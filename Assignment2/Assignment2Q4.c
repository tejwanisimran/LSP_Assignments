// Description : List All Files from the Directories with its types
/*               Accept Diectory Name
                 Print each entery with its type : Regular/Directory/Link/FIFO/Socket/Char/Block
                 Use lstat() for accurate type.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>


#define SIZE_DIR 50
#define SIZE_PATH 100

int main()
{
    char fName[SIZE_DIR];
    char fullPath[SIZE_PATH];
    int iRet = 0;

    DIR * dp = NULL;
    struct dirent * dr = NULL;

    struct stat sobj;

    memset(fName , '\0' , SIZE_DIR);

    printf("Enter the directory that you want to open : ");
    scanf("%s",fName);

    dp = opendir(fName);

    if(dp == NULL)
    {
        perror("Error :");
    }
    else
    {
        printf("Directory gets succcessfully opened");
    }

    while((dr = readdir(dp)) != NULL)
    {
        snprintf(fullPath, SIZE_PATH, "%s/%s", fName, dr->d_name);

        if(lstat(fullPath , &sobj) == 0)
        {
            printf("File Name : %s\n",dr->d_name);

            if(S_ISBLK(sobj.st_mode))
            {
                printf("Block Device\n");
            }
            else if(S_ISCHR(sobj.st_mode))
            {
                printf("Character Device\n");
            }
            else if(S_ISDIR(sobj.st_mode))
            {
                printf("Directory file\n");
            }
            else if(S_ISREG(sobj.st_mode))
            {
                printf("Regular file\n");
            }
            else if(S_ISSOCK(sobj.st_mode))
            {
                printf("Socket file\n");
            }
            else if(S_ISFIFO(sobj.st_mode))
            {
                printf("Pipe file\n");
            }
            else if(S_ISLNK(sobj.st_mode))
            {
                printf("Symbolic Link\n");
            }
        }
    }
    closedir(dp);

    return 0;
}