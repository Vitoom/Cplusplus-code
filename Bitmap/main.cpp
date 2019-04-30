#include <iostream>

class Bitmap {
public:
    Bitmap(){
        a = new int[1+N/BITWORD];
    }

    ~Bitmap(){
        delete []a;
    }

    void set(int i) {
        a[i>>SHIFT] |= 1<<(i & MASK);
    }

    void clr(int i) {
        a[i>>SHIFT] &= ~(1<<(i & MASK));
    }

    int test(int i) {
        return a[i>>SHIFT]>>(i & MASK) & 1;
    }

private:
    const unsigned int BITWORD = 32;
    const unsigned int SHIFT = 5;
    const unsigned int MASK = 0x1F;
    const unsigned int N = 5;
    int* a;
};

int main() {
    Bitmap a;
    a.set(5);
    std::cout << a.test(5) << std::endl;
    return 0;
}