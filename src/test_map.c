/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 16:01:11 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <fcntl.h>  // Pour open
#include <unistd.h> // Pour read, close

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
    // if (argc != 2)
    // {
    //     printf("Usage: %s <fichier_map.fdf>\n", argv[0]);
    //     return 1;
    // }
    (void)argc;
    int width = ft_atoi(argv[1]);  // Largeur de la map
    int height = ft_atoi(argv[2]); // Hauteur de la map

    // Créer et remplir la map
    t_points **map = create_and_fill_map(width, height);

    // Afficher la map
    print_map(map, width, height);

    // Libérer la mémoire
    free_map(map, height);

    return 0;
}
