/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/04 11:59:02 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <fcntl.h>  // Pour open
#include <unistd.h> // Pour read, close
#define BUFFER_SIZE 1

ssize_t ft_getline(char **line, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    char *tmp;
    int ret, len = 0;

    if (!line || fd < 0)
        return -1;

    *line = malloc(1);
    if (!*line)
        return -1;
    (*line)[0] = '\0';

    while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[ret] = '\0'; // Ajouter le null-terminateur

        // Étendre `line` dynamiquement pour ajouter `buffer`
        tmp = malloc(len + ret + 1);
        if (!tmp)
            return -1;

        for (int i = 0; i < len; i++)
            tmp[i] = (*line)[i];
        for (int i = 0; i < ret; i++)
            tmp[len + i] = buffer[i];

        tmp[len + ret] = '\0';
        free(*line);
        *line = tmp;
        len += ret;

        // Arrêter si on atteint un saut de ligne
        if ((*line)[len - 1] == '\n')
            break;
    }

    return (ret == 0 && len == 0) ? -1 : len;
}

// Fonction pour compter les colonnes d'une ligne
int count_columns(char *line)
{
    int count = 0;
    while (*line)
    {
        while (*line == ' ') line++; // Ignorer les espaces
        if (*line) count++;
        while (*line && *line != ' ') line++; // Aller au prochain espace
    }
    return count;
}

// Fonction pour lire le fichier et stocker chaque ligne dans un tableau de chaînes
char **read_map_file(const char *filename, int *width, int *height)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur ouverture fichier");
        return NULL;
    }

    char *line = NULL;
    char **lines = NULL;
    size_t size = 0;
    ssize_t len;
    *height = 0;

    // Lire le fichier ligne par ligne
    while ((len = getline(&line, &size, fdopen(fd, "r"))) != -1)
    {
        if (*height == 0) *width = count_columns(line); // Déterminer la largeur
        lines = realloc(lines, (*height + 1) * sizeof(char *));
        lines[*height] = strdup(line);
        (*height)++;
    }

    free(line);
    close(fd);
    return lines;
}

// Fonction principale
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <fichier_map.fdf>\n", argv[0]);
        return 1;
    }

    int width, height;
    char **lines = read_map_file(argv[1], &width, &height);
    if (!lines)
        return 1;

    t_points **map = allocate_map(width, height);
    fill_map(map, lines, width, height);
    print_map(map, width, height);
    
    // Libération de la mémoire
    free_map(map, height);
    for (int i = 0; i < height; i++)
        free(lines[i]);
    free(lines);
    return 0;
}
