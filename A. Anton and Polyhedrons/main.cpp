#include <iostream>

using namespace std;
string s;
int sum,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        if(s=="Tetrahedron")sum+=4;
        if(s=="Cube")sum+=6;
        if(s=="Octahedron")sum+=8;
        if(s=="Dodecahedron")sum+=12;
        if(s=="Icosahedron")sum+=20;
    }
    cout<<sum;
    return 0;
}
