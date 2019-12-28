#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<pthread.h>
#include<unistd.h>
#include<arpa/inet.h>
#define maxclient 5
#define portnumber 8888 
int main(int argc,char *argv[])
{
        char xx[20],buff[1024],bu[1024],k[10];
        int sockfd,new_fd;
        struct sockaddr_in clien,server;
        struct hostent *host;
         if(argc!=2)
        {
                        fprintf(stderr,"Usage :%s hostname\a\n",argv[0]);
                        exit(1);
         }
        if((host=gethostbyname(argv[1]))==NULL)
        {
                        fprintf(stderr,"Gethostname error\a\n",argv[1]);
                        exit(1);
         }
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                        fprintf(stderr,"Socket error:%s\a\n",strerror(errno));
                        exit(1);
         }
         bzero(&clien,sizeof(clien));
        clien.sin_family=AF_INET;
        clien.sin_port=htons(portnumber);
         if(inet_pton(AF_INET,argv[1],&clien.sin_addr) <= 0) {
        printf("server address error\n");   }
        if(connect(sockfd,(struct sockaddr *)(&clien),sizeof(struct sockaddr))==-1)
        {
                        fprintf(stderr,"Connect error:%s\a\n",strerror(errno));
                        exit(1);
         }
        fgets(buff,1024,stdin);
        send(sockfd,bu,sizeof(bu),0);
        exit(0);
}
