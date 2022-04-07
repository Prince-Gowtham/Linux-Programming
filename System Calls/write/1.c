#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd,fd1,fd2,fd3,x,y,z;
    char a[1]={0};
    //opening file
    fd=open("./Gowtham.txt",O_RDONLY);
    (fd==-1)?printf("file doesn't open"):printf("the file is opened ");
    //reading file
    fd1=read(fd,a,100);
    (fd1==-1)?printf("file doesn't read "):printf("the file is readed ");
    //creating new file
    fd2=creat("./hari1.txt",S_IRWXU |S_IRWXG |S_IRWXO);
    (fd2==-1)?printf("file doesn't creat "):printf("the file is created ");
    //file creation
    fd3=write(fd2,a,100);
    (fd2==-1)?printf("file doesn't write "):printf("the file is write ");
    close(fd);
}
