//***factorial Trailing zeros And digits At any base ***
#include<bits/stdc++.h>
using namespace std;
#define S 1001000
int mark[S+6];
vector<long long int > prime,Prime_factors,v;
int sieve()
{
    int x,y;
    for(x=0; x<S; x++)
        mark[x]=0;
    for(x=4; x<S; x=x+2)
        mark[x]=1;
    for(x=3; x*x<=S; x=x+2)
    {
        if(mark[x]==0)
        {
            for(y=x*x; y<S; y=y+x+x)
                mark[y]=1;
        }
    }
    for(x=2; x<S; x++)
        if(mark[x]==0)
            prime.push_back(x);
}
int trailing_zeros(long long int number,int base)
{
    Prime_factors.clear();v.clear();
    long long int x,y=0,count=0;
    while(prime[y]*prime[y]<=base)
    {
        count=0;
        if(base%prime[y]==0)
        {
            Prime_factors.push_back(prime[y]);
            while(base%prime[y]==0)
            {
                base=base/prime[y];
                count++;
            }
            v.push_back(count);
        }
        y++;
    }
    if(base>1)
        {
            Prime_factors.push_back(base);
            v.push_back(1);
        }
    long long int ans1=-1, ans=0,d,e=0,f;
    while(e<v.size())
    {
        d=Prime_factors[e];
        ans=0;
        while(d<=number)
        {
            ans=ans+(number/d);
            d=d*Prime_factors[e];
        }
        ans=ans/v[e];
        if(ans<ans1||ans1==-1)
            ans1=ans;
        e++;
    }
    return ans1;
}
int digit(long long int number,long long int base)
{

    long long int x,y;
    double z;
    for(x=1; x<=number; x++)
    {
        z=z+log(x)/log(base);
    }
    z=floor(z)+1;
    return z;
}
int main()
{
    sieve();
    cout<<digit(1654,10)<<endl;// output: 4608
    cout<<trailing_zeros(1654,10)<<endl; // Output: 411

}
