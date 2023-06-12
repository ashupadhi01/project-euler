#include <iostream>
#include <vector>
using namespace std;
#define range 1000

int if_exists(int a, vector <int>& v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        if(a == v[i]) return v.size() - i;
    }

    return 0;
}

int recc_length(int n) {
    vector <int> v;
    int k = 10, temp;
    
    while(k > 0) {
        k %= n;
        temp = if_exists(k, v);
        if(temp) return temp;
        else v.push_back(k);
        k *= 10;
    }

    return 0;
}

int main(void) {
    for(int i = range; i >= 2; i--) {
        if(recc_length(i) == i -1) {
            cout << i << endl;
            break;
        }
    }
}

/*
Maximum recurring length obtained by 1 / D in a given range is for the largest D for which the recurring length is D - 1. So, we compute the recurring length for each D in a decrementing loop in the given range. The moment the recurring length becomes equal to D-1, we stop and print the result.
*/
