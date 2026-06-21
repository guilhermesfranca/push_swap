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
| `--simple` | Force Turkish sort with standard cost function |
| `--medium` | Force the O(n√n) chunk sort (k-sort) |
| `--complex` | Force Turkish sort with optimized cost function |
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

### 1. Simple Sort — for ≤ 5 elements

**How it works:**

- For **2 elements**: one `sa` if needed.
- For **3 elements** (`simple_3low`): every possible ordering of 3 values is handled with a hardcoded sequence of at most 2 operations, checking the top, middle, and bottom values and applying the minimum moves.
- For **4–5 elements** (`sort_simple`): elements are extracted one by one to stack `b` in sorted order (smallest first), then pushed back to `a`. Each extraction uses `bring_to_top` to rotate the target index to the top before pushing.

**Why:**
Small inputs have very few possible states, making brute-force/hardcoded solutions optimal. These cases must be handled perfectly to meet grading thresholds.

---

### 2. K-Sort (Chunk Sort) — O(n√n) — `--medium` flag or mid disorder

**How it works:**

Inspired by chunk-based sorting:

1. **Push to B in chunks**: the stack is divided into chunks of size `~1.5 * √n`. Elements are scanned linearly; if an element's index falls in the current chunk, it's pushed to `b` (and rotated to the back of `b` if it's in the next chunk slot). Otherwise, `ra` is used to scan forward.
2. **Push back to A in order**: elements are retrieved from `b` largest-first, using `rb`/`rrb` to bring each target to the top, then `pa`.

**Why:**
K-sort balances push operations and rotations, achieving sub-quadratic performance without the complexity of a full greedy cost search. It performs well on mid-disorder inputs where Turkish sort's overhead is not yet worth it.

---

### 3. Turkish Sort (Greedy Insertion) — O(n log n) — `--simple` and `--complex` flags

**How it works:**

Based on the "Turk algorithm" — a greedy, cost-minimizing insertion sort between two stacks:

1. Push the first element to `b`.
2. For every remaining element in `a`, compute the **cheapest move**: the pair (position in `a`, target position in `b`) that requires the fewest total rotations. Target position in `b` is the slot where the element fits in descending order.
3. Execute the cheapest move using simultaneous rotations (`rr`/`rrr`) when both stacks rotate in the same direction, then individual rotations, then `pb`.
4. After `a` is reduced to 3 elements, apply `simple_3low`.
5. Push everything back from `b` to `a` in order, using `get_target_a_pos` to find the correct insertion point each time.
6. Finally, rotate `a` so the minimum is at the top.

The algorithm has **two cost variants**, selected by the `name` parameter in `turk_sort`:

**`--simple` → `find_cheapest` (standard cost)**
- If both positions are in the upper half → cost = `max(cost_a, cost_b)` (simultaneous `rr`)
- If both are in the lower half → cost = `max(cost_a, cost_b)` (simultaneous `rrr`)
- Otherwise → cost = `cost_a + cost_b` (individual rotations)

**`--complex` → `find_best_cheapest` (optimized cost)**
- Considers all four rotation strategies (pure `rr`, pure `rrr`, mixed A-then-B, mixed B-then-A) and picks the minimum across all of them, without assuming which half each position falls in. This avoids the half-rounding approximation and finds the true minimum.

**Why two variants:**
The standard cost function is fast and performs well on moderately disordered inputs. The optimized variant adds a more exhaustive cost search that benefits heavily disordered inputs where the rounding in the standard function would miss cheaper moves. Both avoid the overhead of radix sort's bitwise passes entirely.

**Why:**
Turkish sort finds the cheapest move at each step, minimizing total operations through greedy insertion. It is the core algorithm for both `--simple` and `--complex` modes, and is used by the adaptive strategy for both low and high disorder cases.

---

### Adaptive Strategy

The program computes a **disorder metric** at startup using pairwise inversion counting:

```
disorder = inversions / total_pairs
```

Based on the result:

| Disorder | Strategy chosen |
|----------|-----------------|
| < 20% | Turkish Sort (standard cost) |
| 20–50% | K-Sort |
| ≥ 50% | Turkish Sort (optimized cost) |

At low disorder, the standard Turkish sort is fast enough and avoids the overhead of chunk management. At high disorder, the optimized cost variant extracts more savings from simultaneous rotations. K-sort fills the middle ground efficiently.

---

## Resources

### Sorting Algorithms & Theory

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
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
│   ├── sort_turk.c          # turk_sort, find_cheapest, find_best_cheapest
│   ├── sort_turk_utils_1.c  # target position finders
│   ├── sort_turk_utils_2.c  # rotate helpers, execute_move
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