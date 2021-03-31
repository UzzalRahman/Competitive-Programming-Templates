*** convert to decimal and vice versa ***
#include<bits/stdc++.h>
using namespace std;
int value(char ch)
{
    if(ch>='0'&&ch<='9')
        return ch-'0';
    else
        return ch-'A'+10;
}
int toDeci(string s, int base)
{
    int len = s.length();
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-1]*base + str[len-1]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (value(s[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
        num += value(s[i]) * power;
        power = power * base;
    }

    return num;
}
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;  // Initialize index of result

    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    // Reverse the result
    strev(res);
    return res;
}
int main()
{
    cout<<toDeci("ABCDEF0123456789",16)<<endl;// output: 591751049

    return 0;
}
