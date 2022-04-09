/**************************************************************************/
/*   Author      : Gowtham.S						  */
/*   Date        : 09-04-2022						  */
/*   Filename    : strrev.c						  */
/*   Description : reading a stringa and store in entire string in reverse*/
/*									  */
/**************************************************************************/

/* Included header file */

#include "strrev.h"

/* Global variable definitions */

/* function definitions */

int main(int argc,char *argv[])
{
    //declareing the varriables
    int x,i,j=0,k,str=0,fd,open_fd,read_fd,creat_fd,write_fd;
    char c[1];

    //opening the file
    open_fd=open(argv[1],00);
    if(open_fd==-1)
	printf("fd: no such as dircetory %s %s",__FILE__,argv[1]);

    //checking how many chrecter presented in that file
    fd=open(argv[1],00);
    while((x=read(fd,c,1)!=0))
	str++;
    printf("given file have %d chracters\n",str);
    close(fd);//closing the fd

    char a[str],b[str];//declare and initializing buffers

    //reading the file
    read_fd=read(open_fd,a,str);
    if(read_fd==-1)
	printf("read_fd: no such as dircetory %s %s",__FILE__,argv[1]);

    //reversing the strings
    for(i=str;i>=0;i--)
    {
	if(a[i]!=0)
	    b[j++]=a[i];	
    }
    //creating the new file
    creat_fd=creat(argv[2],S_IRWXU | S_IRWXG);
    if(creat_fd==-1)
	printf("creat_fd: no such as dircetory %s %s",__FILE__,argv[2]);

    //writing into the new file
    write_fd=write(creat_fd,b,str);
    if(write_fd==-1)
	printf("write_fd: no such as dircetory %s %s",__FILE__,argv[2]);

    //closing all file discreptors
    close(open_fd);
    close(creat_fd);
    close(read_fd);
    close(write_fd);
}
