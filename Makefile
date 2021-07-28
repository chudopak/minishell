NAME=		minishell
LIBFT=		libft/libft.a
FLAGS=		-Wall -Wextra -Werror -g

HEADERS=	headers/overall.h \
			headers/parser.h

PARSER=		parser/auxiliary_parser.c \
			parser/dollar.c \
			parser/environment_to_struct.c \
			parser/parser.c \
			parser/special_symbol.c \
			parser/arrows_space.c \
			parser/glue_env_to_arg.c \
			parser/back_slash.c \
			parser/set_to_exec.c \
			parser/set_to_exec1.c \
			parser/set_fd_for_redirect.c \
			parser/set_to_exec_path.c \
			parser/parser2.c

UTILS=		utils/env_utils.c \
			utils/split_paths.c

BUILT_IN=	built_in/ft_cd.c \
			built_in/ft_echo.c \
			built_in/ft_env.c \
			built_in/ft_exit.c \
			built_in/ft_export.c \
			built_in/ft_pwd.c \
			built_in/ft_unset.c

ENV_FUNC=	built_in/ft_env_func/env_utils1.c \
			built_in/ft_env_func/env_utils2.c \
			built_in/ft_env_func/env_utils3.c \
			built_in/ft_env_func/env_utils4.c \
			built_in/ft_env_func/env_utils5.c \

SOURCES=	sources/handle_input.c \
			sources/copy_envp.c \
			sources/set_path.c \
			sources/errors.c \
			sources/history.c \
			sources/utils1.c \
			sources/handle_ctrl_c.c \
			sources/puterror.c \
			sources/syntax_error_checker.c \
			sources/set_history.c \
			sources/lst_interact_functions.c \
			sources/exec.c \
			sources/pipes_utils.c \
			sources/redirect_utils.c \
			sources/env_to_charpp.c \
			sources/signal_handler.c

GNL=		gnl/get_next_line.c \
			gnl/get_next_line_utils.c

SRC=		$(PARSER) ${SOURCES} ${GNL} ${UTILS} ${ENV_FUNC} ${BUILT_IN}  minishell.c

OBJ=		$(PARSER:.c=.o) $(SOURCES:.c=.o) $(GNL:.c=.o) $(UTILS:.c=.o) $(ENV_FUNC:.c=.o) $(BUILT_IN:.c=.o) minishell.o

%.o: %.c 
	gcc $(FLAGS) $< -c -o $(<:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(LIBFT) $(OBJ)
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