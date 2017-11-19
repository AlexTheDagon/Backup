#include <iostream>

using namespace std;




int main()
{int a[10000],n,m,b[10000],apare1=1,d;
cin>>n>>m;

for(int i=0;i<n;i++)
{
    cin>>a[i];
}
for(int j=0;j<m;j++)
{
    cin>>b[j];
    for(int i=0;i<n;i++)
    {
        if(b[j]==a[i])
        {
            apare1=1;
            d=i-j;
        }
    }
}
for(int j=0;j<m;j++)
{
    if(b[j]!=a[i+d])
    {
        apare1=0;
    }
}
if(apare1=0)
{
    cout<<"nu!";
}
else(cout<<"da";)

    return 0;
}
