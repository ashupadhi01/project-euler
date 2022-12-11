#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define size 20000

long long int ar[size] = {0};
int k = 1, i = 0, temp;


int no_of_digits(long long int a) {
    int count = 0;

    while(a > 0) {
        a /= 10;
        count++;
    }

    return count;
}

bool is_permutation_of(long long int a, long long int b) {

    if(no_of_digits(a) != no_of_digits(b)) return false;

    
    int ar_1[no_of_digits(a)], ar_2[no_of_digits(a)], count = 0;

    while(a > 0) {
        ar_1[count++] = a % 10;
        a /= 10;
    }

    count = 0;

    while(b > 0) {
        ar_2[count++] = b % 10;
        b /= 10;
    }

    count = sizeof(ar_1) / sizeof(ar_1[0]);

    sort(ar_1, ar_1 + count);
    sort(ar_2, ar_2 + count);

    for(int i = 0; i < count; i++) if(ar_1[i] != ar_2[i]) return false;

    return true;
}

int no_of_permutations_in_the_sequence(long long int ar[]) {
    
    int count, max = 0, temp;

    for(int i = 0; ar[i] != 0; i++) {
        count = 0;

        for(int j = i + 1; ar[j] != 0; j++) {
            if(is_permutation_of(ar[i], ar[j])) count++;
        }

        if(count > max) {
            max = count;
            temp = i;
        }
    }

    if(max != 0) for(int i = temp; ar[i] != 0; i++) if(is_permutation_of(ar[temp], ar[i])) cout << cbrt(ar[i]) << " :: " << ar[i] << endl;

    return max + 1;
}

int main(void) {

    int m;
    cout << "Enter the number of permutations which are cubes :: ";
    cin >> m;

    while(1) {   
    
        while(1) {

            temp = k - 1;

            if(no_of_digits(pow(k, 3)) == no_of_digits(pow(temp, 3))) {
                ar[i++] = pow(temp, 3);
                k++;
            }

            else {
                ar[i] = pow(temp, 3);
                break;
            }
        }

        if(no_of_permutations_in_the_sequence(ar) == m) break;
        cout << endl;

        for(int j = 0; j < size; j++) ar[j] = 0;
        k += 1, i = 0;
    }

    return 0;
}

/*
NOTE:

The program computes the cube of all consecutive numbers with equal number of digits, and stores them in an array. Then, the array is send to a function which checks how many permutations are there in the sequence, and prints the correspoinding numbers along with their cube roots. The program halts if the sequence has *m* number of permutations, where *m* is the input. The problem asks to find the cube whose permutations generate extra four extra perfect cubes.

*/
