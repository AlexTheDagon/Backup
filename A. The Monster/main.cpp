#include <iostream>

using namespace std;
int a,b,c,d,dif;
int main()
{
    cin>>a>>b>>c>>d;
    swap(a,b);
    swap(c,d);

        if(a==c)cout<<a;
        else
        {
            dif=a-c;
            if(a<c)a+=b;
            else c+=d;
            while(a<=1000000 && c<=1000000 && a!=c)
            {
                if(a<c)a+=b;
                else c+=d;
            }
            if(a==c)cout<<a;
            else cout<<"-1";
        }

    return 0;
}
