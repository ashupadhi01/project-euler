#include <iostream>
using namespace std;


int IsPrime(int a) {
    int flag = 1;

    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int func(int i, int j) {
    int a;
    int count = 0;

    for(int n = 0; n >= 0; n++) {
        a = n*n;
        a += i*n;
        a += j;

        if(a < 0) break;
        else if(IsPrime(a) == 0) break;
        printf("f(%d) = %d\n", n, a);
        count++;
    }

    return count;
}

int main(void) {
    int max = 0, a, b, count;
    int k = 0;
    for(int i = -999; i < 1000; i = i + 2) {
        for(int j = 1; j <= 1000; j = j + 2) {
            printf("\n");
            count = func(i, j);
            if(count > max) {
                max = count;
                a = i;
                b = j;
            }
            k++;
        }
    }

    printf("Number of consecutive primes: %d\n", max);
    printf("a = %d, b = %d\n", a, b);
    printf("Product of a*b is: %d\n", a*b);
    printf("We compute for %d equations.\n", k);



    return 0;
}
