*** Int to String and Vice versa ***
string int_to_str(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

int str_to_int(string str)
{
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}
