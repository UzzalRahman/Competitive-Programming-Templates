//***  Phi ***
#include <bits/stdc++.h>
using namespace std;
#define rng 10000100
vector<long long int> prime_factors;
int mark[rng+6],prime[rng];
void sieve()
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
long long int prime_factor(long long int P_F_Number)
{
    long long int i;
    i=0;
    while(prime[i]*prime[i]<=P_F_Number)
    {
        if(P_F_Number%prime[i]==0)
        {
            prime_factors.push_back(prime[i]);
            while(P_F_Number%prime[i]==0)
            {
                P_F_Number=P_F_Number/prime[i];
            }
        }
        i++;
    }
    if(P_F_Number>1)
    {
        prime_factors.push_back(P_F_Number);
    }
}
long long int Phi(long long int num)
{
    prime_factors.clear();
    prime_factor(num);
    long long int phi=num;
    for(int i=0;i<prime_factors.size();i++)
    {
        phi=(phi*(prime_factors[i]-1))/prime_factors[i];//equation: num*(1-(1/prime_factor[i])
    }
    if(num==1)
    return 0;
    return phi;
}
int main()
{
    sieve();
    cout<<Phi(1254)<<endl;//Output: 360
    return 0;
}
