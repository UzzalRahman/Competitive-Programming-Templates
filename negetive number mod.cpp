*** Mod of Negative Number ***
long long int neg_num_mod(long long int num,long long int mod)
{
     long long int result = mod - (abs(num) % mod);
     return result;
}
