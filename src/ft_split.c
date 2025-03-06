/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:05 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:53 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **result, int words)
{
	while (words >= 0)
		free(result[words--]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	char	*start;

	result = ft_calloc((words = count_words(s, c)) + 1, sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i++])
				return (free_split(result, i - 1), NULL);
		}
		else
			s++;
	}
	return (result);
}
// int	main(void)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("Hello World! I am a student", ' ');
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (result[i])
// 		free(result[i++]);
// 	free(result);
// 	return (0);
// }
