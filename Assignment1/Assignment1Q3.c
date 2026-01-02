// Description : Check File Access Permission
/*               Use access() to check permission for current process
                 Print Accessible / Not Accessible with reason.
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
        printf("Invalid input!!");
    }


    if(fd == -1)
    {
        perror("Error occured while opening the file!!");
    }
    else
    {
        printf("File opened with fd : %d\n",fd);
    }

    if(access(fName , R_OK) == 0)
    {
        printf("Read permission is Accessible...\n");
    }
    else
    {
        perror("Read Permission is not Accessible...\n");
    }
    if(access(fName , W_OK) == 0)
    {
        printf("Write permission is Accessible...\n");
    }
    else
    {
        perror("Write Permission is not Accessible...\n");
    }

    close(fd);
    
    return 0;
}