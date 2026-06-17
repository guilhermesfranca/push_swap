*This project has been created as part of the 42 curriculum by guicarva, gfranca.*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, in as few moves as possible, using two stacks — `a` and `b`.

The challenge is not just to sort, but to do so **efficiently**: the grading is based on the number of operations used to sort a given set of integers. This pushes us to study, implement, and compare different algorithmic strategies.

The program reads a list of integers from the command line, and writes to standard output the sequence of operations needed to sort stack `a` in ascending order.

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of `b` onto `a` |
| `pb` | Push the top of `a` onto `b` |
| `ra` | Rotate `a` upward (first element becomes last) |
| `rb` | Rotate `b` upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate `a` (last element becomes first) |
| `rrb` | Reverse rotate `b` |
| `rrr` | `rra` and `rrb` at the same time |

---

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` executable.

```bash
make clean    # remove object files
make fclean   # remove object files and executable
make re       # fclean + all
```

### Execution

```bash
./push_swap [integers...]
```

Integers can be passed as separate arguments or as a quoted string:

```bash
./push_swap 3 1 4 1 5       # Error: duplicate
./push_swap 3 1 4 2 5
./push_swap "3 1 4 2 5"
```

### Optional Flags

| Flag | Description |
|------|-------------|
| `--bench` | Print operation statistics after sorting |
| `--simple` | Force the O(n²) radix-based sort |
| `--medium` | Force the O(n√n) chunk sort (k-sort) |
| `--complex` | Force the O(n log n) Turkish sort |
| `--adaptive` | Let the program choose based on disorder level |

```bash
./push_swap --bench 5 3 1 4 2
./push_swap --complex $(seq 1 100 | shuf | tr '\n' ' ')
```

### Checking correctness

You can pipe the output into a checker to verify the result:

```bash
ARG="5 3 1 4 2"
./push_swap $ARG | wc -l           # count operations
./push_swap $ARG | ./checker $ARG  # verify sort (if checker available)
```

---

## Algorithms

This project implements **three main sorting strategies**, selected adaptively based on the disorder level of the input. Below is a detailed explanation and justification of each.

---

### 1. Simple Sort — O(n²) — for ≤ 5 elements or `--simple`

**How it works:**

- For **2 elements**: one `sa` if needed.
- For **3 elements** (`simple_3low`): every possible ordering of 3 values is handled with a hardcoded sequence of at most 2 operations, checking the top, middle, and bottom values and applying the minimum moves.
- For **4–5 elements** (`sort_simple`): elements are extracted one by one to stack `b` in sorted order (smallest first), then pushed back to `a`. Each extraction uses `bring_to_top` to rotate the target index to the top before pushing.

**Why:**
Small inputs have very few possible states, making brute-force/hardcoded solutions optimal. These cases must be handled perfectly to meet grading thresholds.

---

### 2. Radix Sort — O(n log n) bits — `--simple` flag or low disorder

**How it works:**

Integers are first **rank-indexed** (assigned a position from 0 to n−1), which makes them work with bitwise operations. The sort then processes the binary representation of each index, bit by bit from least significant to most significant:

- If the current bit is `0` → push to `b`
- If the current bit is `1` → rotate `a`

After each pass, everything in `b` is pushed back to `a`. A symmetry optimization skips bit positions where all values share the same bit (using `aaaa()`), and a mirror pass handles the next bit simultaneously.

**Why:**
Radix sort works well when the input is nearly sorted (low disorder). Its operation count scales with the number of bits in the index, making it predictable and reliable for very sorted or weakly shuffled inputs.

---

### 3. K-Sort (Chunk Sort) — O(n√n) — `--medium` flag or mid disorder

**How it works:**

Inspired by chunk-based sorting:

1. **Push to B in chunks**: the stack is divided into chunks of size `~1.5 * √n`. Elements are scanned linearly; if an element's index falls in the current chunk, it's pushed to `b` (and rotated to the back of `b` if it's in the next chunk slot). Otherwise, `ra` is used to scan forward.
2. **Push back to A in order**: elements are retrieved from `b` largest-first, using `rb`/`rrb` to bring each target to the top, then `pa`.

**Why:**
K-sort balances push operations and rotations, achieving sub-quadratic performance without the complexity of a full greedy cost search. It performs well on mid-disorder inputs where Turkish sort's overhead is not yet worth it.

---

### 4. Turkish Sort (Greedy Insertion) — O(n log n) — `--complex` flag or high disorder

**How it works:**

Based on the "Turk algorithm" — a greedy, cost-minimizing insertion sort between two stacks:

1. Push the first two elements to `b`.
2. For every remaining element in `a`, compute the **cheapest move**: the pair (position in `a`, target position in `b`) that requires the fewest total rotations. Target position in `b` is the slot where the element fits in descending order.
3. Execute the cheapest move using simultaneous rotations (`rr`/`rrr`) when both stacks rotate in the same direction, then individual rotations, then `pb`.
4. After `a` is reduced to 3 elements, apply `simple_3low`.
5. Push everything back from `b` to `a` in order, using `get_target_a_pos` to find the correct insertion point each time.
6. Finally, rotate `a` so the minimum is at the top.

**Cost function** (`total_cost`):
- If both positions are in the upper half of their stacks → cost = `max(cost_a, cost_b)` (simultaneous `rr`)
- If both are in the lower half → cost = `max(cost_a, cost_b)` (simultaneous `rrr`)
- Otherwise → cost = `cost_a + cost_b` (individual rotations)

**Why:**
Turkish sort finds the globally cheapest move at each step, minimizing total operations. It performs best on highly disordered inputs where the cost savings from simultaneous rotations are significant. It achieves roughly 700 operations for 100 numbers and under 7000 for 500 numbers in most cases.

---

### Adaptive Strategy

The program computes a **disorder metric** at startup using pairwise inversion counting:

```
disorder = inversions / total_pairs
```

Based on the result:

| Disorder | Strategy chosen |
|----------|-----------------|
| ≤ 20% | Radix Sort |
| 20–50% | K-Sort |
| > 50% | Turkish Sort |

This avoids the overhead of Turkish sort on nearly-sorted inputs, and the poor performance of radix sort on highly shuffled data.

---

## Resources

### Sorting Algorithms & Theory

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Wikipedia — Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Visualgo — Sorting visualizations](https://visualgo.net/en/sorting)
- [42 push_swap — The Turk Algorithm (Medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Chunk sort / K-sort explanation (Stack Overflow discussions)](https://stackoverflow.com)

### 42 Project References

- [push_swap subject (42 official)](https://cdn.intra.42.fr/pdf/pdf/13196/en.push_swap.pdf)
- [push_swap tester — ft_ps_tester](https://pypi.org/project/ft-ps-tester/)

### AI Usage

AI was used for documentation and clarification of some concepts. All decisions were made by the participants together.

---

## Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h          # structs, typedefs, all prototypes
├── srcs/
│   ├── main.c               # entry point, argument parsing, index assignment
│   ├── push_swap.c          # dispatcher: chooses algorithm
│   ├── utils.c              # ft_atoi, ft_strcmp, start_bench
│   ├── free_and_check.c     # memory cleanup, error handling, flags
│   ├── stack_utils.c        # circular linked list utilities
│   ├── sort_simple.c        # simple_3low, sort_simple, bring_to_top
│   ├── sort_radix.c         # radix_sort
│   ├── sort_k.c             # k_sort, push_to_b, push_to_a
│   ├── sort_turk.c          # turk_sort, find, exe_move
│   ├── sort_turk_utils_1.c  # target position finders
│   ├── sort_turk_utils_2.c  # cost functions, rotate helpers
│   ├── max_min_sort.c       # extraction-based sort variant
│   ├── o_push.c             # pa, pb operations
│   ├── o_rotate.c           # ra, rb, rr
│   ├── o_rotate_r.c         # rra, rrb, rrr
│   ├── o_swap.c             # sa, sb, ss
│   ├── ft_printf.c          # custom printf
│   ├── ft_printf_utils.c    # printf helpers
│   ├── ft_split.c           # string split
│   ├── get_next_line.c      # GNL
│   └── get_next_line_utils.c
├── Makefile
└── README.md
```