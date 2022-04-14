/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 14-04-2022									*/
/*   Filename    : cut.c									*/
/*   Description : we can remove the part of the file using this program('@..' '1-9' 'a-z''A-Z') */
/*												*/
/************************************************************************************************/

/* Included header file */

#include "cut.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
        //Initilation

    char buf[buf_size],buf1[buf_size],*a,c;
    ssize_t numRead,inputFlag;
    int inputFd,inputFd1=1,i,j=1,k,count=0;
	
    if (argc < 3) // To check the syntax
    {
	printf( "The Correct Syntax is : cut \"filename\" delimeter\n");
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

    a=strtok(buf,argv[2]);
    while(a !='\0')
    {
	printf(" %s\n", a);
	a = strtok('\0',argv[2]);
    }
    //j=(cut -f ":" -d : argv[1]);
    close(inputFd);
}
