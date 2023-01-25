#include <iostream>
using namespace std;

long long int end_of_chain(long long int a) {
   
    long long int sum = 0;
    int temp;

    while(a > 0) {
        temp = a % 10;
        a /= 10;
        sum += temp * temp;
    }

    return sum;
}

bool is_true(long long int a) {

    while(a != 1 && a != 89) a = end_of_chain(a);

    if(a == 1) return false;

    return true;
}

int main(void) {

    int count = 0;


    for(int i = 2; i < 10000000; i++) if(is_true(i)) count++; 

    cout << count << endl;

    return 0;
}
