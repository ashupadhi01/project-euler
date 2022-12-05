#include <iostream>
using namespace std;
#define size 1000

int t; 
int multiplicand[size] = {0};
int result[size] = {0};
int intermediate[size] = {0};



int no_of_digits(int a) {
    int count = 0;
    
    while(a > 0) {
        a /= 10;
        count++;
    }
    
    return count;
}

int add(int a) { 
    int k = t;
    int temp = 0;

    for(int i = 0; i < a; i++) {
        temp +=  result[k] + intermediate[i];
        result[k++] = temp % 10;
        temp /= 10;
    }
    if(temp != 0)result[k++] = temp;
    t++;
    return k;
}

int product(int a, int b) {
    int k = 0, j = 0;

    while(a >= 0) {
        k += multiplicand[a--] * b;
        intermediate[j++] = k % 10;
        k /= 10;
    }
    
    if(k != 0) intermediate[j++] = k;

   return add(j);
}


int mul(int a, int b) {
    int c;

    while(b > 0) {
        c = product(a, b % 10);
        b /= 10;
    }

    return c;
}

int main(void) {
    
    int a, b, temp, c; 
    cin >> a;
    temp = a;

    b = no_of_digits(a) - 1; 

    while(temp > 0) {
        multiplicand[b--] = temp % 10;
        temp /= 10;
    }

    b = no_of_digits(a) - 1;

    while(a > 1) {
        
        a -= 1;
        t = 0;
        c = mul(b, a);

        int k = 0;

        for(int i = c - 1; i >= 0; i--) {    
            multiplicand[k++] = result[i];
            result[i] = 0;
        }

        b = k - 1;

    }

    temp = 0;

    for(int i = 0; i <= b; i++) temp += multiplicand[i];
    cout << temp << endl;

    return 0;
}
