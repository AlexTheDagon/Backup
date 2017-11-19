#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sr.in");
ofstream out("sr.out");
string a,b;
int j;
int main()
{
    in>>a>>b;
    for(int i=0;i<a.size();++i)
    {
        if(a[i]==b[j])
        {
            ++j;
            out<<i+1<<" ";
        }
    }
    return 0;
}
