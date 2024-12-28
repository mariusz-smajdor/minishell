#include "minishell.h"

void	exit_error(char *message)
{
    ft_putstr_fd(message, 2);
    exit(1);
}
