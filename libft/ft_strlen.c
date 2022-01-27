/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:33:32 by oshelba           #+#    #+#             */
/*   Updated: 2021/10/26 01:16:33 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}*/
size_t	ft_strlen(const char *s)
{
	const char	*wp;

	if (s == NULL)
		return(0);
	wp = s;
	while (*wp != '\0')
		wp++;
	return (wp - s);
}