/****************************************************************/
/*   Author      : Gowtham.S					*/
/*   Date        : 13-04-2022					*/
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
        //Initilation

    char buf[buf_size];
    int inputFd,inputFd1,outputFd,inputFlag,outputFlag;
    ssize_t numRead;
    mode_t mode;
    if (argc < 4) // To check the syntax
    {
	printf( "The Correct Syntax is : copy \"filename src \" \"filename des\" \n");
	exit(-10);
    }

    //Declaration

    inputFlag  = O_RDONLY;
    outputFlag = O_CREAT | O_RDONLY | O_WRONLY | O_APPEND;
    mode       = S_IRUSR | S_IWUSR  | S_IRGRP  | S_IWGRP | S_IROTH;

    //Opening File

    inputFd=open(argv[1],inputFlag);
    if(inputFd == -1)
	printf("%s : no such or directory ",argv[1]);

    //Creat and opening the file 

    outputFd=open(argv[2],outputFlag,mode);
    if(outputFd == -1)
	printf("%s : no such or directory ",argv[2]);

    /*reading file */

    while( (numRead=read(inputFd,buf,buf_size))>0)
	if((write(outputFd,buf,numRead))!=numRead);
}
