#include <iostream>
#include <fstream>
using namespace std;
ifstream in("placare.in");
ofstream out("placare.out");
int fr[305],val[305],n,m,x;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(!fr[j])
            {
                in>>x;
                if(x==0)--j;
                else
                {
                    if(x>0)
                    {
                        for(int k=1;k<=x;++k)
                        {
                            out<<x<<" ";
                            ++j;
                        }
                        --j;
                    }
                    else
                    {
                        out<<-x<<" ";
                        fr[j]=-x-1;
                        val[j]=-x;
                    }
                }
            }
            else
            {
                out<<val[j]<<" ";
                --fr[j];
            }
        }
        out<<'\n';
    }
    return 0;
}
