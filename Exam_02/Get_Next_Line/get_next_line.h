#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
int					get_next_line(int fd, char **line);

#endif
