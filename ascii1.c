#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define AUTHOR "Geek.Law"
#define PROGNAME "ascii"

#define SIZE 4
//#define ASC 95
#define ASC_S 32
#define OCT 8
#define HEX 16
#define DEC 10

/* just used for myself , not good value*/
#if 0
#define A [ m ]  ascii.asc_s[ m++ ]
#endif

static char *progname;
static int flag = DEC;

void printversion(char *str)
{
    printf("%s\t version  %s by %s\n", progname, str, AUTHOR);
    return;
}

void printhelp(void)
{
    printf("usage: %s [-vohd?]\n", progname);
    return;
}

void do_print(int i, int flag)
{
    if(flag == OCT)
        printf("0%o %c \t", i, i);
    if(flag == HEX)
        printf("%.2x %c\t", i, i);
    if(flag == DEC)
        printf("%.2d %c \t", i, i);
    return;
}


void do_print2(int i, char *str, const int flag)
{
    if(flag == OCT)
        printf("0%o %s\t", i, str);
    if(flag == HEX)
        printf("%.2x %s\t", i, str);
    if(flag == DEC)
        printf("%.2d %s\t", i, str);
    return;
}

struct ascii{
    char *asc_s[ASC_S];
   // int asc[ASC];
    char *asc_last;
};

struct ascii asc_init(void)
{
    int i = 0;
    struct ascii buf;
    
 //   buf.asc_s[i++] = "NULL";
    buf.asc_s[i++] = "nul";
    buf.asc_s[i++] = "sah";
    buf.asc_s[i++] = "stx";
    buf.asc_s[i++] = "etx";
    buf.asc_s[i++] = "eot";
    buf.asc_s[i++] = "enq";
    buf.asc_s[i++] = "ack";
    buf.asc_s[i++] = "bel";
    buf.asc_s[i++] = "bs";
    buf.asc_s[i++] = "ht";
    buf.asc_s[i++] = "nl";
    buf.asc_s[i++] = "vt";
    buf.asc_s[i++] = "np";
    buf.asc_s[i++] = "cr";
    buf.asc_s[i++] = "so";
    buf.asc_s[i++] = "si";
    buf.asc_s[i++] = "dle";
    buf.asc_s[i++] = "dc1";
    buf.asc_s[i++] = "dc2";
    buf.asc_s[i++] = "dc3";
    buf.asc_s[i++] = "dc4";
    buf.asc_s[i++] = "nak";
    buf.asc_s[i++] = "syn";
    buf.asc_s[i++] = "etb";
    buf.asc_s[i++] = "can";
    buf.asc_s[i++] = "em";
    buf.asc_s[i++] = "sub";
    buf.asc_s[i++] = "esc";
    buf.asc_s[i++] = "fs";
    buf.asc_s[i++] = "gs";
    buf.asc_s[i++] = "rs";
    buf.asc_s[i++] = "us";
    buf.asc_s[i++] = "sp";
    /*for(; i < 127; i++)*/
        /*buf.asc[i] = i;*/
    buf.asc_last = "del";
    return buf;
}

void  printascii(const struct ascii tmp,const int fl)
{
   int i; 

    for(i = 0; i < 128; i++)
    {
        if(i < 33)
            do_print2(i, tmp.asc_s[i], fl);
        else if(i < 127)
            do_print(i, fl);
        else
            do_print2(i, tmp.asc_last, fl);
        if(!(((i+1) % 8)))
                 printf("\n");
    }
    puts("\n");
    return;
}

int main(int argc, char **argv)
{
    char *optstring = "vohd?";
    char optch;
    struct ascii t = asc_init();
    progname = *argv;
    while(strrchr(progname, '/'))
        progname++;
    while((optch = getopt(argc, argv, optstring)) != -1)
    {
        switch(optch)
        {
            case 'v':
                printversion("1.0pre");
                return 0;
                break;
            case '?':
                printhelp();
                return 0;
                break;
            case 'o':
                flag = OCT;
               // return 0;
                break;
            case 'h':
                flag = HEX;
                //return 0;
                break;
            case 'd':
                flag = DEC;
                //return 0;
                break;
            default:
                printhelp();
                return 0;
        }
    }
    printascii(t, flag);
    return 0;
}

