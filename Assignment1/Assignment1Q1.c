// Description : open file
/*               Accept the file name from the user and open it using open().
                 Print sucess message + return file descriptor.
                 Handles error using perror().
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char fName[50];
    int fd = 0;
    memset(fName , '\0' , sizeof(fName));

    printf("Enter the file name that you want to open : ");
    scanf("%s",fName);

    fd = open(fName , O_RDONLY);

    if(fd == -1)
    {
        perror("Error occured while opening the file!");
    }
    else
    {
        printf("File opened sucessfully with fd : %d\n",fd);
    }

    close(fd);

    return 0;
}