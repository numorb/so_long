# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 14:30:42 by blnunez-          #+#    #+#              #
#    Updated: 2024/12/09 20:23:33 by blnunez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	so_long

SRCDIR:= src
INCDIR:= include
OBJDIR:= bin

SRC:=	so_long.c \
		key_mapping.c \
		map_mapping.c
OBJS:=$(SRC:%.c=$(OBJDIR)/%.o)

LIBFT:= libs/libft/libft.a
CC:=	cc
CFLAGS:= -Wall -Wextra -Werror
debug: CFLAGS += -ggdb3

ifeq ($(UNAME), Darwin)
	LIBMLX:= libs/minilibx_mms/libmlx.a
	CPPFLAGS:= -I ./libs/minilibx_mms -I ./libs/libft -I ./$(INCDIR)
	LDFLAGS:= -L ./libs/minilibx_mms -L ./libs/libft -L ./$(INCDIR)
else
	LIBMLX:= libs/minilibx-linux/libmlx.a
	CPPFLAGS:= -I ./libs/minilibx-linux -I ./libs/libft -I ./$(INCDIR)
	LDFLAGS:= -L ./libs/minilibx-linux -L ./libs/libft -L ./$(INCDIR)
endif
LDLIBS:= -lmlx -lft -lX11 -lXext -lm

.PHONY: all clean fclean re debug

all: $(NAME)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
debug: re
$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR) 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJDIR):
	@mkdir -p $@

$(LIBFT):
	$(MAKE) -C libft

$(LIBMLX):
	@if[($(UNAME), Darwin)]; then \
		$(MAKE) -C libs/minilibx_mms; \
	else \
		$(MAKE) -C libs/minilibx-linux; \
	fi

