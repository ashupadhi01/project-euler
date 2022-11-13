#include <iostream>
#include <cmath>

using namespace std;

int no_of_digits(long long int x) {
    int count = 0;
    
    while(x > 0) {
        x /= 10;
        count++;
    }

    return count;
}

bool is_prime(long long int x) {
    if(x == 0 || x == 1) return false;
    else for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
    return true;
}

bool is_truncatable(long long int x) {
    long long int temp = x, k = pow(10, (no_of_digits(x) - 1));
    bool flag_1 = true, flag_2 = true;

    while(temp > 0) {
        if(!is_prime(temp)) {
            flag_1 = false;
            break;
        }
        temp /= 10;
    }

    temp = x;

    while(k > 9) {

        if(!is_prime(temp % k)) {
            flag_2 = false;
            break;
        }

        k /= 10;
    }

    if(flag_1 && flag_2) return true;
    else return false;
}

int main(void) {
    int count = 0, sum = 0;

    for(int i = 10; i > 0; i++) {
        
        if(is_truncatable(i)) {
            sum += i;
            count++;
            cout << i << endl;
        }
        
        if(count == 11) break;
    }

    cout << "sum :: " << sum << endl;

    return 0;
}
