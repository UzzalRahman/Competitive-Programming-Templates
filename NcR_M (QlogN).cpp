//*** nCr % M Using Fermat's little theorem ***
// M must be prime and M<N
//Time Complexity O(Q*logN)
#include<bits/stdc++.h>
using namespace std;
#define rng 1000
int power(int x, int y, int M)
{
    int res = 1;
    x = x % M;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % M;
        y = y>>1;
        x = (x*x) % M;
    }
    return res;
}
int modInverse(int n, int M)
{
    return power(n, M-2, M);
}
int fact[rng+10],inv[rng+10];
int pre_calculate(int M)
{
    fact[0]=1;
    for(int i=1; i<=rng; i++)
    {
        fact[i] = fact[i-1]*i%M;
        inv[i]=modInverse(fact[i], M) % M;
    }

}
int NcR(int n, int r, int M)
{
    if (r==0)
        return 1;
    return (fact[n]* inv[r] *
            inv[n-r]) % M;
}
int main()
{

    int n = 10, r = 2, M = 13;
    pre_calculate(M);
    cout << "Value of nCr % M is "<< NcR(n, r, M);//Output: 6
    return 0;
}
