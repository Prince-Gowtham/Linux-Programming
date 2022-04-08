/****************************************************************/
/*   Author      : Gowtham.S					*/
/*   Date        : 08-04-2022					*/
/*   Filename    : copy.c					*/
/*   Description : copying file to another file  		*/
/*								*/
/****************************************************************/

/* Included header file */

#include "copy.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
    int fd,fd1,fd2,fd3;
    char a[4665313];

    /*opening file*/
    fd=open(argv[1],O_RDONLY);
    (fd==-1)?printf("file not opened\n"):printf("file opened\n");

    /*reading file */
    fd1=read(fd,a,4665313);
    (fd1==-1)?printf("file not readed\n"):printf("file readed\n");

    /*creat file */
    fd2=creat(argv[2],S_IRWXU | S_IRWXG | S_IRWXO);
    (fd2==-1)?printf("file not creat\n"):printf("file created\n");
    
    /*write file */
    fd3=write(fd2,a,4665313);
    (fd3==-1)?printf("file not write\n"):printf("file writed\n");

    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
}
