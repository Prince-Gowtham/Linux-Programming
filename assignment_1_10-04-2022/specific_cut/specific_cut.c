/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 13-04-2022									*/
/*   Filename    : specfic_cut.c								*/
/*   Description : Displaying the cut particular contents presented in the file			*/
/*												*/
/************************************************************************************************/

/* Included header file */

#include "cut.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
        //Initilation

    char buf[buf_size],c;
    char buf1[buf_size];
    ssize_t numRead,inputFlag;
    int inputFd,inputFd1=1,i=0,j=0,k,count=0;
    if (argc < 3) // To check the syntax
    {
	printf( "The Correct Syntax is : cut \"filename\" delimeter\n");
	exit(-10);
    }

    //Declaration

    inputFlag  = O_RDONLY;

    //Opening File
    c=*argv[2];
    inputFd=open(argv[1],inputFlag);
    if(inputFd == -1)
	printf("%s : no such or directory ",argv[1]);

    /*reading file */
    numRead=read(inputFd,buf,buf_size); 
    do
    {
	buf1[i] =buf[i];
	i++;
    }while(buf[i] != c);
    buf1[i]='\0';
    printf("%s",buf1);
}
