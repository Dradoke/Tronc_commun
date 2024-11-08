/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:25:15 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/08 19:25:15 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
	{
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && in_word != 1)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*make_word(const char *start, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(len + 1);
	if (!word)
	{
		return (NULL);
	}
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_len_count(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_words(char **words, int j)
{
	while (j > 0)
	{
		free(words[j - 1]);
		j--;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int i, j;
        
	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0, j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j++] = make_word(&s[i], word_len_count(&s[i], c));
			if (!result[j])
			{
				free_words(result, j);
				return (NULL);
			}
			i += word_len_count(&s[i], c);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

int	main(void)
{
	char **test = ft_split("coucou je suis moi", ' ');
	int i = 0;

	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
}