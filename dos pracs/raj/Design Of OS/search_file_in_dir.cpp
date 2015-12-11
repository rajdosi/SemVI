//TO Search a file in a directory
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <unistd.h>
using namespace std;

void search (char* file, char* dir){
	DIR *dirptr=opendir(dir);
	struct dirent *entry = readdir(dirptr);
	while (entry != NULL) {
		if ((strcmp(entry->d_name, file) == 0)){
			cout<<"Found";
			return ; /* return success */
		}
		entry = readdir(dirptr);
	}
	cout<<"Not found";
	return ; /* return failure */
}

int main(int argc, char** argv){
        //mkdir("newdirt",0777);
        //rmdir("newdirt"); NOT DECLARED IN THIS SCOPE????
        //chmod("newdirt",0751);
	search(argv[1],argv[2]);
        return 0;
}

