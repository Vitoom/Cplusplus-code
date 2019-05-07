// linux c 库函数实现
#include <string>

long atol(const char *nptr) {
    int c;
    long total;
    int sign;

    while(isspace((int)(unsigned char)*nptr))
        ++nptr;

    c = (int)(unsigned char)*nptr++;
    sign = c;
    if(c=='-' || c=='+')
        c = (int)(unsigned char)*nptr++;

    while(isdigit(c)) {
        total = 10 * total + (c - '0');
        c = (int)(unsigned char)*nptr++;
    }

    if(sign=='-')
        return -total;
    else
        return total;
}

int atoi(
        const char *nptr
        )
{
    return (int)atol(nptr);
}

int main(int args, char* argv[]){
    return 0;
}
