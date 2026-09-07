#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

long long int _get_triangular_number(int n) {
   return (n * (n + 1)) / 2;
}

int num_divisors(long long int n) {
   unordered_map <int, int> factors;
   int factor = 2, count = 1;

   do {
       if(n % factor == 0) {
           n /= factor;
           factors[factor]++;
       }
       else {
           factor++;
       }
  
   } while(n > 1);

   for(auto it = factors.begin(); it != factors.end(); it++) {
       count *= it->second + 1;
   }

   return count;
}

int main(void) {
   int divisors_count, triangular_number, n = 1;

   while (n++){
       triangular_number = _get_triangular_number(n);
       divisors_count = num_divisors(triangular_number);
      
       if(divisors_count >= 500) {
           break;
       }
   }

   cout << triangular_number << '\n';
   return 1;
}
