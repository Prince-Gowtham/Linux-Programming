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
    (fd==-1)?printf("file doesn't open"):printf("the file is opened ");
    //reading file
    fd1=read(fd,a,4665313);
    (fd1==-1)?printf("file doesn't read "):printf("the file is readed ");
    //creating new file
    fd2=creat("./sysfopsong1.mp3",S_IRWXU |S_IRWXG |S_IRWXO);
    (fd2==-1)?printf("file doesn't creat "):printf("the file is created ");
    //file Writing
    fd3=write(fd2,a,4665313);
    (fd2==-1)?printf("file doesn't write "):printf("the file is write ");
    close(fd);
}
