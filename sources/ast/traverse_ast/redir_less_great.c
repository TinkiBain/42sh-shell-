#include "exec.h"

int		redir_less_great(t_io_redirect *redir)
{
	int fd;

	if ((fd = open(redir->file_name, O_RDWR | O_CREAT, 0644)) < 0)
		return (redirect_error_open(redir->file_name));
	if (redir->io_number != -1)
	{
		if (redir->io_number >= 10000)
			return (redirect_error_fd(redir->io_number));
		dup2(fd, redir->io_number);
		close(fd);
		fd = redir->io_number;
	}
	// добавить в таблицу файловых дескрипторов
	return (1);
}
