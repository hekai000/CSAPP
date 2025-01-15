#include <stdio.h>
void switch_eg(long x, long n, long *dest) {
    long val = x;
    switch (n) {
        case 0:
            val *= 13;
            break;
        case 2:
            val += 10;
            break;
        case 3:
            val +=11;
            break;
        case 4:
        case 6:
            val += 11;
            break;
        default:
            val = 0;
    }
    *dest = val;
}
long Q(long x) {
    long y = x * 2;
    return y;
}
long P(long x, long y) {
    long u = Q(y);  
    long v = Q(x);
    return u + v;
}

long rfact(long n) {
    long result;
    if (n<=1) {
        result = 1;
    }
    else {
        result = n * rfact(n-1);
    }
    return result;
}

int main() {
    rfact(3);
    return 0;
}