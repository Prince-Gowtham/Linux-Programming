//write a program for creat one file store some datas into the buffer and write into the files
//again read the file and store the data into the buffers...? 

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int x,y,z,fd;
    	//creating the file
    fd=open("./read.txt",O_CREAT);
    if(fd==-1)
	printf("file is already there\n");
    else
	printf("file has been created\n");
    close(fd);
    	//storeing the data into the buffers
    char b[10],a[]={'H','i','G','o','w','t','h','a','m','\0'};
    	//writeing the file
    fd=open("./read.txt",O_WRONLY); 
    x=write(fd,a,9);
    if(x==-1)
	printf("the file doesn't write\n");
    else
	printf("the file was writen successfully\n");
    close(fd);
    	//reading the file
    fd=open("./read.txt",O_RDONLY); 
    y=read(fd,b,10);
    if(y==-1)
	printf("the file doesn't read\n");
    else
	printf("the file was readed successfully\n");
    	//printing the buffer or array
    for(z=0;z<9;z++)
	printf("%c",b[z]);
    close(fd);
}
