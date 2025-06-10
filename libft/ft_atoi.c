/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:55:58 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/10 13:48:24 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* int	main(void)
{
	const char *str1 = "   -12345abc";
	const char *str2 = "42";
	const char *str3 = "  000987";
	const char *str4 = "-42";
	const char *str5 = "   +2024";

	printf("ft_atoi(\"%s\") = %d\n", str1, ft_atoi(str1)); // -12345
	printf("ft_atoi(\"%s\") = %d\n", str2, ft_atoi(str2)); // 42
	printf("ft_atoi(\"%s\") = %d\n", str3, ft_atoi(str3)); // 987
	printf("ft_atoi(\"%s\") = %d\n", str4, ft_atoi(str4)); // -42
	printf("ft_atoi(\"%s\") = %d\n", str5, ft_atoi(str5)); // 2024

	// to compare with the original atoi function
	printf("\nPruebas con atoi:\n");
	printf("atoi(\"%s\") = %d\n", str1, atoi(str1)); // -12345
	printf("atoi(\"%s\") = %d\n", str2, atoi(str2)); // 42
	printf("atoi(\"%s\") = %d\n", str3, atoi(str3)); // 987
	printf("atoi(\"%s\") = %d\n", str4, atoi(str4)); // -42
	printf("atoi(\"%s\") = %d\n", str5, atoi(str5)); // 2024

	return (0);
} */