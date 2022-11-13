#include <iostream>
#include <vector>
using namespace std;

int factorial(int a) {
    if(a == 1 || a == 0) return 1;
    else return a * factorial(a - 1);
}

int main(void) {
    int temp, ans = 0; long long int sum;

    for(int i = 3; i <= 999999; i++) {
        sum = 0; temp = i; 
        
        while(temp > 0) {
            sum += factorial(temp % 10);
            temp /= 10;
        }

        if(sum == i) ans += i;
    }
    
    cout << ans << endl;

    return 0;
}
