/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:34:44 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/14 21:36:38 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dst;
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (s == NULL)
		return(NULL);
	str = (char *)s;
	while (str[len] != '\0')
		len++;
	(dst = (char *)malloc(sizeof(char) * (len + 1)));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}/*
char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*rp;

	size = ft_strlen(s) + 1;
	if ((rp = malloc(size)) == NULL)
		return (NULL);
	while (size-- != 0)
		rp[size] = s[size];
	return (rp);
}*/