#include <iostream>
#include <cstdio>
#include <cassert>

char* strcpy(char* des, const char*src) {
    assert((des!=NULL) && (src!=NULL));
    char* address = des;
    while((*des++ = *src++) != '\0')
        ;
    return address;
}

size_t strlen(const char* str) {
    assert(str != NULL);
    size_t len = 0;
    while((*str++) != NULL)
        ;
    return len;
}

char* strcat(char* des, const char* src) {
    assert((des!=NULL) && (src!=NULL));
    char* address = des;
    while(*des != '\0')
        ++des;
    while((*des++=*src++)!='\0')
        ;
    return address;
}

int strcmp(const char* s1, const char* s2) {
    assert((s1!=NULL) && (s2!=NULL));
    while(*s1==*s2){
        if(*s1=='\0')
            return 0;
        ++s1;
        ++s2;
    }
    return *s1-*s2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}