#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include<bits/stdc++.h>

using namespace std;

void print_cont_of_dir(char path[])
{
    DIR *dir = opendir(path);
    struct dirent *dp;
    struct stat statbuf;
    for (dp=readdir(dir); dp != NULL ; dp=readdir(dir)){
        stat(dp->d_name, &statbuf);
        //cout<<"-------------------------------------------------------------------"<<endl;
        printf("File name              :- %s ", dp->d_name);
        printf("              %s\n", S_ISDIR(statbuf.st_mode)?"DIRECTORY":"FILE");
        if(S_ISDIR(statbuf.st_mode) && dp->d_name[0]!='.')
        {
            strcat(path,"/");
            strcat(path,dp->d_name);
            cout<<"*************************"<<endl;
            cout<<"CONTENTS OF DIRECTORY "<<path<<endl;
            print_cont_of_dir(path);   
            cout<<"*************************"<<endl;
        }
    }
   
}

int main()
{
char dirpath[256];
gets(dirpath);
print_cont_of_dir(dirpath);
cout<<"-------------------------------------------------------------------"<<endl;
return 0;
}
