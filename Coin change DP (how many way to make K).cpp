#include<bits/stdc++.h>
using namespace std;
int value[110];
int Quan[110];
int DP[55][1100];
int K,n,mod=100000007;
int dp(int coin,int money)
{
    int temp1=0,temp2=0;
    if(money==K)
        return 1;
    if(coin>n)
        return 0;
    if(DP[coin][money]!=-1)
        return DP[coin][money];
        temp2+=dp(coin+1,money)%mod;
    for(int i=1; i<=Quan[coin]; i++)
    {

        if(money+(value[coin]*i)<=K)
            {
                temp2+=dp(coin+1,money+(value[coin]*i))%mod;
            }
    }
    return DP[coin][money]=temp2%mod;
}
int main()
{
    int a,b,c,d,x,y,z,m,t,cas=0;
    cin>>t;
    while(t>0)
    {
        cin>>n>>K;
        for(x=0; x<54; x++)
        {
            for(y=0; y<1010; y++)
                DP[x][y]=-1;
        }
        for(x=1; x<=n; x++)
        {
            cin>>value[x];
        }
        for(x=1; x<=n; x++)
            cin>>Quan[x];
        cout<<"Case "<<++cas<<": "<<dp(1,0)<<endl;
        t--;
    }
    return 0;
}
/*Input:
    1
    5 1123
    1 2 3 5 7
    1000 1000 1000 1000 1000
Output:
    Case 1: 32874190
*/
