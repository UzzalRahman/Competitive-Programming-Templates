*** Factorial Factors ***
#include<bits/stdc++.h>
using namespace std;
//Total number of factors: (pow of 1st factor+1)*(pow of 2nd factor+1)*....
#define S 1000005
int mark[S+6];
vector<int >prime;
map<int ,int> count1;
void sieve()
{
    int x,y,z;
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
int factorial_factors(int number)
{
    int x,y=0,z;
    while(prime[y]<=number)
    {
        x=number;
        z=prime[y];
        int count=0;
        while(z<=number)
        {
            count=count+(number/z);
            z=z*prime[y];
        }
        count1[prime[y]]=count;
        y++;
    }

}
int main()
{
    sieve();
    int a,b,c,d,e,x,y,z;
    while(cin>>a)
    {
        factorial_factors(a);
        cout<<count1[2]<<endl;
        //Input:32 Output:31
        count1.clear();
    }
}
