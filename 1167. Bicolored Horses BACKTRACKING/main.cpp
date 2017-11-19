#include <iostream>

using namespace std;
int n,k,a[501],coef=100000000,i,j,cop;
pair <int,int > c[501];
void back(int x,int graj)
{
    if(graj<=k)
    {
        int c0=0,c1=0;
        for(int i=x;i<=n;++i)
        {
            if(a[i]==1)c1++;
            else c0++;
            cop+=c1*c0;
            back(i+1,graj+1);
            cop-=c1*c0;

        }

    }
    else
    {
        if(x>n)
        {
            cout<<cop<<" "<<coef<<" "<<x<<endl;
            coef=min(coef,cop);
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int u=1;u<=n;++u)cin>>a[i];
    back(1,1);
    cout<<coef;
    return 0;
}
