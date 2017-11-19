#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
float ipotenuza,l1,l2,x,y;
int cadran(int i,int j)
{
    if(i<=0)
    {
        if(j>0)return 0;
        return 1;
    }
    else
    {
        if(j<=0)return 2;

    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
