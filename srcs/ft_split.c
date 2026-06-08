/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:24:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 15:05:55 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free_matrixx(char **matrixx, int i)
{
	while (i > 0)
	{
		i--;
		free(matrixx[i]);
	}
	free(matrixx);
}

static char	*ft_next_word(const char **s, char c)
{
	const char	*start;
	size_t		len;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	*s = *s + len;
	return (ft_substr(start, 0, len));
}

char	**ft_split(char const *s, char c)
{
	char	**matrixx;
	size_t	word;
	size_t	i;

	if (!s)
		return (NULL);
	word = ft_count_words(s, c);
	matrixx = malloc(sizeof(char *) * (word + 1));
	if (!matrixx)
		return (NULL);
	i = 0;
	while (i < word)
	{
		matrixx[i] = ft_next_word(&s, c);
		if (!matrixx[i])
			return (ft_free_matrixx(matrixx, i), NULL);
		i++;
	}
	matrixx[i] = NULL;
	return (matrixx);
}
