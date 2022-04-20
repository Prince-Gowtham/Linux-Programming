/********************************************************************************************************/
/*   Author      : Gowtham.S									        */
/*   Date        : 20-04-2022									        */
/*   Filename    : mbr.c									        */
/*   Description : open and copying MBR partition table 512 bytes and checking bootflags (root user). 	*/
/*												        */
/********************************************************************************************************/

					/* GO THROW THE README FILE */

/* Included header file */

#include "mbr.h"

/* Global variable definitions */

/* function definitions */

int main(int argc, char *argv[])
{
    char buf,buf1[buf_size],c[1];
    int inputFd,inputFd1=1,i,j=1,k,count=0;
    FILE *fd,*fd1;

    /* here we using popen (stream to or from a process).The  popen()  function opens a process by creating a pipe, and invoking the shell.Since a pipe is by definition unidirectional, the type argument may specify only reading or writing, not both; the resulting stream is corres pondingly read-only or write-only.*/

    fd=popen("dd if=/dev/sda of=mbr.bin bs=512 count=1","r");//here we opening the source /dev/sda.it's stdin and stdout mbr.bin   
    fd1=popen("hexdump -x mbr.bin > hexformat.txt","r");//here we are opening bin file and converting into hex file.
    pclose(fd);//closing the popen 
    pclose(fd1);//closing popen

    if (argc < 3) // To check the syntax
    {
	printf( "ERROR The Correct Syntax is : ./mbr bootflag filename \n\n");
	exit(-10);
    }
    	//Opening the file Readonly
    inputFd = open(argv[2],O_RDONLY); 

        // reading the file up to end of the file
    while(inputFd1 != 0) 
    {
	i=0;

	do
	{
	    inputFd1=read(inputFd,&buf,1);
	    buf1[i++]=buf;
	}while((inputFd1 != 0)&&(buf != '\n'));

	//assigning null bytes in end of the string
	buf1[i]='\0';

	count++;
	i=0;
	//the while loop should be run till null bytes

	while(buf1[i] != '\0')
	{
	    //checking the string and given string is same or not
	    if(buf1[i] == argv[1][0])
	    {
		k=1;//counting the number of cherecter 
		i++;

		//if it is execute till the condition false
		while((k < strlen(argv[1])) && (buf1[i] == argv[1][k]))
		{
		    i++;
		    k++;
		}

		//checking the given charecter and k count is equal
		if(k == strlen(argv[1]))
		    printf("%s",buf1);
		 //write(1,buf1,1);
             }
	    i++;
	}
    }
    printf("No of Line Readed %d ",count);
    printf("\n");
    close(inputFd);
}
