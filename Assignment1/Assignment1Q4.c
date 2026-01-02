// Description : Display Complete file information
/*               Accept Filename and display metadata using stat()
                 Size,inode,permissions,hardlinks,owner uid/gid,filetype,last access/modify time.
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include<time.h>

int main()
{
    char fName[50];
    int iRet = 0;

    struct stat sobj;

    memset(fName , '\0' , sizeof(fName));

    printf("Enter the file name that you want to open : ");
    scanf("%s",fName);

    if(stat(fName,&sobj) == -1)
    {
        perror("Error : ");
    }
    else
    {
        printf("Total size : %ld\n",sobj.st_size);
    
        printf("Block size : %ld\n",sobj.st_blksize);

        printf("Inode Number : %ld\n",sobj.st_ino);

        printf("HardLink Count : %ld\n",sobj.st_nlink);

        printf("User ID of owner : %d\n",sobj.st_uid);

        printf("Group ID of the owner: %d\n",sobj.st_gid);

        printf("File Type : %d\n",sobj.st_mode);

        printf("Time of last access : %ld\n",sobj.st_atime);

        printf("Time of lass modified : %ld\n",sobj.st_mtime);

    }

    

    return 0;
}