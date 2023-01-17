#include <iostream>
#include <vector>
using namespace std; 


bool is_prime(int a) {
    for(int i = 2; i * i <= a; i++) if(a % i == 0) return false;
    return true;
}

void remove_duplicates(vector <int>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] == v[j]) {
                v.erase(v.begin() + j);
                j -= 1;
            }
        }
    }
}

vector <int> prime_factorise(int a) {
    vector <int> v;
    
    for(int i = 2; i > 0; i++) {
        if(is_prime(i)) {
            while(1) {
                if(a % i == 0) {
                    v.push_back(i);
                    a /= i;
                }

                else break;
            }
        }

        if(a == 1) break;
    }

    remove_duplicates(v);

    return v;
}

int main(void) {
    vector <int> v1, v2;
    int k = 4;

    for(int i = 2; i > 0; i++) {
        v1 = prime_factorise(i);

        if(v1.size() == 4) v2.push_back(i);
        else v2.clear();

        if(v2.size() == k) break;
        else continue;
    }


    for(auto x : v2) cout << x << " ";

    return 0;
}

/*
NOTE:

1. is_prime() function checks whether it a number is prime.
2. remove_duplicates() function removes the similar elements in a vector.
3. prime_factorise() function factorises a number a stores all the factors in a vector,which the function eventually returns.

In driver code, I run an infinite loop. I factorise each *i* and store the factors in vector *v1*.
If the number of unique factors match *k*, I push *i* into another vector v2. 
If the number of unique factors of (i + 1) doesn't match *k*, I empty the vector v2.

In in any segment of the infinite loop, I get *k* consecutive numbers each having *k* distinct prime factors, the loop breaks. Then, I print those numbers stored in vector *v2*

*/
