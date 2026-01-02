// Description : Read whole file
/*               Accept Filename and print full content on console
                 Use Buffer loop (read() until 0).
                 Show total bytes read.
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
    int iRet = 0 , iTotal = 0;

    memset(Buffer , '\0' , SIZE_BUFFER);
    memset(fName , '\0' , SIZE_FILE);

    printf("Enter the file that you want to open : ");
    scanf("%s",fName);

    fd = open(fName , O_RDONLY);

    if(fd == -1)
    {
        perror("Error : ");
        return -1;
    }

    printf("File opened successfully with fd : %d\n",fd);

    while((iRet = read(fd , Buffer , SIZE_BUFFER)) != 0)
    {
        write(1 ,Buffer , iRet);
        iTotal = iTotal + iRet ;
        memset(Buffer , '\0' , SIZE_BUFFER);
    }
    printf("\n");
    printf("%d bytes gets succesfully read\n",iTotal);

    close(fd);

    return 0;
}