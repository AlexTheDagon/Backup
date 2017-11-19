#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int m,ind;

int main()
{
    cin>>m;
    srand(time(0));
    for(int n=2;n<=m+1;++n)
    {
        ind=rand()%n;
        if(ind==0)ind=n/2;
        for(int i=1;i<n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                cout<<"? "<<i<<" "<<j<<'\n';
            }
        }
        cout<<"! "<<ind<<" "<<ind+1<<'\n';
    }
    return 0;
}
/// i,j
/// i-negru
/// j-alb
