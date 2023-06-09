#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool if_ap_exists(vector <int>& v) {
    vector <int> ap;
    int size = v.size();
    int diff[size - 1][size];
    
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            diff[i][j] = v[j] - v[i];
        }
    }

    for(int i = 0; i < size - 1 - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            for(int m = i + 1; m < size - 1; m++) {
                for(int n = m + 1; n < size; n++) {
                    if(diff[i][j] == diff[m][n]) {
                        if(j == m) {
                            ap.push_back(v[i]);
                            ap.push_back(v[j]);
                            ap.push_back(v[n]);
                            diff[m][n] = 0;
                        }
                    }
                }
            }
        }
    }

    if(ap.size() != 0) {
        for(auto x : ap) cout << x << " ";
        return true;
    }

    return false;
}

bool is_permutation_of(int a, int b) {
    vector <int> v1, v2;
    
    while(a > 0) {
        v1.push_back(a % 10);
        a /= 10;
    }

    while(b > 0) {
        v2.push_back(b % 10);
        b /= 10;
    }

    if(v1.size() != v2.size()) return false;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]) return false;
    }

    return true;
}

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(void) {
    vector <int> v, u;
    int flag;

    for(int i = 1000; i < 10000; i++) {
        if(is_prime(i)) v.push_back(i);
    }

    for(int i = 0; i < v.size(); i++) {
        flag = 0;
        for(int j = i + 1; j < v.size(); j++) {
            if(is_permutation_of(v[i], v[j])) {
                flag = 1;
                u.push_back(v[j]);
                v.erase(v.begin() + j);
                j -= 1;
            }
        }
       
        if(flag) {
            u.insert(u.begin(), v[i]);
            v.erase(v.begin() + i);
            i -= 1;
            if(u.size() > 2) {
                if(if_ap_exists(u)) cout << endl;
            }
            u.clear();
        }
    }

    return 0;
}
