*** KMP IMPLEMENTATION ***
//Time Complexity: Length of text
#include<bits/stdc++.h>
using namespace std;
#define rng 100
int prefix[rng];
void kmp_preprocess(string pattern)
{
    int len=pattern.length();
    for(int i=0;i<len+2;i++)
    prefix[i]=0;
    int j = 0;
    for(int i = 1; i < len; i++)
    {
        if(pattern[i]==pattern[j])
            prefix[i]=j+1,j++;
        else
        {
            while(j!=0)
            {
                j = prefix[j-1];
                if(pattern[i]==pattern[j])
                {
                    prefix[i] = j+1;
                    j++;
                    break;
                }
            }
        }
    }
}
bool kmp(string text, string pattern)
{
    kmp_preprocess(pattern);
    int len=text.length();
    int len1=pattern.length();
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(text[i]==pattern[j])
        {
            j++;
            if(j==len1)
            {
                printf("Found pattern at index %d\n",i);
            }
        }
        else
        {
            while(j!=0)
            {
                j = prefix[j-1];
                if(text[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return false;
}
int main()
{
    string txt = "ABABAB";
    string pattern = "AB";
    kmp(txt,pattern);
    //Output: index 1 3 5
}
// call kmp_preprocess to process the pattern than call kmp to find ans
