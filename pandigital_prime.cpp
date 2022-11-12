#include <iostream>
using namespace std;

int length(long long int a) {
    int count = 0;
    while(a > 0) {
        a /= 10;
        count++;
    }

    return count;
}

bool is_pandigital(long long int a) {
	int l = length(a);
	long long int b; int chk;
    
	while(l > 0) {
	   chk = 1;
           b = a;
           while(b > 0) {
           	if(l == b % 10) {
           	    chk = 0;
           	    break;
           	}
           	
           	b /= 10;
         }
         
         if(chk) return false;
         l--;   
    }

  return true;
}


bool is_prime(long long int a) {
    for(int i = 2; i * i <= a; i++) if(a % i == 0) return false;
    return true;
}


int main(void) {

    for(long long int i = 7654321; i >= 0; i--) {
        if(is_pandigital(i)) if(is_prime(i)) {
            cout << i << endl;
            break;
        }
        else continue;
    }

   return 0;
}

/*

NOTES: The insight in this problem is pandigit numbers can only be of less than 10 digits, as to make a 10 digit number you must use zero, but using zero defys the very definition of pandigit. All pandigit numbers of 9 digits can't be primes as the sum of the digits is (9 * 10) / 2, which is divisible by 3. 

All 9 digit pandigit numbers are divisible by 3, as the sum of the digits will be 45.
All 8 digit pandigit numbers are divisible by 3, as the sum of the digits will be 36, which again is divisible by 3.
All 6 digit pandigit numbers are also divisible by 3, as the sum of the digits will be 21.
So, the highest pandigit number which is also prime must be a 7 digit number
The strategy here is to start checking from the highest 7 digit pandigit number, and halt till you obtain the prime.

*/
