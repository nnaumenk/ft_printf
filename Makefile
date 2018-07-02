# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 14:12:58 by nnaumenk          #+#    #+#              #
#    Updated: 2018/07/02 11:16:45 by nnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CFILES =	ft_printf.c				\
			ft_str_bonus.c			\
			ft_color.c				\
			ft_join.c				\
			ft_str.c				\
			ft_str_2.c				\
			ft_float.c				\
			ft_float_precision.c	\
			ft_atoa.c				\
			ft_etoa.c				\
			ft_gtoa.c				\
			ft_ftoa.c				\
			ft_itoa.c				\
			ft_reset.c				\
			ft_lib_additional.c		\
			ft_lib_additional_2.c	\
			ft_specificator.c		\
			ft_width.c				\
			ft_mod.c				\
			ft_str_flags.c			\
			ft_unicode.c			\
			ft_str_mul_div.c		\
			#main.c					\

OFILES = 	$(CFILES:.c=.o)

HEADER = 	ft_printf.h

FLAGS = 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
		
		#gcc -I $(HEADER) $(FLAGS) -c $(CFILES)
		#gcc -o $(NAME) $(OFILES)
		ar rc $(NAME) $(OFILES)
		
#$(MAKE_OFILES):
#		gcc -I $(HEADER) -c $(CFILES)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
		/bin/rm -f $(NAME)

re:		fclean all
