#include <iostream>
#include <fstream>
using namespace std;
ifstream in("fotbal.in");
ofstream out("fotbal.out");
int a,b,ga,gb,m[6][6],cn,n,pozs,pozf;
pair< pair<int,int> , pair<int,int> > x[6];
int main()
{
    in>>n;
    if(n%2==0)cn=n-1;
    for(int i=1;i<=cn;++i)
    {
        in>>a>>b>>ga>>gb;
        x[a].second.first+=ga;
        x[a].second.second+=gb;
        x[b].second.first+=gb;
        x[b].second.second+=ga;
        if(ga>gb)
        {
            x[a].first.first+=3;
            m[a][b]=a;
        }
        else
        {
            if(ga==gb)
            {
                x[a].first.first++;
                x[b].first.first++;
                m[a][b]=1;
            }
            else
            {
                x[b].first.first+=3;
                m[a][b]=b;
            }
        }
    }
    for(int i=1;i<=n;++i)x[i].first.second=x[i].second.first-x[i].second.second;
    for(int i=1;i<=n;++i)
    {
        pozs=1;
        pozf=n;
        for(int j=1;j<=n;++j)
        {
            if(j!=i)
            {
                if(x[i].first.first>x[j].first.first)pozf--;
                else
                {
                    if(x[i].first.first<x[j].first.first)pozs++;
                    else
                    {
                        if(m[i][j]==i)pozf--;
                        else
                        {
                            if(m[i][j]==j)pozs++;
                            else
                            {
                                if(x[i].first.second>x[j].first.second)pozf--;
                                else
                                {
                                    if(x[i].first.second<x[j].first.second)pozs++;
                                    else
                                    {
                                        if(x[i].second.first>x[j].second.first)pozf--;
                                        else
                                        {
                                            if(x[i].second.first<x[j].second.first)pozs++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        out<<pozs<<" "<<pozf<<'\n';
    }
    return 0;
}
