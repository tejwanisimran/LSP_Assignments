// Description : List All Files from the Directories
/*               Accept Directory Name
                 Use opendir/readdir to print only names.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include <sys/types.h>


#define SIZE_DIR 50
int main()
{
    char fName[SIZE_DIR];
    int iRet = 0;

    DIR * dp = NULL;
    struct dirent * dr;

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
        if((strcmp(dr->d_name , ".") == 0) || (strcmp(dr->d_name , "..") == 0))
        {
            continue;
        }

        printf("%s\n",dr->d_name);
    }

    closedir(dp);

    return 0;
}