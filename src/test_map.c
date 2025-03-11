/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/11 15:40:57 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <unistd.h>


// Fonction principale
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <fichier_map.fdf>\n", argv[0]);
        return 1;
    }
    t_map map;
    map = build_map(argv[1]);
    
    // Libération de la mémoire
    free_map(&map);


    return 0;
}
