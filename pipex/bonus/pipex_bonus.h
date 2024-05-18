/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:18:07 by ihajouji          #+#    #+#             */
/*   Updated: 2024/05/18 09:32:37 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "gnl_bonus.h"

size_t	ft__strlen(const char *s);
void	ft_exit(int i);
char	*ft__strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*fill(char *str, int count, int index);
int		handle_quote(char *s, int i, char c);
void	ft__free(char **str, int i);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_path(char *command, char **env);
void	run(char *av, char **env);
void	dup_in(int filein);
void	_wait(int i);
int		open_file(char *file, int mode);

#endif