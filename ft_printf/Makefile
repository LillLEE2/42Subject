# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 16:56:00 by junholee          #+#    #+#              #
#    Updated: 2021/08/12 17:35:38 by junholee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ftprintf.a

SOURCE= ft_printf.c ft_sub.c ft_sub2.c ft_sub3.c

HEADER= ft_printf.h

OUT=$(SOURCE:.c=.o)

CC= gcc

FLAGE= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OUT)
	@ar rcs  $(NAME) $(OUT)

$(OUT): $(SOURCE) $(HEADER)
	@$(CC) $(FLAGE) -c $(SOURCE)

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
