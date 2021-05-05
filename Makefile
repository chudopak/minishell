NAME		= minishell
LIBFT		= libft/libft.a
FLAGS		= -Wall -Wextra -Werror -g

HEADERS=	headers/overall.h \
			headers/parser.h

PARSER=		parser/auxiliary_parser.c \
			parser/dollar.c \
			parser/environment_to_struct.c \
			parser/lst_add_back.c \
			parser/lstclear_char.c \
			parser/lstnew.c \
			parser/parser.c \
			parser/special_symbol.c \
			parser/back_slash.c \
			parser/arrows_space.c

SOURCES=	sources/handle_input.c \
			sources/errors.c \
			sources/history.c

SRC=		$(PARSER) ${SOURCES} minishell.c

OBJ			= $(PARSER:.c=.o) $(SOURCES:.c=.o) minishell.o

%.o: %.c 
	gcc $(FLAGS) $< -c -o $(<:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -ltermcap

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)
	rm -f **/a.out
	rm -f a.out
	rm -rf minishell.dSYM

re: fclean all