#include <iostream>
#include <vector>
using namespace std;
int n,leg,nrleg;
vector <int> v[10005],s;
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        cin>>leg;
        v[leg].push_back(i);
        v[i].push_back(leg);
    }
    nrleg=n-1;
    while(nrleg>1)
    {
        for(int i=1;i<=n;++i)
        {
            if(v[i].size()==1)
            {
                v[i].erase(v[i].begin());
                --nrleg;
            }
        }
        if(nrleg>0)
        {
            for(int i=1;i<=n;++i)
            {
                if(v[i].size()>0)
                {
                    for(int j=0;j<v[i].size();++j)
                    {
                        if(v[v[i][j]].size()==0)
                        {
                            v[i].erase(v[i].begin()+j);
                            --j;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(v[i].size())cout<<i<<" ";
    }
    return 0;
}
