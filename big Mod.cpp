*** Big Mod ***
// Time complexity : LogN
#include<bits/stdc++.h>
using namespace std;
long long int mod=1000000007;
long long int big_mod(long long int num,long long int pow)
{
	if(pow==0) return 1;
	if(pow%2==0)
	{
		long long int ret=big_mod(num,pow/2);
		return (ret*ret)%mod;
	}
	else return (num*big_mod(num,pow-1))%mod;
}
int main()
{
    cout<<big_mod(2,3)<<endl;
}
