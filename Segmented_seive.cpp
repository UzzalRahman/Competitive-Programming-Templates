//*** Segmented Sieve implementation ***
#define S 10000000
bool mark[S+7];
#include<bits/stdc++.h>
using namespace std;
vector< int >prime,segment;
bool sieve()
{
    int i,j;
    for( i=4; i<S; i+=2)
        mark[i]=1;
    for(i=3; i*i<=S; i+=2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<S; j+=i+i)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<S; i+=2)
    {
        if(mark[i]==0)
        {
            prime.push_back(i);
        }
    }
}

int segment_sieve(long long int l, long long int u)
{
    long long int root,start,si,i,j,count=0;
    root=sqrt(u)+1;
    segment.clear();
    for(i=l; i<=u; i++)
        segment.push_back(i);

    if(l==1)
        count++;
    for(i=0; prime[i]<=root; i++)
    {
        si=prime[i];
        start=si*si;
        if(start<l)
        {
            start=((l+si-1)/si)*si;
        }
        for(j=start; j<=u; j+=si)
        {
            if(segment[j-l]!=0)
            {
                segment[j-l]=0;
                count++;
            }
        }

    }
    int total_number=(u-l)+1;
    return total_number-count;
}
int main()
{
    sieve();
    cout<<segment_sieve(10000000,10001000)<<endl; //Output: 61
}
