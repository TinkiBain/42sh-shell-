#include "exec.h"

void	redir_add_fd_table(int fd)
{
	int	*tmp;
	int	size;
	int	i;

	size = *g_open_fd + 1;
	i = 0;
	tmp = (int *)ft_xmalloc(sizeof(int) * size + 1);
	while (i < size)
	{
		tmp[i] = g_open_fd[i];
		++i;
	}
	tmp[i] = fd;
	tmp[0]++;
	free(g_open_fd);
	g_open_fd = tmp;
}
