#include <iostream>
#include <fstream>
using namespace std;
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("br.in");
ofstream out("br.out");
int n,t,s,k,sp[30005];
int main()
{
    in>>n>>t;
    for(int i=1;i<=n;++i)
    {

        in>>sp[i];
        sp[i+n]=sp[i];
    }
    for(int i=1;i<=2*n;++i)sp[i]+=sp[i-1];
    for(int i=1;i<=t;++i)
    {
        in>>k>>s;
        int beri=0;
        for(int j=k;j<k+n && sp[j]-sp[k-1]<=s;++j)++beri;
        out<<beri<<'\n';
    }
    return 0;
}
