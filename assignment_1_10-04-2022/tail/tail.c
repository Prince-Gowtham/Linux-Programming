/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 14-04-2022									*/
/*   Filename    : tail.c									*/
/*   Description : display the file content given number of charecters				*/
/*												*/
/************************************************************************************************/

/* Included header file */

#include "tail.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
    int inputFd,i,j=0;
    off_t count = 0;
    char a,*b = argv[1];
    struct stat statFd;
    
    i=atoi(argv[2]);//atoi command it is used to convert string to interger
    inputFd = open(b,O_RDONLY);//opening the file
    stat(b, &statFd);//predefined function have in this structure file status

    while(lseek(inputFd,count, SEEK_SET) < statFd.st_size)//checing the file and moving the offset using lseek command
    {
        if(read(inputFd,&a,1) != '\n')//reading the filediscriptor byte by byte
        {
            printf("%c",a);//printing the buffer
            count++;
        }
	j++;
	if(j == i)//when this line reaches the exact conditions was true the break statement executed
	    break;
    }
    close(inputFd);
}
