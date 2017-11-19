#include <iostream>

using namespace std;
int ciur[1000],er[1000],ind_curent;
int n;
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i)ciur[i]=1;
    for(int i=2;i<=n;++i)
    {
        if(ciur[i]==1)
        {
            ind_curent=ind_curent+1;
            er[ind_curent]=i;
            for(int j=i+i;j<=n;j+=i)ciur[j]=0;
        }
    }
    for(int i=1;i<=ind_curent;++i)cout<<er[i]<<" ";
    return 0;
}
