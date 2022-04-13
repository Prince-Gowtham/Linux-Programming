/****************************************************************/
/*   Author      : Gowtham.S					*/
/*   Date        : 13-04-2022					*/
/*   Filename    : reverse.c					*/
/*   Description : reverseing the given string  		*/
/*								*/
/****************************************************************/

/* Included header file */

#include "reverse.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
        //Initilation

    char buf[buf_size];char buf1[buf_size];
    int i,k,j=0,inputFd,outputFd,inputFlag,outputFlag;
    ssize_t numRead;
    mode_t mode;
    int inputFd,inputFd1=1,i,j=1,k,count=0;
    if (argc < 4) // To check the syntax
    {
	printf( "The Correct Syntax is : rev \"filename src\" \"filename des\" \n");
	exit(-10);
    }

    //Declaration

    inputFlag  = O_RDONLY;
    outputFlag = O_CREAT | O_RDONLY | O_WRONLY;
    mode       = S_IRUSR | S_IWUSR  | S_IRGRP  | S_IWGRP | S_IROTH;

    //Opening File

    inputFd=open(argv[1],inputFlag);
    if(inputFd == -1)
	printf("%s : no such or directory ",argv[1]);

    //Creat and opening the file 

    outputFd=open(argv[2],outputFlag,mode);
    if(outputFd == -1)
	printf("%s : no such or directory ",argv[2]);

    /*reading file and reversing the files*/

    numRead=read(inputFd,buf,buf_size);
    	for(i=numRead; i>=0 ;i--)
	    buf1[j++]=buf[i];
    write(outputFd,buf1,numRead);
    close(inputFd);
    close(outputFd);
}
