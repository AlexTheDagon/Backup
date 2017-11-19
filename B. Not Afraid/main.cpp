#include <iostream>
#include <stdlib.h>
#include <vector>
#define pb push_back
using namespace std;
int fr[100005],m,n,x,sem,k,semm;
vector <int> fol;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>k;
        for(int j=1;j<=k;++j)
        {
            cin>>x;
            fol.pb(50000+x);
            ++fr[50000+x];
            if(fr[50000+x] && fr[50000-x])sem=1;
        }
        for(auto j:fol)
        {
            fr[j]=0;
        }
        if(sem==0)semm=1;
        fol.clear();
    }
    if(semm)cout<<"YES";
    else cout<<"NO";
    return 0;
}
