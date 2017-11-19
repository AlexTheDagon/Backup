#include <iostream>
#include <fstream>

using namespace std;
ifstream in("date.in");
ofstream out("date.out");

int a[1000],m,n,b[1000][1000],S=0,x;

int main()
{
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a[i];
    }
    in>>m;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            in>>b[j][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        x=10000;
        for(int j=0;j<m;j++)
        {
            if(b[j][i]<x && b[j][i]!=-1)
            {
                x=b[j][i];
            }
        }
        S=S+a[i]*x;
    }
    out<<S;

    return 0;
}
