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
    char buf[buf_size];
    int inputFd;
    FILE *fd,*fd1,*fd2;

    /* here we using popen (stream to or from a process).The  popen()  function opens a process by creating a pipe, and invoking the shell.Since a pipe is by definition unidirectional, the type argument may specify only reading or writing, not both; the resulting stream is corres pondingly read-only or write-only.*/

    fd=popen("dd if=/dev/sda of=mbr.bin bs=512 count=1","r");/*here we opening the source /dev/sda.it's stdin and stdout mbr.bi*n*/
    pclose(fd);//closing the popen 

    fd1=popen("hexdump -x mbr.bin > hexformat.txt","r");     //here we are opening bin file and converting into hex file.
    pclose(fd1);//closing popen

    fd2=popen("grep aa55 'hexformat.txt'  > gow.txt","r");   //here we are checking bootable flags. 
    pclose(fd2);//closing popen
    
    inputFd=open("./gow.txt",O_RDONLY);// we are opening the file readonly mode.

    while((read(inputFd,buf,1))>0) // we are reading the file when the conditions shold be false.
	write(1,buf,1);                  // we are using printing the buf.
    close(inputFd);//closing open
}
