#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define sum 1000

bool is_triplet(int a, int b, int c) {

    if(a * a == b * b  + c * c) return true;
    else return false;
}

int main(void) {
    int c, flag = 0;

    for(int a = 1; a <= sum; a++) {
        for(int b = a; b <= sum; b++) {
            c =  sum - (a + b);
            
            if(c > 0) {
                if(c > b) {
                    if(is_triplet(c, b, a)) {
                        cout << c << " " << b << " " << a << endl;
                        cout << a * b * c << endl;
                        flag = 1;
                        break;
                    }
                }

                else {
                    if(is_triplet(b, c, a)) {
                        cout << c << " " << b << " " << a << endl;
                        cout << a * b * c << endl;
                        flag = 1;
                        break;
                    }
                }
            }

        }

        if(flag) break;
    }

    return 0;
}

/*

This is a brute force way to find the triplet having sum 1000. The two nested loops chooses all combinations of two variables in the triplet. We find the third interger by subtracting the sum from 1000. Now, we check whether the triplet is pythagorean or not. If so, we print the result. This happens in O(n ^ 2).   

*/
