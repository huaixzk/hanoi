#include <stdio.h>
#include <unistd.h>

int main()
{
    write(STDOUT_FILENO, "hello, world!!\n", 15);
    return 0;
}
