// Description : open file in the given mode
/*               Accept the file name & mode(R , W , RW , A) from the user.
                 Convert mode to flags(O_RDONLY,O_WRONLY, O_RDWR , O_APPEND | O_CREAT)
                 And open file accordingly and display fd.
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char fName[50];
    char fmode[50];
    int fd = 0;
    memset(fName , '\0' , sizeof(fName));
    memset(fmode , '\0' , sizeof(fmode));    

    printf("Enter the file name that you want to open : ");
    scanf("%s",fName);

    printf("Enter the mode in that you want to open the file : ");
    scanf("%s",fmode);

    if(strcmp(fmode , "R") == 0)
    {
        fd = open(fName , O_RDONLY | O_CREAT);
    }
    else if(strcmp(fmode , "W") == 0)
    {
        fd = open(fName , O_WRONLY | O_CREAT);
    }
    else if(strcmp(fmode , "RW") == 0)
    {
        fd = open(fName , O_RDWR | O_CREAT);
    }
    else if(strcmp(fmode , "A") == 0)
    {
        fd = open(fName , O_WRONLY | O_APPEND | O_CREAT);
    }
    else
    {
        perror("Invalid input!!");
    }

    if(fd == -1)
    {
        perror("Error occured while opening the file !!");
    }
    else
    {
        printf("File opened with fd : %d\n",fd);
    }
    
    close(fd);

    return 0;
}