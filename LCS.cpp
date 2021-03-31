//*** LCS: Longest Common Subsequence ***
//Time Complexity: O(mn)
#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];
string s3;
int LCS(string s,string s1)
{
    int i,j,l1,l2;
    l1=s.length();
    l2=s1.length();
    for(i=0; i<l1; i++)
        arr[0][i]=0;
    for(i=0; i<l1; i++)
        arr[i][0]=0;
    for(i=1; i<=l2; i++)
    {
        for(j=1; j<=l1; j++)
        {
            if(s[j-1]==s1[i-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    for(i=l2; i>0; i--)
    {
        for(j=l1; j>0; j--)
        {
            if(arr[i][j]==arr[i][j-1])
                {
                    continue;
                }
            else if(arr[i][j]==arr[i-1][j])
                {
                    i--,j++;
                }
            else if(arr[i-1][j-1]<arr[i][j])
            {
                s3+=s1[i-1];
                i=i-1;
            }
        }
    }
    reverse(s3.begin(),s3.end());
    return arr[l2][l1];

}
int main()
{
    int a,b,c,d,e,f,g,x,y,z;
    string s,s1;
    cin>>s>>s1;
    cout<<LCS(s,s1)<<endl;
    reverse(s3.begin(),s3.end());
    cout<<s3<<endl;
    return 0;
}
/*Input:
    AGGTAB
    GXTXAYB
Output:
    4
    BATG
*/
