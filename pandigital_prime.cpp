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