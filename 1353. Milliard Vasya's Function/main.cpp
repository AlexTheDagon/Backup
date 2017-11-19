#include <iostream>

using namespace std;
int sum,s,x;
int main()
{
    cin>>sum;
    if(sum!=1)
    {
        for(int i1=0;i1<=9;++i1)
        {
            for(int i2=0;i2<=9;++i2)
            {
                for(int i3=0;i3<=9;++i3)
                {
                    for(int i4=0;i4<=9;++i4)
                    {
                        for(int i5=0;i5<=9;++i5)
                        {
                            for(int i6=0;i6<=9;++i6)
                            {
                                for(int i7=0;i7<=9;++i7)
                                {
                                    s=sum-i1-i2-i3-i4-i5-i6-i7;
                                    if(s>9 && s<=18)x=x+(19-s);
                                    if(s<=9 && s>=0)x=x+s+1;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<x;
    }
    else cout<<"10";
    return 0;
}
