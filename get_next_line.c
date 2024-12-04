/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:25:24 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/25 18:10:07 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE

# define	BUFFER_SIZE 42

#endif

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return NULL;
	if (s1)
		ft_strcpy(joined, s1);
	if (s2)
		ft_strcpy(joined + len1, s2);
	free(s1);
	return joined;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	temp[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		temp[bytes_read] = '\0';
		buffer = join_and_free(buffer, temp);
	}
	if (buffer)
		return extract_line(&buffer);
	else
		return NULL;
}

// int main(void) {
//     int fd;
//     char *line;

//     // Ouvrir le fichier text.txt en mode lecture seule
//     fd = open("text.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }

//     // Lire et afficher chaque ligne du fichier
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line); // N'oubliez pas de libérer la mémoire allouée par get_next_line
//     }

//     // Fermer le fichier
//     close(fd);

//     return 0;
// }