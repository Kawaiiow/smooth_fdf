/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:00:38 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/19 03:20:40 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split_clear(char **split_str)
{
	int	i;

	i = 0;
	if (!split_str)
		return (NULL);
	while (split_str[i])
		free(split_str[i++]);
	free(split_str);
	return (NULL);
}

static int	ft_wordcount(char *str, char sep)
{
	char	*s;
	int		n;

	s = str;
	n = 0;
	while (*s)
	{
		while (*s != '\0' && *s == sep)
			s++;
		if (*s)
		{
			s++;
			n++;
		}
		while (*s != '\0' && *s != sep)
			s++;
	}
	return (n);
}

static int	ft_wordlen(char *str, char sep)
{
	int	len;

	len = 0;
	if (!str)
		return (-1);
	while (str[len] != '\0' && str[len] != sep)
		len++;
	return (len);
}

static char	*ft_cutword(char *str, char sep)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_wordlen(str, sep);
	if (len < 0)
		return (NULL);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != sep)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**res;

	if (!str)
		return (NULL);
	i = ft_wordcount((char *)str, c);
	if (!i)
		return (NULL);
	res = (char **)malloc((i + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			res[i++] = ft_cutword((char *)str, c);
		if (res[i - 1] == NULL)
			return (split_clear(res));
		while (*str && *str != c)
			str++;
	}
	res[i] = 0;
	return (res);
}
