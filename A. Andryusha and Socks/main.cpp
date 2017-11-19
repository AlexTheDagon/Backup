#include <iostream>

using namespace std;
int fol[100005],s,maxx,n,x;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;++i)
    {
        cin>>x;
        if(fol[x]==1)--s;
        else
        {
            fol[x]=1;
            ++s;
            maxx=max(maxx,s);
        }
    }
    cout<<maxx;
    return 0;
}
