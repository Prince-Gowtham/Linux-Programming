/************************************************************************************************/
/*   Author      : Gowtham.S									*/
/*   Date        : 20-04-2022									*/
/*   Filename    : mbr.h									*/
/*   Description : Displaying the MBR Partition table	        		 	      	*/
/*												*/
/************************************************************************************************/

						"This Program Will Execute Only Root Users"

1) In this program we are using popen.The  popen()  function opens a process by creating a pipe, and invoking the shell.Since a pipe is by definition unidirectional, the type argument may specify only reading or writing, not both; the resulting stream is correspondingly read-only or write-only.

2) popen("dd if=/dev/sda of=mbr.bin bs=512 count=1","r"). In using of popen command we can use the shell commands directly.dd(copy and convert)(if) was standard in and /dev/sda it is source file where needs to copy of the 0 to 512 bytes.(of)was standard out and (bs)is byte count( how many times we need to copy that count).we are  going to copy 512 bytes single time.the (r+w) flags avaliable here.in this function we are using readonly flag.(this is for the output file permission).

3) closing the popen processes.(every popen file needs to close. it is unidirectional we close at the time only process should be end).

4) popen("hexdump -x mbr.bin > hexformat.txt","r"). In before step we getting one output file that was binary format in this step we are going to convert the binary to hexa decimal format.so for that we are using the hexdump command it is used to convert binary to hexadecimal.

5) closing the popen processes.(every popen file needs to close. it is unidirectional we close at the time only process should be end).

6) popen("grep aa55 'hexformat.txt'  > gow.txt","r").we are checking the bootflag id default (aa55) using grep command and using standard out we are storing into the another file.

7) closing the popen processes. (every popen file needs to close. it is unidirectional we close at the time only process should be end).

8) we are opening the system call function it'll be used for opening the particular file(here we have a output file called gow.txt.

9) using the file descriptor we can access the file and we are readin and storing in to the buffers .at the same way we are displaying the output using the sytem call write when the the condition will false at the time the loop should be exit.

10) we are closing the file diescriptors.

for reference:
	man open
	man read
	man write
	man popen
        man dd
	man hexdump
