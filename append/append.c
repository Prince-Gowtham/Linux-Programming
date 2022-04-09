/**************************************************************************/
/*   Author      : Gowtham						  */
/*   Date        : 09-04-2022						  */
/*   Filename    : append.c						  */
/*   Description : reading 2 files and writing in single file             */
/*									  */
/**************************************************************************/

/* Included header file */

#include "append.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char* argv[])
{
    //Initilation

    char buf[buf_size];
    int inputFd,inputFd1,outputFd,inputFlag,outputFlag;
    ssize_t numRead;
    mode_t mode;

    //Declaration

    inputFlag  = O_RDONLY;
    outputFlag = O_CREAT | O_RDONLY | O_WRONLY | O_APPEND;
    mode       = S_IRUSR | S_IWUSR  | S_IRGRP  | S_IWGRP | S_IROTH;

    //Opening File

    inputFd = open(argv[1],inputFlag);
    if(inputFd == -1)
    {
	printf("%s : Error creating file",argv[1]);
	exit(-10);
    }

    inputFd1 = open(argv[2],inputFlag);
    if(inputFd1 == -1)
    {
	printf("%s : Error creating file",argv[1]);
	exit(-10);
    }

    outputFd = open(argv[3],outputFlag,mode);
    if(outputFd == -1)
    {
	printf("%s : Error creating file",argv[2]);
	exit(-20);
    }

    //Reading file1 and writing file

    while((numRead=read(inputFd,buf,buf_size))>0)
	if((write(outputFd,buf,numRead))!=numRead);

    //Reading file2 and writing file the same file

    while((numRead=read(inputFd1,buf,buf_size))>0)
	if((write(outputFd,buf,numRead))!=numRead);
    
    close(inputFd);
    close(outputFd);
    exit(0);
}
