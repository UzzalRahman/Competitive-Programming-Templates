//*** nCr % M Using Lucas Theorem ***
// N and R must be less than M
//Time complexity (M^2(logpM))
#include<bits/stdc++.h>
using namespace std;
int DP(int n, int r, int M)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1; // Top row of Pascal Triangle
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%M;
    }
    return C[r];
}
// Lucas Theorem based function that returns nCr % M
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int NcR(int n, int r, int M)
{
    // Base case
    if (r==0)
        return 1;
    // Compute last digits of n and r in base p
    int ni = n%M, ri = r%M;
    // Compute result for last digits computed above, and
    // for remaining digits.  Multiply the two results and
    // compute the result of multiplication in modulo p.
    return (NcR(n/M, r/M, M) * // Last digits of n and r
            DP(ni, ri, M)) % M;  // Remaining digits
}
int main()
{
    int n = 1000, r = 900, M = 13;
    cout << "Value of nCr % M is " << NcR(n, r, M);// Output: 8
    return 0;
}
