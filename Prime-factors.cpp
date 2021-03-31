//*** Prime Factors ***
#include<bits/stdc++.h>
using namespace std;
#define rng 10000000
vector<int> prime_factors;
int mark[rng+6],prime[rng];
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
int prime_factor(int P_F_Number)
{
    int i;
    i=0;
    while(prime[i]*prime[i]<=P_F_Number)
    {
        if(P_F_Number%prime[i]==0)
        {
            while(P_F_Number%prime[i]==0)
            {
                P_F_Number=P_F_Number/prime[i];
                prime_factors.push_back(prime[i]);
            }
        }
        i++;
    }
    if(P_F_Number>1)
    {
        prime_factors.push_back(P_F_Number);
    }
    return prime_factors.size();
}
int main()
{
    sieve();
    cout<<prime_factor(12)<<endl;//Output: 3
}
