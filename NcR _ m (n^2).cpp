//***  nCr % M ***
// Time complexity O(N*R)
#include<bits/stdc++.h>
using namespace std;

int NcR(int n, int r, int M)
{
    int C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;


    for (int i = 1; i <= n; i++)
    {

        for (int j = min(i, r); j > 0; j--)

            C[j] = (C[j] + C[j-1])%M;
    }
    return C[r];
}
int main()
{


    cout<<NcR(10,2,13)<<endl;// Output: 6
}
