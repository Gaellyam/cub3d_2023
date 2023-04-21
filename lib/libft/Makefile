# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamy <glamy@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:31:42 by glamy             #+#    #+#              #
#    Updated: 2020/11/23 14:23:53 by glamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc

CCFLAGS = -Wall -Wextra -Werror

NAME 	= libft.a

SRCS 	= 	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c 	ft_isdigit.c 	ft_isprint.c	ft_itoa.c 		ft_memccpy.c\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c\
			ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c\
			ft_strchr.c		ft_strdup.c		ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c\
			ft_strlen.c		ft_strmapi.c	ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
			ft_strtrim.c	ft_substr.c 	ft_tolower.c	ft_toupper.c	ft_strcpy.c\
			ft_strcat.c		ft_strncpy.c	ft_strcmp.c		ft_putchar.c	ft_putstr.c\
			ft_itoa_base.c	ft_utoa_base.c	ft_putnbr.c		ft_isupper.c	ft_isspace.c \
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJS 	= $(SRCS:.c=.o)

$(NAME): $(OBJS) libft.h
		ar rc $(NAME) $(OBJS) libft.h 

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< 

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

reb: fclean

.PHONY : re clean fclean