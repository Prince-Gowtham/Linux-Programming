/**************************************************************************/
/*   Author      : Gowtham						  */
/*   Date        : 09-04-2022						  */
/*   Filename    : open.c						  */
/*   Description : opening,reading,creating,writing a file                */
/*									  */
/**************************************************************************/

/* Included header file */

#include "open.h"

/* Global variable definitions */

/* function definitions */


int main(int argc,char* argv[])
{
    //Initilation

    char buf[buf_size];
    int inputFd,outputFd,inputFlag,outputFlag;
    ssize_t numRead;
    mode_t mode;

    //Declaration

    inputFlag  = O_RDONLY;
    outputFlag = O_CREAT | O_RDONLY | O_WRONLY;
    mode       = S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP | S_IROTH;

    //Opening File

    inputFd = open(argv[1],inputFlag);
    if(inputFd == -1)
    {
	printf("%s : Error creating file",argv[1]);
	exit(-10);
    }

    outputFd = open(argv[2],outputFlag,mode);
    if(outputFd == -1)
    {
	printf("%s : Error creating file",argv[2]);
	exit(-20);
    }

    //Reading file and writing file

    while((numRead=read(inputFd,buf,buf_size))>0)
	if((write(outputFd,buf,numRead))!=numRead);
    
    close(inputFd);
    close(outputFd);
    exit(0);
}

