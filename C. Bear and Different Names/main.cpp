#include <iostream>

using namespace std;
string s;
int n,k,cod[100],maxx,sem;
int main()
{
    cin>>n>>k;
    cin>>s;
    if(s=="YES")
    {
        for(int i=1;i<=k;++i)cod[i]=i;
    }
    else
    {
        for(int i=2;i<=k;++i)cod[i]=i;
        cod[1]=2;
    }
    for(int teste=2;teste<=n-k+1;++teste)
    {
        cin>>s;
        maxx=0;
        if(s=="YES")
        {
            for(int i=teste-1;i<teste+k-1;++i)
            {
                maxx=max(maxx,cod[i]);
            }
            cod[teste+k-1]=maxx+1;
        }
        else
        {
            cod[teste+k-1]=cod[teste];
        }
    }
    for(int i=1;i<=n;++i)
    {
        sem=1;
        for(int j=0;j<=7;++j)
        {
            if(cod[i] & (1<<j))
            {
                if(sem==0)cout<<(char)('a'+j);
                else
                {
                    cout<<(char)('A'+j);
                    sem=0;
                }
            }
        }
        cout<<" ";
    }
    return 0;
}
