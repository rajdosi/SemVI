#include<stdio.h>
#include <pwd.h>
#include <grp.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Not Enough Arguments");
        return 0;
    }
   
    struct stat s;
    
    int prot,temp[5],i=0;
    char perm[6];
    if(stat(argv[1],&s)<0)
    {
        return 0;
    };

    printf("\n------------Information About %s:-------------------\n",argv[1]);
    printf("\nFile Name:%s",argv[1]);
    printf("\nFile Size: %d bytes",s.st_size);   
    printf("\nDevice ID: %d ",s.st_rdev);
    printf("\nInode Number: %d ",s.st_ino);
    printf("\nID of device Containing File %s : %d ",argv[1],s.st_dev);
    printf("\nUser ID of Owner: %d ",s.st_uid);
    printf("\nGroup ID of Owner: %d ",s.st_gid);
    printf("\nBlock Size of File System I/O: %d ",s.st_blksize);
    printf("\nNumber of Blocks Allocated: %d ",s.st_blocks);
    printf("\nNumber of Hard Links: %d ",s.st_nlink);
    printf("\nI-node number:            %ld\n", (long) s.st_ino);
    printf("Link count:               %ld\n", (long) s.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",(long) s.st_uid, (long) s.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",(long) s.st_blksize);
    printf("File size:                %lld bytes\n",(long long) s.st_size);
    printf("Blocks allocated:         %lld\n",(long long) s.st_blocks);
    printf("Last status change:       %s", ctime(&s.st_ctime));
    printf("Last file access:         %s", ctime(&s.st_atime));
    printf("Last file modification:   %s", ctime(&s.st_mtime));

	struct passwd *pw = getpwuid(s.st_uid);
	struct group  *gr = getgrgid(s.st_gid);

    sprintf(perm,"%o",s.st_mode);
    printf("\nThe device id is:%c%c%c",perm[0],perm[1],perm[2]);
    printf("\nPermissions: %c%c%c\n",perm[3],perm[4],perm[5]);
    printf("\nUser:%s Group:%s",pw->pw_name,gr->gr_name);
    printf("\n");   
return 0;
}
