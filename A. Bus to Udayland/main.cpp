#include <iostream>

using namespace std;
char c[1001][6];
int n,sem,contor;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=5;++j)
        {
            cin>>c[i][j];
        }
        if(sem==0)
        {
            if(c[i][1]=='O' && c[i][2]=='O')
            {
                c[i][1]='+';
                c[i][2]='+';
                sem=1;
            }
            else
            {
                if(c[i][4]=='O' && c[i][5]=='O')
                {
                    c[i][4]='+';
                    c[i][5]='+';
                    sem=1;
                }
            }
        }
    }
    if(sem==1)
    {
        cout<<"YES"<<'\n';
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=5;++j)cout<<c[i][j];
            cout<<'\n';
        }
    }
    else cout<<"NO";
    return 0;
}
