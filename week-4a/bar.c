#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pipe_fd[2];

    pipe(pipe_fd); // pass pointer in

    printf(
        "input: %d, output: %d\n",
        pipe_fd[0],
        pipe_fd[1]);

    write(pipe_fd[1], "Hello!", 7); // (7 bytes includes null terminator at the end of the string literal)

    char buf[1024];
    read(pipe_fd[0], buf, 1024);
    printf("Read from pipe: '%s'\n", buf);
}