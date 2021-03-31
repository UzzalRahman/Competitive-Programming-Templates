//***Catalon Number***
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int catalon(int n)
{
    int temp=binomialCoeff(2*n,n);
    return temp/(n+1);
}
int main()
{
    for(int i=0;i<5;i++)
        cout<<catalon(i)<<endl;
}
//Output: 1 1 2 5 14
