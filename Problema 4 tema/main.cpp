#include <iostream>

using namespace std;
int n;
struct pacient
{
    int timp;
    char nume[30];
};
pacient a[1000],aux;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].timp;
        cin>>a[i].nume;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j>1 && a[j].timp<a[j-1].timp;--j)
        {
            aux=a[j];
            a[j]=a[j-1];
            a[j-1]=aux;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<a[i].nume<<" "<<a[i].timp<<endl;
    }
    return 0;
}
