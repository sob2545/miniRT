/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:39:01 by sesim             #+#    #+#             */
/*   Updated: 2022/10/16 20:10:29 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_line
{
	char			*line;
	int				idx;
	struct s_line	*next;
	struct s_line	*prev;
}	t_line;

size_t	ft_strlen_g(char *s);
char	*ft_strchr_g(char *s, int c);
size_t	ft_strlcpy_g(char *dst, char *src, size_t dstsize);
char	*ft_strjoin_g(char *s1, char *s2);
char	*new_line(char *bac);
char	*read_line(int fd, char *bac);
char	*get_line(char *bac);
char	*get_next_line(int fd);
char	*get_one_line(int fd);
char	*lst_new(t_line *head, int fd);

#endif
