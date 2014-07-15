#include <stdio.h>

char a[] = "hello world";

void out(FILE *out, char *strs)
{
    fprintf(out, "%s\n", strs);
    return;
}

int indexof(char letter, char *string)
{
    char * buf = string;

    int i = 0;
    while(*buf && *buf != letter)
    {
        buf++;
        i++;
    }
        out(stdout, buf);
    return (*buf)?i:-1;
}

char *ss = "testtest";

int main(void)
{
    char s[BUFSIZ];
    puts("input:");
    fgets(s, BUFSIZ, stdin);
    
    printf("%d\n", indexof('s', ss));
}
