// Description : Read N bytes from the file
/*               Accept Filename and n bytes 
                 Read exactly N bytes using read() and print on console.
                 If file contains less than N bytes then print available bytes.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE_BUFFER 100
#define SIZE_FILE 50

int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    char fName[SIZE_FILE];
    int iRet = 0;
    int iBytes = 0;

    memset(Buffer , '\0' , SIZE_BUFFER);
    memset(fName , '\0' , SIZE_FILE);

    printf("Enter the file that you want to open : ");
    scanf("%s",fName);

    printf("Please enter the bytes that you want to read from the file : ");
    scanf("%d",&iBytes);

    if((iBytes < 0) || (iBytes > SIZE_BUFFER))
    {
        printf("Invalid Number of bytes !!\n");
        return -1;
    }

    fd = open(fName , O_RDONLY);

    if(fd == -1)
    {
        perror("Error : ");
        return -1;
    }

    printf("File opened successfully with fd : %d\n",fd);

    iRet = read(fd , Buffer , iBytes);

    if(iRet == -1)
    {
        perror("Error : ");
        close(fd);
        return -1;
    }

    printf("%d bytes gets succesfully read\n",iRet);

    printf("Data from file : %s\n",Buffer);

    close(fd);

    return 0;
}