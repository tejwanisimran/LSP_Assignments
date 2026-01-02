// Description : Write a String into the file
/*               Accept Filename and string from the user.
                 Write string using write().
                 Print number of bytes written.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE_BUFFER 100
#define SIZE_FILE 50
#define SIZE_STRING 100
int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    char fName[SIZE_FILE];
    char string[SIZE_STRING];
    int iRet = 0 ;

    memset(Buffer , '\0' , SIZE_BUFFER);
    memset(fName , '\0' , SIZE_FILE);
    memset(string , '\0', SIZE_STRING);

    printf("Enter the file that you want to open : ");
    scanf("%s",fName);

    getchar();

    printf("Enter the string that you want to write into the file : ");
    fgets(string , SIZE_STRING , stdin);

    fd = open(fName , O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        perror("Error : ");
        return -1;
    }

    printf("File opened successfully with fd : %d\n",fd);

    iRet = write(fd ,string , strlen(string));

    printf("%d bytes gets successfully written into the file \n",iRet);

    close(fd);

    return 0;
}