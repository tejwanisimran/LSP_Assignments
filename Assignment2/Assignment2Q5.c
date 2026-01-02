// Description : Find Largest File in the directory.
/*               Accept Diectory Name.
                 Find and print : 
                    largest file name .
                    its size in the bytes.
                 Consider only regular files.
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
    char largestFile[SIZE_DIR];
    int iRet = 0 ,maxSize = 0;

    DIR * dp = NULL;
    struct dirent * dr = NULL;

    struct stat sobj;

    memset(fName , '\0' , SIZE_DIR);
    memset(fullPath , '\0' , SIZE_PATH);
    memset(largestFile , '\0' , SIZE_DIR);

    printf("Enter the directory that you want to open : ");
    scanf("%s",fName);

    dp = opendir(fName);

    if(dp == NULL)
    {
        perror("Error :");
    }
    else
    {
        printf("Directory gets succcessfully opened\n");
    }

    while((dr = readdir(dp)) != NULL)
    {
        snprintf(fullPath, SIZE_PATH, "%s/%s", fName, dr->d_name);

        if(lstat(fullPath , &sobj) == 0)
        {
            if(S_ISREG(sobj.st_mode))
            {
                if(sobj.st_mode > maxSize)
                {
                    maxSize = sobj.st_mode;
                    strcpy(largestFile , dr->d_name);
                }
            }
            
        }
    }

    if(maxSize == 0)
    {
        printf("There are no regular files!!\n");
        return -1;
    }
    else
    {
        printf("Largest File in the directory is : %s\n",largestFile);
        printf("Size of the Largest File is : %d\n",maxSize);
    }

    closedir(dp);

    return 0;
}