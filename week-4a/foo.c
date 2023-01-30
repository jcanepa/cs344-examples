#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("foo.txt", O_WRONLY | O_CREAT, 0644);

    dup2(fd, 1);

    write(1, "Hello!\n", 7);

    close(fd);
}