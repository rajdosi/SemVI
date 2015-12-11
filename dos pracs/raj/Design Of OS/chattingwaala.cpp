#include <unistd.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <iostream>

using namespace std;
int main()
{
	int f1[2], f2[2];
	pipe(f1);
	pipe(f2);
	int x = fork();
	char b[500], s[500];
	if(!x)
	{
		while(1)
		{
			read(f1[0], b, 500);
			cout<<"\nStranger read : "<<b;
			cout<<"\nStranger : ";
			cin>>s;
			write(f2[1], s, 500);
		}
	}
	else
	{
		while(1)
		{
			cout<<"\nYou : ";
			cin>>b;
			write(f1[1], b, 500);
			read(f2[0], s, 500);
			cout<<"\nYou read : "<<s;
		}
	}
}
