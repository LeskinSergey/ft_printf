/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:55:15 by sbombadi          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:17 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	length_str_u( unsigned int n)
{
	unsigned long	nbr;
	int				len;
	int				f;

	nbr = n;
	len = 0;
	f = 0;
	if (n < 0)
	{
		nbr = nbr * -1;
		f = -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	if (n == 0)
		return (1);
	return (len - f);
}

static char	*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = length_str_u(n);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 0 && i >= 0)
	{
		str[len - i - 1] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_print_u( unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_u(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
