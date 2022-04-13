/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 13-04-2022									*/
/*   Filename    : cat.c									*/
/*   Description : Displaying the what are the contents presented in the file			*/
/*												*/
/************************************************************************************************/

/* Included header file */

#include "cat.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
        //Initilation

    char buf[buf_size];
    int inputFd,inputFlag,i;
    ssize_t numRead;
    int inputFd,inputFd1=1,i,j=1,k,count=0;
    if (argc < 2) // To check the syntax
    {
	printf( "The Correct Syntax is : cat \"filename\" \n");
	exit(-10);
    }

    //Declaration

    inputFlag  = O_RDONLY;

    //Opening File

    inputFd=open(argv[1],inputFlag);
    if(inputFd == -1)
	printf("%s : no such or directory ",argv[1]);

    /*reading file */

    numRead=read(inputFd,buf,buf_size);

    //printing the file

    for(i=0;i<numRead;i++)
	printf("%c",buf[i]);
    close(inputFd);
}
