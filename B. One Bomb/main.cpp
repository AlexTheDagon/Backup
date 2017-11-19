#include <iostream>

using namespace std;
int n,m,C=-1,L=-1,linii,col,sem,stel;
char d[1000];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>d;
        sem=0;
        for(int j=0;j<m;++j)if(d[j]=='*')sem++;
        for(int j=0;j<m;++j)
        {
            if(d[j]=='*')
            {
                if(sem==1)
                {
                    if(j!=C)
                    {
                        C=j;
                        col++;
                    }
                }
                else
                {
                    if(i!=L)
                    {
                        L=i;
                        linii++;
                    }
                }

            }
        }
    }
    if(linii==0)L=0;
    if(col==0)C=0;
    if(linii<2 && col<2)cout<<"YES"<<'\n'<<L+1<<" "<<C+1;
    else cout<<"NO";
    return 0;
}
