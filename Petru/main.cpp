#include <iostream>

using namespace std;
int z,n;
int main()
{
    cin>>n;
    for(int i1=1;i1<=n;++i1)
        for(int i2=i1;i2<=n;++i2)
           for(int i3=i2;i3<=n;++i3)
                for(int i4=i3;i4<=n;i4++)z++;
    cout<<z;
    return 0;
}
