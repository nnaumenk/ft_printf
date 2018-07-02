/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:23:55 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/11 19:43:30 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//ubrat
# include <math.h>//ubrat
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFF_SIZE 4096

typedef 		struct
{
			char			str_full[BUFF_SIZE];
			char			*s;
			va_list			ptr;
			va_list			argptr_offset;
			int				argptr_counter;
			int				len;
	/* 00 */int				len_full;
	/* 01 */char			flag_minus;
	/* 02 */char			flag_plus;
	/* 03 */char			flag_space;
	/* 04 */char			flag_hash;
	/* 05 */char			flag_zero;
			char			flag_comma;
			char			flag_dolar;
			char			flag_asterisk;
			char			flag_float;
	/* 06 */int				width_field;
	/* 07 */int				precision_field;
	/* 08 */int				len_field;
	/* 09 */char			type_field;
			int				buf;
			int				dot;
			int				i;
			int				unicode_check;
	
	/* 10 */
	/* 11 */
	/* 12 */
	/* 13 */
	/* 14 */
}				t_list;

void			ft_set_counter(t_list *my);
char			*ft_date_iso(t_list *my);
char			*ft_notprintable_str(char *str, int len, int i, int j);
char			*ft_notprintable(char *str, t_list *my);

int				ft_color_check(char *color);
void			ft_color(t_list *my, char *color, int i);
int				ft_str_color(char *new, char *str, char *color, int i);
void			ft_add_color(t_list *my, int i, int color_len);
void			ft_color_search(t_list *my);


char			*ft_str_join_free(char *s1, char *s2, int len1, int len2);
char			*ft_str_join_char_free(char *s1, int len, char c);
void			ft_my_strcat(t_list *my, char *s1, int len);
int				ft_str_join_free_check(char *s1, char *s2, int fl1, int fl2);
char			*ft_str_join_free_spec(char *s1, char *s2, int *spec);
char			*ft_str_join_free_flag(char *s1, char *s2, int fl1, int fl2);
void			ft_expand(char **form, t_list *my);

long			ft_mod_int(t_list *my);
unsigned long	ft_mod_unint(t_list *my);
//unsigned long	ft_mod_unint(va_list argptr, int c);
long double		ft_mod_float(t_list *my);

void			ft_strdel(char **as);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_my_strdup_precision(const char *s, t_list *my);
char			*ft_my_strdup(const char *s, t_list *my);
char			*ft_chardup(const char c);

char 			*ft_strchardup(int len, char c);
int				ft_strcount(char *str, int *spec);
char 			*ft_my_strnew(int size);
char			*ft_set_precision_long_min(t_list *my);


char			*ft_float_check(char *str, t_list *my);
int				ft_float_minus(long double *n);
int				ft_float_max_check(long double n);
char			*ft_float_max_str(long double n, t_list *my);
char 			*ft_ftoa_precision(char *str, t_list *my);
char			*ft_ftoa_precision2(char *new, char *str, t_list *my, int af);
char			*ft_float_add_minus(char *str, t_list *my);
char			*ft_round_float_2(char *str, t_list *my);
char			*ft_round_float(char *str, t_list *my, char max_base);



char			*ft_float_a_prefix(char *str, t_list *my, int symbol, int sign);
char			*ft_atoa_to_hex_str(char *str, t_list *my, int symbol, int sign);
int				ft_atoa_to_hex_counter(long double num, int pr);
char			*ft_atoa_to_hex(long double num, t_list *my);
int				ft_atoa_pow(long double *n, long double m);
char			*ft_atoa(long double n, t_list *my);





char			*ft_gtoa_precision(char *str, t_list *my);
char			*ft_gtoa(double n, t_list *my);

char 			*ft_float_binary(unsigned long *ptr);
int				ft_exponent(char *str);
unsigned long	ft_mantisa(char *str, int *exponent);
int				ft_float_dot(t_list *my);
char			*ft_float_infinite_numbers(char *str, t_list *my);
char			*ft_float(char *str_ptr, t_list *my);
char			*ft_float_add_exponent(char *str, t_list *my, int count, char type);
char			*ft_ftoa(double n, t_list *my);



char			*ft_etoa_precision_minus(char *str, t_list *my,
				int first_num_ind);
char 			*ft_etoa_precision_plus(char *str, t_list *my, int dot_index);
char			*ft_etoa_add_exponent(char *str, t_list *my, int counter);
char			*ft_etoa_help(char *str, t_list *my);
char			*ft_etoa(double n, t_list *my);


char			*ft_set_precision_str(char *str, int *spec);
char			*ft_set_precision(char *str, t_list *my);
char			*ft_set_precision2(char *str, int *spec, int count);

char			*ft_flag_plus(char *str, t_list *my);
char			*ft_flag_hash_o(char *str, t_list *my);
char			*ft_flag_hash_x(char *str, t_list *my);
char			*ft_flag_space(char *str, t_list *my);
char 			*ft_flag_comma(char *str, t_list *my);



char			*ft_wchardup2(const wchar_t c, t_list *my);
char			*ft_wchardup(const wchar_t c, t_list *my);
char			*ft_set_precision_wstr(wchar_t *str, int len, t_list *my);
char			*ft_wstrdup_wstr(wchar_t *str, int len, t_list *my);
char			*ft_wstrdup(wchar_t *str, t_list *my);

int				ft_minus(int *pow);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_numcount_base_sign(long n, int base);
int				ft_numcount_base_unsign(unsigned long n, int base);
int				ft_char_index(char *str, char c);
int				ft_nochar_index(char *str, char c1, char c2);

void			ft_reset_flags(t_list *my);

int				ft_str_chr_all(const char *str, char c);
char			*ft_strchr(const char *s, int c);
int				ft_lenchr(const char *s, int *start, char c);
int				ft_len_chr_str(const char *s, int start, char *sub);
char			*ft_join_char(char *str, int len, char c);

char			*ft_set_precision(char *str, t_list *my);

char			*ft_width_zero(char *str, t_list *my);
char			*ft_width_space(char *str, t_list *my);
char			*ft_width_minus_space(char *str, t_list *my);
char			*ft_field_width_main(char *str, t_list *my);

void			ft_search_s4(char **form, t_list *my);
void			ft_search_s3(char **form, t_list *my);
void			ft_search_s2(char **form, t_list *my);
void			ft_search_s1(char **form, t_list *my);
void			ft_specificator(char **form, t_list *my);

char 			*ft_strdup(char *str);///ubrat
char			*ft_itoa_base_u(char const *str_base, int *len,
				unsigned long n, int base);
char			*ft_itoa_base_int(char const *str_base, t_list *my,
				long n, int base);
char			*ft_itoa_base_unint(char const *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_base_unint_o(char const *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_base_unint_x(char const *str_base, t_list *my,
				unsigned long n, int base);
char			*ft_itoa_pointer(char const *str_base, t_list *my,
				unsigned long n, int base);
long			ft_atoi(char **str);

char			*ft_cut(char *str, int *len);
char 			*ft_str_mul_two(char *s1, int *len);
int				ft_dot(int *dot, char elem, char *s);
char			*ft_str_div_two(char *s, int *len);


void			ft_va_next(t_list *my);
char			*ft_expr_to_str2(t_list *my);
char			*ft_expr_to_str(t_list *my, char const *b1, char const *b2);
void			ft_expr_out(t_list *my);
int				ft_printf(const char *format, ...);

//int 			main(void);

#endif
