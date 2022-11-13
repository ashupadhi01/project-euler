#include <iostream>
#include <vector>

int main(void) {

    /*
    You do not need to generate all the elements of the spiral. Design an algorithm that generates the corner elements if the sphere has *n* layers. Transition to the successive layer always happens after element at the top-right. 
    */

    int a, k = 0, n = 1, sum = 1;
    std::cout << "Enter the dimension of spiral: ";
    std::cin >> a; 
    a /= 2;

    while(1) {
        
        k++;

        for(int i = 0; i < 4; i++) {
            n += 2*k;
            sum += n;
        }

        if(k == a) break;
    }

    std::cout << sum << "\n";

    return 0;
}
