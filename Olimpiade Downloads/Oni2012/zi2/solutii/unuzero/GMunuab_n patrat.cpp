// O(n^2)
#include <fstream>
using namespace std;

int mod=666013,a,b;
int u[1000100],z[1000100],n;
int main()
{
	ifstream in("unuzero.in");
	ofstream out("unuzero.out");
	
	in>>n>>a>>b;
	z[0]=1;
	z[1]=1;
	if(a==1) u[1]=1;
	for(int i=2;i<=n;++i)
	{
		z[i]=z[i-1]+u[i-1]; // daca punem 0
		z[i]%=mod;
		for(int j=i-b;j<=i-a;++j) // daca punem 1
		{
			if(j>=0)
			{
				u[i]+=z[j];
				u[i]%=mod;
			}
		}
	}
	
	out<<(z[n]+u[n]-1+(z[n]+u[n]-1<0?mod : 0))%mod<<'\n';
	out.close();
	return 0;
}
