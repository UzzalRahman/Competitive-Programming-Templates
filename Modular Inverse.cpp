//*** Modular Inverse ***
// Time complexity O(logM)
#include<bits/stdc++.h>
using namespace std;
// Given number and Mod must be co-prime
int modInverse(int num, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (num > 1)
    {
        int q = num / m;
        int t = m;
        m = num % m, num = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}
//Iterative methods : Time Complexity O(m)
int modInverse_2(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
int main()
{
        int mod=11;
    long long int x=modInverse(3,mod);
    cout<<x<<endl;//Output: 4
}
