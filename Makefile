# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:02:42 by sezequie          #+#    #+#              #
#    Updated: 2023/10/08 23:30:25 by sezequie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha\
		ft_isascii ft_isdigit ft_isprint ft_memchr ft_memcmp\
		ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup\
		ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr\
		ft_strrchr ft_tolower ft_toupper ft_substr ft_strjoin\
		ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri\
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\

CC =cc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)