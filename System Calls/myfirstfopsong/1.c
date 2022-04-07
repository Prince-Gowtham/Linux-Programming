//########################################################################################
//# write a c program for read mp3 and creat one mp3 file and write using systemcalls..? #
//#								       			 #
//########################################################################################


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd,fd1,fd2,fd3,x,y,z;
    char a[4665313];
    //opening file
    fd=open("./Arabic.mp3",O_RDONLY);
    (fd==-1)?printf("file doesn't open\n"):printf("the file is opened\n");
    //reading file
    fd1=read(fd,a,4665313);
    (fd1==-1)?printf("file doesn't read\n"):printf("the file is readed\n");
    //creating new file
    fd2=creat("./sysfopsong1.mp3",S_IRWXU |S_IRWXG |S_IRWXO);
    (fd2==-1)?printf("file doesn't creat\n"):printf("the file is created\n");
    //file Writing
    fd3=write(fd2,a,4665313);
    (fd2==-1)?printf("file doesn't write\n"):printf("the file is writing\n");
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
}
