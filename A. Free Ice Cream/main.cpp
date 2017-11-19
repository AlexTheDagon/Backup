#include <iostream>

using namespace std;
long long n,x,d,cplecati;
char c;
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;++i)
    {
        cin>>c>>d;
        if(c=='+')x+=d;
        else
        {
            if(d>x)cplecati++;
            else x-=d;
        }

    }
    cout<<x<<" "<<cplecati;
    return 0;
}
