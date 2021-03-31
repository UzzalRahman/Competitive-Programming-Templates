#include <bits/stdc++.h>
using namespace std;

int Set(int n,int pos)
{
    return n=n|(1<<pos);
}
int Reset(int n,int pos)
{
    return n=n&~(1<<pos);
}
bool Check(int n,int pos)
{
    return (bool)(n=n&(1<<pos));
}
long long int n;
long long int arr[22][22];
long long int dp[(1<<20)+2];
long long int DP(long long int i,long long int mask)
{
    long long int temp1=0;
    if(mask==((1<<n)-1))
    {
        return 1;
    }
    if(i>=n)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    for(int j=0;j<n;j++)
    {
        long long int temp=0;
        if(Check(mask,j)==0&&arr[i][j]==1)
        {
            temp=DP(i+1,Set(mask,j));
        }
        temp1+=temp;
    }
    return dp[mask]=temp1;
}
int main()
{

    long long int m, k, q, t, cnt = 0, sum = 0,ans=0, a, b, c,d,e,f,g,h,i,j,x, y, z,temp, temp1;
    string s, s1, s2, s3;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        long long int mask=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {
                scanf("%lld",&a);
                arr[i][j]=a;
            }
        }
        for(i=0;i<(1<<20)+1;i++)
        dp[i]=-1;
        a=DP(0,mask);
        printf("%lld\n",a);
    }


    return 0;
}
