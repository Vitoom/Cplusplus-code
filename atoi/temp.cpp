#include <cstdio>

int main(){
    unsigned int iMax1=(1<<(8*sizeof(int)-1)),iMax2=~(1<<8*sizeof(int)-1);
    printf("%x,%x", iMax1, iMax2);
    return 0;
}
