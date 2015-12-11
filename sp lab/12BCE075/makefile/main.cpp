#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    int n=0;
    cout << endl;
    cout<<"Enter a number:-";
    cin>>n;
    print_hello();
    cout <<endl<<"The factorial of "<<n<<" is "<<factorial(n) << endl;
    return 0;
}
