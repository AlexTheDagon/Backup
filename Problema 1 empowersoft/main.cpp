#include <iostream>
#include <fstream>
using namespace std;
ifstream in("artificii.in");
ofstream out("artificii.out");
int er[1000001],C1,C2,P,pr[80000],k;
int main()
{
    for(int i=2;i<=1000000;++i)
    {
        er[i]=1;
    }
    for(int i=2;i<=1000000;++i)
    {
        for(int j=i+i;j<=1000000;j=j+i)er[j]=0;
    }
    for(int i=1;i<=1000000;++i)
    {
        if(er[i]==1)
        {
            pr[k]=i;
            k++;
        }
    }
    for(int i=1;i<k;++i)
    {
        for(int j=pr[i]*2;j<=1000000;j=j+pr[i])er[i]++;
    }

    return 0;
}
