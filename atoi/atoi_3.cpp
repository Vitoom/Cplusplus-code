#include <cstdio>
#include <cstring>
typedef enum {VALID, INVALID} ResType;

ResType ret_stat = VALID;

bool isdigit(char ch)
{
    return '0'<=ch && ch<='9';
}

int StrToInt(const char *str)
{
    unsigned int ret=0, iMax=~(1<<(8*sizeof(int)-1));
    int sign;
    const char *p;

    if(!str || strlen(str)<=0){
        ret_stat = INVALID;
        return 0;
    }

    for(p=str; *p==' '; p++);

    sign = 1;
    if('+'==*p){
        p++;
    }else if('-' == *p){
        p++;
        sign = -1;
        iMax = ~iMax;
    }

    if(*p == '\0'){
        ret_stat = INVALID;
        return 0;
    }

    for(;*p!='\0';p++){
        if(isdigit(*p)){
            ret = ret*10 + (*p-'0');
            if(ret > iMax){
                ret_stat = INVALID;
                return 0;
            }
        }
        else{
            ret_stat = INVALID;
            return 0;
        }
    }

    return sign*ret;
}

void Test(const char* string)
{
    ret_stat = VALID;
    int result = StrToInt(string);
    if(ret_stat == INVALID)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);

    Test("");

    Test("123");

    Test("+123");

    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}
