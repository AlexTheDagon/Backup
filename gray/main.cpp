#include <iostream>
#include <vector>
#define pb push_back
#define pp pop_back
using namespace std;
vector<int> v;
int sem,viz[5000],n;
void back(int nr)
{
    if(v.size()==(1<<n))
    {
        for(auto i:v)
        {
            for(int j=0;j<n;++j)
            {
                if(i&(1<<j))cout<<"1";
                else cout<<"0";
            }
            cout<<'\n';
        }
        sem=1;
    }
    if(sem)return;
    for(int i=0;i<n;++i)
    {
        if(viz[nr^(1<<i)]==0)
        {
            v.pb(nr^(1<<i));
            viz[nr^(1<<i)]=1;
            back(nr^(1<<i));
            v.pp();
            viz[nr^(1<<i)]=0;
        }
    }
}
int main()
{
    cin>>n;
    v.pb(0);
    viz[0]=1;
    back(0);
    return 0;
}
