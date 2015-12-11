#include <sys/types.h>
#include <sys/dir.h>
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;
void files_in_dir(char* dir)
{
	DIR *dirptr=opendir(dir);
	struct dirent *entry = readdir(dirptr);
	struct stat statbuf;
	while (entry = readdir(dirptr)) 
	{
		if (strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
			continue;
		else
		{
			char temp[200];
			strcpy(temp,dir);
			strcat(temp,"/");
			strcat(temp,entry->d_name);
			if(opendir(temp))
			{
				cout<<temp<<"\t\tdir"<<endl;;
				files_in_dir(temp);
			}
			else
			{
				//stat(entry->d_name, &statbuf);
				cout<<temp<<"\t\tfile"<<endl;
			}
		}	
	}
}

int main(int argc, char* argv[])
{
	files_in_dir(argv[1]);
	return 0;
}
