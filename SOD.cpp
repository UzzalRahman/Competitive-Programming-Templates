//*** SOD (sum of divisors) ***
//SOD=(((p1^e1+1)-1)/(p1-1))+(((p2^e2+1)-1)/(p2-1))+........
#include<bits/stdc++.h>
using namespace std;
#define rng 10000000
int mark[rng+6];
vector<int > prime;
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
int SOD(int number)
{
    int i=0,ans=1;
    while(prime[i]*prime[i]<=number)
    {
        int count1=1;
        if(number%prime[i]==0)
        {
            while(number%prime[i]==0)
            {
                number=number/prime[i];
                count1++;
            }
            ans=ans*((pow(prime[i],count1)-1)/(prime[i]-1));
        }
        i++;
    }
    if(ans==0)
        return number+1;
    if(number>1)
        ans=ans*((number*number-1)/(number-1));
    return ans;
}

int main()
{
    sieve();
    cout<<SOD(12)<<endl;// Output: 28
}
