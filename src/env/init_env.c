#include "minishell.h"

static t_env *new_env(char *envp)
{
    t_env   *env;

    env = malloc(sizeof(t_env));
    if (!env)
        exit_error("error: malloc failed\n");
    env->key = ft_strndup(envp, ft_strchr(envp, '=') - envp);
    env->value = ft_strndup(ft_strchr(envp, '=') + 1, ft_strlen(ft_strchr(envp, '=') + 1));
    env->next = NULL;
    return (env);
}

void init_env(t_data *data, char **envp)
{
    t_env   *current;
    short   i;

    i = 0;
    while (envp[i])
    {
        if (!i)
        {
            data->env = new_env(envp[i]);
            current = data->env;
        }
        else
        {
            current->next = new_env(envp[i]);
            current = current->next;
        }
        i++;
    }
}
