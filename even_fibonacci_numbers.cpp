#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {

    long long int sum = 0, k;
    
    for(int i = 0; i >= 0; i++) {
        k = fibonacci(i);
        if(k > 4000000) break;
        if(k % 2 == 0) sum += k;
    }

    cout << sum << endl;

    return 0;
}
/*
There is a function which computes the i-th fibonacci number recursively. An infinite loop runs in the main function which which keeps adding the i-th fibinnacci number to the variable *sum* if it is less than 4 million and divisible by two.
*/
