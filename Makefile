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
			parser/lst_size.c \
			parser/parser.c \
			parser/special_symbol.c \
			parser/arrows_space.c \
			parser/glue_env_to_arg.c \
			parser/back_slash.c \
			parser/set_to_exec.c

SOURCES=	sources/handle_input.c \
			sources/errors.c \
			sources/history.c \
			sources/utils1.c \
			sources/handle_ctrl_c.c \
			sources/puterror.c \
			sources/syntax_error_checker.c

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