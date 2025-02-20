/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:48 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:24 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int add_shade(double distance, int color);
int get_oposite(int color);
unsigned int blend_color(unsigned int bg, unsigned int fg, float alpha);