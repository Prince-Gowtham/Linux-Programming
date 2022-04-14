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
    
    i=atoi(argv[2]);
    inputFd = open(b,O_RDONLY);
    stat(b, &statFd);

    while(lseek(inputFd,count, SEEK_SET) < statFd.st_size)
    {
        if(read(inputFd,&a,1) != '\n')
        {
            printf("%c",a);
            count++;
        }
	j++;
	if(j == i)
	    break;
    }
    close(inputFd);
}
