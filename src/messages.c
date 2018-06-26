/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:05:43 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 06:05:46 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_error_message(char *message)
{
	perror(message);
	exit(1);
}

void	display_message(char *message)
{
	ft_putstr(message);
	exit(0);
}
