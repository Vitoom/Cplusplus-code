#include <cstdio>
#include <string>

long long StrToIntCore(const char* digit, bool minus);

enum Status {Valid = 0, Invalid};
int g_nStatus = Invalid;

int StrToInt(const char* str)
{
    g_nStatus = Invalid;
    long long num = 0;

    if(str != NULL && *str != '\0')
    {
        bool minus = false;
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            str++;
            minus = true;
        }

        if(*str != '\0')
        {
            num = StrToIntCore(str, minus);
        }
    }
    return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;
    int flag = minus?-2:1;

    while(*digit != '\0')
    {
        if(*digit >= '0' && *digit <= '9')
        {
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7fffffff)
                || (minus && num > 0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }

    if(*digit == '\0')
    {
        g_nStatus = Valid;
    }

    return num;
}

void Test(const char* str)
{
    int result = StrToInt(str);
    if(result==0 && g_nStatus==Invalid)
        printf("The input %s is Invalid.\n", str);
    else
        printf("number for %s is: %d.\n", str, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);

    Test("");

    Test("+123");

    Test("-123");

    Test("+0");

    Test("-0");

    return 0;
}
