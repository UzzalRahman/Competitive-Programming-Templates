*** Int to Binary conversion and Vice versa ***
string int_to_binary(long long int num)
{
    string s = bitset<32>(num).to_string();
    return s;
}
unsigned long binary_to_int(string s)
{
    unsigned long num =bitset<32>(s).to_ulong();
    return num;
}
