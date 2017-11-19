#include<cstdio>
#include<bitset>
using namespace std;
int H,W,NT,i,j,n,I,J,N,c[4110],poz;
bitset<2110> v[2110];
int main()
{
    freopen("intersectii.in","r",stdin);
    freopen("intersectii.out","w",stdout);
    scanf("%d%d%d",&W,&H,&NT);
    for(i=1;i<W;i++)
        for(j=1;j<H;j++)
            if(!v[i][j])
            {
                n=i+j-1;
                for(I=i,J=j,N=n;I<W && J<H;I+=i,J+=j,N+=n)
                {
                    v[I][J]=1;
                    c[N]++;
					if(poz<N) poz=N;
                }
            }
	//for(i=1;i<=poz;++i) c[i]+=c[i-1];
    for(;NT;NT--)
    {
        scanf("%d",&i);
		if(i>poz) printf("0\n");
        else printf("%d\n",4*c[i]);
    }
    return 0;
}
