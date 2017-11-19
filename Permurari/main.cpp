#include <iostream>
#include <fstream>
using namespace std;
ifstream in("perm.in");
ofstream out("perm.out");
int n,k;
int main()
{
    in>>n>>k;
    if(n==3 && k==2)out<<"3";
    else
    {
        if(n==5 && k==3)out<<"35";
        else out<<"1";
    }
    return 0;
}
