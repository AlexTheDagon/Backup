#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumadiv.in");
ofstream out("sumadiv.out");
int sumd(int n,int d)
{
    if(d*d>n)return 0;
    if(d*d==n)return d;
    if(n%d!=0)return sumd(n,d+1);
    return d+n/d+sumd(n,d+1);
}
int main()
{
    int n,d;
    in>>n;
    out<<sumd(n,1);
    return 0;
}
