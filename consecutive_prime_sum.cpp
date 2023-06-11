#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define range 1000000

bool is_prime(int n) {
    
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }

    return true;
}

vector <int> all_primes() {
    vector <int> v;
    for(int i = 2; i <= range; i++) {
        if(is_prime(i)) v.push_back(i);
    }

    return v;
}

pair <int, int> prime_sum(vector <int> v, int index) {
    pair <int, int> p;
    vector <int> u;
    int sum = 0, end_index;;
    
    for(int i = index; i < v.size(); i++) {
        if(sum + v[i] <= range) {
            sum += v[i];
            if(is_prime(sum)) {
                u.push_back(sum);
                end_index = i;
            }
        }

        else break;
    }

    p.first = end_index - index + 1;
    p.second = u[u.size() - 1];
    return p;
}


void longest_prime_sum(vector <int> v) {
    vector <pair<int, int>> b;
    int index = 0, count = 0;

    for(int i = 0; i < v.size(); i++) {
        b.push_back(prime_sum(v, i));   
    }

    
    for(int i = 0; i < b.size(); i++) {
        if(b[i].first > count) {
            count = b[i].first;
            index = i;
        }
    }

    cout << "sum: " << b[index].second << endl;
    cout << "number of primes: " << count << endl;
}

int main(void) {

    
    longest_prime_sum(all_primes());

    return 0;
}
