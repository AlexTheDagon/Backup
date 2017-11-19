#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,c,t;
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        out<<a<<'\n';
    }
    return 0;
}
