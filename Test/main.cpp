#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
char a[200],b[200];
char *c;
int main()
{
    cin.getline(a,100);
    cout<<a<<endl<<b<<endl;
    strncpy(a+2,a+4,2);
    cout<<a;
    return 0;
}
