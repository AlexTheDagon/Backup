#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,a[100000],max1=-2100000000,max2;
int main()
{
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a[i];
        if(a[i]>=max1)
        {
            max2=max1;
            max1=a[i];
        }
        else{if(a[i]>max2)max2=a[i];}
    }
out<<max1<<" "<<max2;

    return 0;
}
