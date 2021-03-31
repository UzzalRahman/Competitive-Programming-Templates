*** Substring: Check If pattern has the key or not ***
int main()
{
    char s[100005], *p;
    cin >> s;
    if ((p = strstr(s, "AB")) and strstr(p + 2, "BA")) cout << "YES" << endl;
    else if ((p = strstr(s, "BA")) and strstr(p + 2, "AB")) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
/*Return Value: This function returns a pointer points to the first character of the found s2 in s1 otherwise a null pointer if
s2 is not present in s1. If s2 points to an empty string, s1 is returned.*/
