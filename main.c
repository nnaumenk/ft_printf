/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:46:56 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:46:57 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "locale.h"
//////gtoa printf("11.0 = %.4g\n", 5664.5);
	////ft_printf("11.0 = %.0g\n", 0.234);
////ft_printf("11.0 = %.50g\n", 123432423.234123);
int main(void)
{
	int count;
	//double m = -1.7976931348623157e+305;

	// setlocale(LC_ALL, "");
	printf("printf = {%C}\n", L'123');
	ft_printf("ftprintf = {%C}\n", L'123');

//	ft_printf("  str2 = %.0g\n", 0.49999);

	
// 	printf("11.0 = %g\n", 123.12);
// ft_printf("11.0 = %g\n", 123.12);

// 	printf("11.0 = %g\n", 0.012);
// ft_printf("11.0 = %g\n", 0.012);


	
	

	// system("leaks libftprintf.a");

	



	return (0);
}
