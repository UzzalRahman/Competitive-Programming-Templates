*** Bitwise Operation ***
int Set(int n,int pos)
{
    return n=n|(1<<pos);
}
int Reset(int n,int pos)
{
    return n=n&~(1<<pos);
}
bool Check(int n,int pos)
{
    return (bool)(n=n&(1<<pos));
}
