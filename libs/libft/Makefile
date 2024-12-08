# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 19:20:33 by blnunez-          #+#    #+#              #
#    Updated: 2024/10/28 17:46:57 by blnunez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -I.
SRC		:=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_fprintf.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_puthex.c \
			ft_puthex_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putpointer.c \
			ft_putpointer_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putunsigned.c \
			ft_putunsigned_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_fprintf.c \
			ft_printf.c \
			ft_printf_utils.c \
			get_next_line.c \
			get_next_line_utils.c
			
OBJS		:=	$(SRC:.c=.o)

BONUS		:= 	ft_lstmap.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \

BONUS_OBJS	:= $(BONUS:.c=.o)
H_FILES		:= libft.h

all:		$(NAME)

%.o: %.c $(H_FILES)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			ar -crs $(NAME) $(OBJS)
	
clean:		
			$(RM) -f $(OBJS) $(BONUS_OBJS)
	
fclean:		clean
			$(RM) $(NAME)

re: 		fclean all


bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus
