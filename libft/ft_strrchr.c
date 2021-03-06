/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:23:05 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:11:03 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	carac;
	int		i;

	i = 0;
	ptr = 0;
	carac = (char)c;
	while (str[i])
	{
		if (str[i] == carac)
			ptr = (char *)&str[i];
		i++;
	}
	if (carac == 0)
		return ((char *)&str[i]);
	else if (ptr != 0)
		return (ptr);
	else
		return (0);
}
