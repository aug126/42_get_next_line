/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:33:56 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:22:25 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** calcule la longueur de la string s
*/

size_t ft_strlen(const char *s)
{
	int len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}
