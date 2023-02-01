#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open

// 4 possible main function signatures:
// int main(int argc, char **argc)
// int main(int argc, char *argc)
// int main(int argc, char *argv[])
int main(void)
{
    int fd = open("foo.out", O_CREAT | O_WRONLY, 0644); // r/w permissions
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    // char pointer (string)
    char *s = (pid == 0)
                  ? "C" // pointers
                  : "P";

    // use & to "address of" pointer
    char c = (pid == 0)
                 ? 'C' // a char (individual byte)
                 : 'P';

    for (int i = 0; i < 2000; i++)
        // a syscall, gives up control to OS
        write(fd, &c, 1); // expects a pointer to some data: s or &c

    close(fd); // both processes need to close the file descriptor
}