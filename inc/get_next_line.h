/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:17:01 by jfritz            #+#    #+#             */
/*   Updated: 2022/02/24 16:37:46 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAXFD			4096
# define BUFFER_SIZE	10000

char		*ft_strjoin_dif(char const *s1, char const *s2);
char		*ft_strdup_dif(const char *s1);
char		*ft_substr_dif(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);

#endif