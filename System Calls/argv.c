/***********************************************************************************/
/*Author 	: Gowtham S						           */
/*Date	 	: 08-04-2022						           */
/*Filename	: argv.c		   	                                   */
/*Description 	: (passing cmdline arguments to creat mp3 and read write the file) */
/***********************************************************************************/


//header file inclutions

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* function definitions*/

int main(int argc,char *argv[])/*passing cmdline arguments to the functions */
{
    int fd,fd1,fd2,fd3,fd4;
    char a[4665313];

    //file creation
    fd=creat(argv[1],S_IRWXU |S_IRWXG |S_IRWXO);
    (fd==-1)?printf("file doesn't creat "):printf("file created\n");

    //file opening
    fd1=open(argv[1],O_WRONLY);
    (fd1==-1)?printf("file doesn't open "):printf("file opened\n");
    
    //file opening
    fd2=open("./Arabic.mp3",O_RDONLY);
    (fd2==-1)?printf("file doesn't open "):printf("file opened\n");

    //file reading 
    fd3=read(fd2,a,4665313);
    (fd3==-1)?printf("file doesn't read\n"):printf("the file is readed\n");
    
    //file writing
    fd4=write(fd1,a,4665313);
    (fd4==-1)?printf("file doesn't write "):printf("file writed\n");

    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}
