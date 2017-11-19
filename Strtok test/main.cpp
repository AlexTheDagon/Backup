#include <iostream>
#include <string.h>
using namespace std;
char a[100],*s;
int main()
{
    cin.getline(a,90);
    s=strtok(a," ");
    while(s!=NULL)
    {
        cout<<s;
        s=strtok(NULL," ");
        cout<<endl;
    }
    return 0;
}
