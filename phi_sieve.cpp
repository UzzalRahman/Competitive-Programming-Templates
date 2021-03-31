//*** Phi Sieve ***
#include<bits/stdc++.h>
using namespace std;
#define rng 5100000
int mark[rng+6],prime[rng],phi[rng+6];
int sieve()
{
    int i,j;
    for(i=0; i<rng; i++)
        mark[i]=0;
    mark[0]=mark[1]=1;
    for(i=4; i<rng; i=i+2)
        mark[i]=1;
    for(i=3; i*i<=rng; i=i+2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<=rng; j=j+i+i)
                mark[j]=1;
        }
    }
    j=0;
    for(i=2; i<rng; i++)
        if(mark[i]==0)
            prime[j++]=i;

}
int phi_sieve()
{
    int i,j;
    for(i=1;i<rng;i++)
        phi[i]=i;
    for(i=2;i<rng;i++)
    {
        if(mark[i]==0)
        {
            for(j=i;j<rng;j=j+i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
int main()
{
    sieve();
    phi_sieve();
    cout<<phi[12]<<endl;//Output: 4

    return 0;
}
