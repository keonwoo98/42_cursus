/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:40:35 by keokim            #+#    #+#             */
/*   Updated: 2021/06/28 19:40:37 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
static void		free_all(char **path, char **cmd, char *cmd_path);
char			**split_path(char **envp);
char			*get_path(char **path, char *cmd);
int				main(int argc, char **argv, char **envp);

#endif
