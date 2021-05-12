#include "../headers/overall.h"

int	invalid_pipe_semicolom_token(char *data)
{
	if (*data == '|' && *(data + 1) == '|')
		return (puterror("syntax error near unexpected token `||'", 258));
	else if (*data == ';' && *(data + 1) == ';')
		return (puterror("syntax error near unexpected token `;;'", 258));
	else if (*data == '|')
		return (puterror("syntax error near unexpected token `|'", 258));
	else if (*data == ';')
		return (puterror("syntax error near unexpected token `;'", 258));
	return (0);
}

static int	check_after_pipe(char *data)
{
	while (*data == ' ')
		data++;
	if (ft_strchr("\0\n#", *data))
		return (1);
	return (0);
}

static int	check_dbl_semicolom_pipe(char *data)
{
	while (*data && is_separator(*data))
		data++;
	if (*data == '|' || *data == ';')
		return (1);
	return (0);
}

static int	check_redirect_token(char **data)
{
	char	token[2];

	if (**data == '>' && *(*data + 1) == '>')
		*data += 2;
	else
		(*data)++;
	while (**data && is_separator(**data))
		(*data)++;
	if (ft_strchr("\0\n#", **data))
		return (puterror("syntax error near unexpected token `newline'", 258));
	else if (ft_strchr(";|&><", **data))
	{
		if (**data == '>' && *(*data + 1) == '>')
			return (puterror1("syntax error near unexpected token `", ">>", "'", 258));
		token[0] = **data;
		token[1] = '\0';
		return (puterror1("syntax error near unexpected token `", token, "'", 258));
	}
	return (0);
}

int	syntax_error_checker(char *data)
{
	while (is_separator(*data))
		data++;
	if (*data == '|' || *data == ';')
		return (invalid_pipe_semicolom_token(data));
	while (!ft_strchr("\0\n#", *data))
	{
		if (*data == '|' || *data == ';')
		{
			if (*data == '|' && check_after_pipe(data + 1))
				return (puterror("Error: we don't handle that.", 258));
			else if (check_dbl_semicolom_pipe(data + 1))
				return (invalid_pipe_semicolom_token(data));
		}
		else if (*data == '>' || *data == '<')
		{
			if (check_redirect_token(&data))
				return (-1);
		}
		data++;
	}
	return (0);
}