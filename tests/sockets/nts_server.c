/****************************************************************
** 
** server端:
** 
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFLEN 1024
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef void Sigfunc (int);

void str_echo(FILE *,int);
//Sigfunc *signal(int, Sigfunc *);

title()
{
        system("clear");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("      北京南天软件有限公司 银行交易主机系统 \n");
        printf("                  交易服务控制界面      \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

}

int main(int argc,char **argv)
{
 int connfd,listenfd;
 pid_t childpid;
 socklen_t clilen;
 struct sockaddr_in cliaddr,servaddr;
 void sig_chld(int);

 title();
 listenfd = socket(AF_INET, SOCK_STREAM, 0);

 memset(&servaddr,0,sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(5358);

 bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
 listen(listenfd,8);

 signal(SIGCHLD,sig_chld);

 while(1)
 {
  clilen = sizeof(cliaddr);
  if((connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&clilen)) < 0)
  {
   if(errno == EINTR)
   {
    fputs("accept error: EINTR\n",stdout);
    continue;
   }
   else
   {
    fputs("accept error..\n",stdout);
   }
  }

  if((childpid = fork()) == 0)
  {
   close(listenfd);
   str_echo(stdin,connfd);
   exit(0);
  }
  close(connfd);
 }
}

void str_echo(FILE *fp,int sockfd)
{
 int n = 0;
 char sendbuf[BUFLEN] = { 0 },recvbuf[BUFLEN] = { 0 };
 int maxfdp;
 fd_set rset;

 FD_ZERO(&rset);

 while(1)
 {
  FD_SET(fileno(fp),&rset);
  FD_SET(sockfd, &rset);
  maxfdp = MAX(fileno(fp),sockfd)+1;

  select(maxfdp, &rset ,NULL, NULL, NULL);
  
  if(FD_ISSET(sockfd, &rset))
  {    
   if(n = read(sockfd, recvbuf, BUFLEN) == 0)
   {
    return;
   }
   if(n == -1)
   {
    break;
   }
   printf("客户机交易信息:%s\n",recvbuf);
   if (strcmp(recvbuf,"010101")==0) 
	system("./tx_010101");
   if (strcmp(recvbuf,"010102")==0) 
	system("./tx_010102"); 
   if (strcmp(recvbuf,"010103")==0) 
	system("./tx_010103"); 
   if (strcmp(recvbuf,"010201")==0) 
	system("./tx_010201"); 
   if (strcmp(recvbuf,"010202")==0) 
	system("./tx_010202"); 
   if (strcmp(recvbuf,"300108")==0) 
	system("./tx_300108"); 
   memset(recvbuf,0,BUFLEN);
  }
  if(FD_ISSET(fileno(fp),&rset))
  {
   scanf("%s",sendbuf);
   write(sockfd, sendbuf,strlen(sendbuf));
  }
 }
}

void sig_chld (int signo)
{
 pid_t pid;
 int stat;

 while ((pid = waitpid(-1,&stat, WNOHANG)) > 0)
 {
  printf("child %d terminated\n",pid);
 }
 return;
}

