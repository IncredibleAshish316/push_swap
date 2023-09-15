/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:38 by anepali           #+#    #+#             */
/*   Updated: 2023/03/06 13:54:06 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0 || dst == src)
		return (len);
	while (*src != '\0' && i < n - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst++ = '\0';
	return (len);
}

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	int		delimiter;

	i = 0;
	delimiter = 0;
	while (*str)
	{
		if (*str != c && delimiter == 0)
		{
			delimiter = 1;
			i++;
		}
		else if (*str == c)
			delimiter = 0;
		str++;
	}
	return (i);
}

static void	process(char const *s, char **p, size_t len_words, char c)
{
	size_t	j;
	size_t	i;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (p && j < len_words)
	{
		while (s[i] != c && s[i] != '\0')
		{
			count++;
			i++;
		}
		if (count > 0)
		{
			p[j] = (char *)malloc(sizeof(char) * count + 1);
			ft_strlcpy(p[j], &s[i - count], count + 1);
			count = 0;
			j++;
		}
		i++;
	}
	p[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	len_words;
	size_t	i;
	size_t	j;
	char	**p;

	i = 0;
	j = 0;
	len_words = count_words(s, c);
	p = (char **)malloc((len_words + 1) * sizeof(char **));
	if (!p)
		return (0);
	else
	{
		process(s, p, len_words, c);
		return (p);
	}
}
