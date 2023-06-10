#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) {
    int size = s.length();
    if(size == 1) return true;
    
    for(int i = 0; i < size / 2; i++) {
        if(s[i] != s[size - 1 -i]) return false;
    }

    return true;
}

string to_binary(int n) {
    string result = "";

    while(n > 0) {
        result.insert(0, to_string(n % 2));
        n /= 2;
    }

    return result;
}


int main(void) {

    int sum = 0;

    for(int i = 0; i < 1000000; i++) {
        if(is_palindrome(to_string(i))) {
            if(is_palindrome(to_binary(i))) sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}
