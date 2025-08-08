/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:19:09 by yenyilma          #+#    #+#             */
/*   Updated: 2025/08/08 17:51:02 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_overflow(long digit, long result, long sign)
{
	if (sign == -1 && result > (2147483648 - digit) / 10)
		exit(1);
	else if (sign == 1 && result > (2147483647 - digit) / 10)
		exit(1);
}

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	long	digit;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		exit(1);
	while (*str >= 48 && *str <= 57)
	{
		digit = *str - 48;
		check_overflow(digit, result, sign);
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}
