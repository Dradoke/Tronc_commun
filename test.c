/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:44:15 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/18 14:47:02 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>




int     main(void)
{
        int     result = printf("Coucou je suis un test %s", "et voila\n");
        printf("%d: resultat du printf", result);
}