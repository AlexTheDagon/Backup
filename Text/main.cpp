#include <iostream>

#include <fstream>
using namespace std;
ifstream in("text.in");
ofstream out("text.out");
long long sum,k,j;
char c;
int main()
{
    while(in.get(c))
    {
        if(isalpha(c))++j;
        else
        {
            if(j!=0)
            {
                sum+=j;
                ++k;
            }
            j=0;
        }
    }
    if(j!=0)
    {
        k++;
        sum+=j;
    }
    if(k!=0)out<<sum/k;
    else out<<"0";
    return 0;
}

