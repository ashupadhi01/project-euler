#include <iostream>
using namespace std;

int main(void) {

    int sum = 0;
    for(int i = 0; i < 1000; i++) if(i % 3 == 0 || i % 5 == 0) sum += i;
    cout << sum << endl;

    return 0;
}

/*
A loop runs that adds to a variable named *sum* if the iterator is either a multiple of 3 or 5.
Then, the result is printed.
*/
