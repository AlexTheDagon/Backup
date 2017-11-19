#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char a[200];
char l;

int main()
{
    in.get(a,100);
    cin>>l;
    cout<<toupper(
                  l);
    return 0;
}
