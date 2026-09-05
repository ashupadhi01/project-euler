#include <iostream>
#include <vector>
using namespace std;

bool is_prime(long long int n) {
    
    if(n == 1) {
        return false;
    }

    for(long long int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

void largest_prime_factor(long long int n) {
    vector <int> factors;
   
    for(int i = 2; i <= n; i++) {
        if(is_prime(i) && (n % i == 0)) {
            n /= i;
            factors.push_back(i);
            i--;
        }
       
    }

    cout << factors[factors.size() - 1] << '\n';
    return;
}

int main(void) {
    long long int n = 600851475143;
    largest_prime_factor(n);
    return 0;
}
