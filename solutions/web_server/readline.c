/* include readline */
#include	"unp.h"

static ssize_t
my_read(int fd, char *ptr)
{
	static int	read_cnt = 0;
	static char	*read_ptr;
	static char	read_buf[MAXLINE];

	if (read_cnt <= 0) {
		// Always true?? we set read_cnt to 0
again:
		// set read_cnt to the read, check if it's < 0
		if ( (read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
			// There's some error?
			if (errno == EINTR)
				goto again; // try again if async was interrupted
			return(-1);
		} else if (read_cnt == 0)
			// There's nothing to read?
			return(0);
		read_ptr = read_buf; // Point to the buffer that we read
	}

	read_cnt--;
	*ptr = *read_ptr++; // Set the input ptr to the read_ptr + 1
	return(1);
}

ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
	// ptr is char array
	int		n, rc;
	char	c, *ptr;

	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(fd, &c)) == 1) {
			// my_read was successful
			*ptr++ = c;
			if (c == '\n')
				break;	/* newline is stored, like fgets() */
		} else if (rc == 0) {
			if (n == 1)
				return(0);	/* EOF, no data read */
			else
				break;		/* EOF, some data was read */
		} else
			return(-1);		/* error, errno set by read() */
	}

	*ptr = 0;	/* null terminate like fgets() */
	return(n);
}
/* end readline */

ssize_t
Readline(int fd, void *ptr, size_t maxlen)
{
	ssize_t		n;

	if ( (n = readline(fd, ptr, maxlen)) < 0)
		err_sys("readline error");
	return(n);
}
