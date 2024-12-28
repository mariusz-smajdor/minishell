#include "minishell.h"

int main(int ac, char **av, char **ev)
{
    (void)ac;
    (void)av;
    (void)ev;

    char *line;

    while (true)
    {
        line = readline("minishell$ ");
        if (line == NULL)
            break;
        if (line[0] != '\0')
        {
            add_history(line);
            parse_input(line);
        }
        free(line);
    }
    return (0);
}
