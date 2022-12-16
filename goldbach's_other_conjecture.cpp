#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int a) {
    for(int i = 2; i * i <= a; i++) if(a % i == 0) return false;
    return true;
}

bool is_goldbach(int a) {

    int temp;

    for(int i = a; i >= 2; i -= 2) {
        
        temp = a;

        if(is_prime(i)) {
            temp -= i;
            if(!(temp % 2 == 0)) break;
            temp /= 2;
            if(int(sqrt(temp)) * int(sqrt(temp)) == temp) return true;
        }

        else continue;
    }

    return false;
}

int main(void) {

    for(int i = 3; i > 0; i += 2) {
        if(!is_prime(i)) {
            if(!is_goldbach(i)) {
               cout << i << endl;
               break;
            }
        }
    }

    return 0;
}

/*
NOTE ::

is_prime function checks whether a number is prime in root n time.

is_goldbach function checks whether a number satisfys the conjecture or not.
This function first finds the nearest prime of the number, and then checks whether the difference of it and the original number is a perfect square or not. If it's not, then it finds the next nearest prime. This happens till the lowest prime i.e if for no prime perfect square exists, the function returns false.

main function consists of an infinte loop which sends all the composite-odd numbers to  the is_goldbach function. 

*/
