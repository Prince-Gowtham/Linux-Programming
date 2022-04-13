/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 13-04-2022									*/
/*   Filename    : pattern.c									*/
/*   Description : pattern matching(how many of them same string present the dircctory)		*/
/*												*/
/************************************************************************************************/

/* Included header file */

#include "pattern.h"

/* Global variable definitions */

/* function definitions */

int main(int argc, char *argv[])
{
    char buf,buf1[buf_size];
    int inputFd,inputFd1=1,i,j=1,k,count=0;
    if (argc < 4) // To check the syntax
    {
	printf( "The Correct Syntax is : grep \"pattern\" \"filename\" \n");
	exit(-10);
    }
    	//Opening the file Readonly

    inputFd = open(argv[3],O_RDONLY); 

        // reading the file up to end of the file
    while(inputFd1 != 0) 
    {
	i=0;
	//we need to check the 
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
	    if(buf1[i] == argv[2][0])
	    {
		k=1;//counting the number of cherecter 
		i++;//incrementing i
		//if it is execute till the condition false
		while((k < strlen(argv[2])) && (buf1[i] == argv[2][k]))
		{
		    i++;
		    k++;
		}
		//checking the given charecter and k count is equal
		if(k == strlen(argv[2]))
		    printf("%s",buf1);
	    }
	    i++;
	}
    }
    printf("\n");
    printf("No of Line Readed %d ",count);
    close(inputFd);
}
