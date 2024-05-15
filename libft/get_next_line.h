/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/22 15:35:34 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char **s1, char const *s2, int len2);
char	*ft_charshifter(char *s1, int shift);
char	*ft_free_error(char **s1, char *s2);
int		ft_get_line(int fd, char **readed, int firstrun);
int		ft_strnlen(char const *s);
size_t	ft_strlen(char const *s);

#endif
