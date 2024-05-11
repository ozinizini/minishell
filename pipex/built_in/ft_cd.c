/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:28:00 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 14:00:37 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static	void	var_value(char **path, t_list *env, int position)
{
	int		i;

	i = 1;
	while (i++ < position)
		env = env->next;
	*path = ft_strnstr((const char *)env->content, "=",
			ft_strlen((const char *)env->content));
	if (*path)
		(*path)++;
}

static int	update_pwd_oldpwd_env_variables(t_list **env,
	t_list **export_list, char *old_path)
{
	char	*pwd_path;
	char	cwd[1024];

	ft_export(env, export_list, old_path);
	getcwd(cwd, sizeof(cwd));
	pwd_path = ft_strjoin((const char *)"PWD=", (const char *)cwd);
	if (pwd_path == NULL)
	{
		free(old_path);
		return (error_message_return
			("Minishell: cd: Memory allocation failed\n", 1));
	}
	ft_export(env, export_list, pwd_path);
	free(old_path);
	free(pwd_path);
	return (0);
}

static	int	execute_chdir(char *path, char *old_path,
	t_list **env, t_list **export_list)
{
	if (chdir(path) != 0)
	{
		free(old_path);
		return (minishell_error_message_return(strerror(errno), path, 1));
	}
	else
		return (update_pwd_oldpwd_env_variables(env, export_list, old_path));
}

int	ft_cd(char *path, t_list **env, t_list **export_list)
{
	char	cwd[1024];
	char	*old_path;

	if (path == NULL)
	{
		if (env_variable_exists(*env, "HOME"))
			var_value(&path, *env, env_variable_exists(*env, "HOME"));
		else
			return (error_message_return("Minishell: cd: HOME not set\n", 1));
	}
	else if (!ft_strcmp(path, "-"))
	{
		if (env_variable_exists(*env, "OLDPWD"))
			var_value(&path, *env, env_variable_exists(*env, "OLDPWD"));
		else
			return (error_message_return("Minishell: cd: OLDPWD not set\n", 1));
	}
	getcwd(cwd, sizeof(cwd));
	old_path = ft_strjoin((const char *)"OLDPWD=", (const char *)cwd);
	if (old_path == NULL)
		return (error_message_return
			("Minishell: cd: Memory allocation failed\n", 1));
	return (execute_chdir(path, old_path, env, export_list));
}
