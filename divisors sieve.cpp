*** Divisors Sieve Implementation ***
// Time complexity: N*LogN*LogN
#include<bits/stdc++.h>
using namespace std;
#define rng 1000000
vector<int> divi[rng];
int divisors_sieve()
{
    int i,j;
    for(i=1; i<=rng; i++)
    {
        for(j=i; j<=rng; j=j+i)
        {
            divi[j].push_back(i);
        }
    }

}
int main()
{
    divisors_sieve();
    for(int i=0; i<divi[12].size(); i++)
    {
        cout<<divi[12][i]<<" ";
    }

    return 0;
}
//Output: 1 2 3 4 6 12
