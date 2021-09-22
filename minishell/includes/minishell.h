/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:42:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:42:52 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define REDIROUT 1
# define REDIRIN 2
# define APPEND 3
# define HEREDOC 4
# define PIPE 5
# define DQUOTE 6
# define SQUOTE 7
# define CMD 8
# define BUILTIN 9
# define ARG 10
# define FILEARG 11
# define DIRARG 12
# define DOLLAR 13

typedef struct s_node
{
	int				type;
	char			*contents;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_cmd
{
	int				size;
	struct s_node	*first;
	struct s_node	*last;
}t_cmd;

typedef struct s_state
{
	char			**env;
	int				exit_status;
	int				redir_in;
	int				redir_out;
	int				pip[2][2];
	int				i;
	int				ac;
	int				fork;
}t_state;

t_state				g_state;

/*
** assign_util.c
*/
int		check_type(int type);
int		check_syntax(t_node *node);
/*
**	built_in.c
*/
int		is_builtin(char *str);
void	exec_builtin(t_node *node);
/*
**	check_assign.c
*/
int		check_redir(t_cmd *cmd);
// int		check_type(int type);
void	assign_arg(t_cmd *cmd);
/*
**	env.c
*/
int		environ_len(char **envp);
int		env_len(void);
int		get_env_last(void);
int		is_exist(char *key);
/*
** error_util.c
*/
void	print_errmsg(char *str, char *msg);
void	print_errmsg2(char *str, char *contents, char *msg);
void	print_error_util(char *str, char *contents, char *msg);
/*
**	error.c
*/
void	error_return(t_cmd *cmd, char *line);
void	error_exit(char *str);
void	syntax_error(char c);
/*
**	exec_cmd_utils.c
*/
char	**split_path(char **envp);
char	**get_cmd(t_node *node);
char	*get_path(char **path, char *cmd);
/*
**	exec_cmd.c
*/
int		exec_cmd(t_node *node);
/*
**	execute_utils.c
*/
void	connect_redirect(t_node *node);
void	set_pipe(void);
void	pre_execute(t_node *node);
void	backup_execute(int *stdin, int *stdout);
void	execute_node(t_node *node);
/*
**	execute.c
*/
void	builtin(t_node *node);
void	execute_cmd(t_node *node);
void	execute(t_node *node);
/*
**	expansion.c
*/
void	expansion(t_cmd **cmd);
/*
** ft_cd_utils.c
*/
void	add_oldpwd(char *path);
int		ft_cd_cdpath(char **cd_path, t_node *node);
int		ft_cd_none(char *home);
int		is_home_exist(char *home);
char	**put_slash(void);
/*
**	ft_cd.c
*/
int		ft_cd(t_node *node);
/*
** ft_echo.c
*/
int		ft_echo(t_node *node);
/*
**	ft_exit.c
*/
void	ft_exit(t_node *node);
/*
** ft_export_util.c
*/
void	add_env_arg(t_node *node, int i);
void	add_env_quote(t_node *node, int i);
/*
**	ft_export.c
*/
int		ft_export(t_node *node);
int		is_key_valid(char *key);
/*
**	ft_unset.c
*/
int		ft_unset(t_node *node);
/*
** get_env.c
*/
int		get_env(char *str);
char	*get_env_str(char *str);
/*
**	get_next_line.c
*/
int		get_next_line(int fd, char **line);
/*
**	list_func.c
*/
t_cmd	*init_cmd_list(void);
t_node	*new_list(char *contents, int type);
void	add_list(t_cmd *cmd, char *contents, int type);
void	free_list(t_cmd *cmd);
/*
**	parsing.c
*/
int		parse_line(t_cmd **cmd, char *line);
/*
**	print_export.c
*/
void	print_export(void);
void	free_str(char **str);
/*
**	redirect.c
*/
int		redirect_in(char *file);
int		redirect_out(char *file);
int		redirect_out_append(char *file);
void	here_doc(t_node *node);
void	connect_pipe(int fd[2], int io);
/*
** remove_blank.c
*/
void	remove_blank(t_cmd **cmd);
/*
**	signal.c
*/
void	set_signal(void);
#endif
