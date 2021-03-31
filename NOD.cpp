//*** NOD (Number of divisors) ***
//NOD=(pow1+1)*(pow2+1)*(pown+1)
#include<bits/stdc++.h>
using namespace std;
#define rng 10000000
int mark[rng+6];
vector<int> prime;
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
            prime.push_back(i);
}
int NOD(long long int number)
{
    int i=0,count=1,count1=0;
    while(prime[i]*prime[i]<=number)
    {
        count1=1;
        if(number%prime[i]==0)
        {

            while(number%prime[i]==0)
            {
                count1++;
                number=number/prime[i];
            }
             count=count*count1;
        }
        i++;
    }
    if(number>1)
        count=count*2;
    return count;
}
int main()
{
    sieve();
    cout<<NOD(12)<<endl;// Output: 6
}

