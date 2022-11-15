#include <iostream>
#include <cmath>
using namespace std;

int length(long long int a) {
    int count = 0;

    while(a > 0) {
        a /= 10;
        count++;
    }
    
    return count;
}

bool is_prime(long long int n) {
    for(long long int i = 2; i * i <= n; i++) if(n % i == 0) return false;
    return true;
}

bool all_digit_odd(long long int a) {
    
    while(a > 0) {
        if((a % 10) % 2 == 0) return false;
        a /= 10;
    }

    return true;
}

bool is_circular_prime(long long int a) {
    
    if(!is_prime(a)) return false;
    long long int temp; 
    int count = 0;
    int l = length(a);
    int digit;

    while(count++ < l) {
        digit = a % 10;
        a /= 10;
        temp = digit * int(pow(10, l - 1));
        temp += a;
        a = temp;
        if(!is_prime(a)) return false;
    }

    return true;
}

int main(void) {

    int count = 1;

    for(int i = 3; i <= 1000000; i += 2) {
        if(all_digit_odd(i)) if(is_circular_prime(i)) count++;
        else continue;
    }

    cout << "Number of circular primes below one million are :: " << count << endl;

    return 0;
}

/*
The insight on this problem is that all even numbers can't be prime, and hence can't also be circular primes. So, checking starts from 3 and incerements by 2 everytime till 1 million.
Now, if an odd number has any even digit, it can't be circular prime as when that digit will come to the one's place it will not remain a prime.
So, before checking whether the number is prime, a check happens whether it contains any even digit, and if it doesn't contain any, then the check happens whether it is circular prime.

*/
