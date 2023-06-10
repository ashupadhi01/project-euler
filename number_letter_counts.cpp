#include <iostream>
#include <vector>
using namespace std;

vector <string> p1 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector <string> p2 = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector <string> p4 = {"zero", "eleven", "twelve", "thirteen", "fourteen", "fifteen"};
string a = "teen";
string b = "hundred";
string c = "thousand";

int char_count(string s) {
    int count  = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 32 || s[i] == 45) continue;
        else count++;
    }

    return count;
}

string number_to_word(int n) {
    string s = "";
    int i = 1, temp;

    while(i) {
        if(n <= 0) break;

        if(n % 10 != 0) {

            if(i == 1) {

                if(n % 100 <= 15 && n % 100 >= 11 ) {
                    s.insert(0, p4[n % 10] + " ");
                    i++;
                    n /= 10;
                }

                else if(n % 100 > 15 && n % 100 < 20) {
                    if(n % 100 == 18) {
                        s.insert(0, "eighteen");
                    }

                    else {
                        s.insert(0, p1[n % 10] + a + " ");
                    }

                    n /= 10;
                    i++;
                }

                else s.insert(0, p1[n % 10] + " ");
            }

            else if(i == 3) {

                if(s.length() != 0) {
                    s.insert(0, p1[n % 10] + " " + b + " " + "and ");
                }

                else {
                    s.insert(0, p1[n % 10] + " " + b);
                }
            }

            else if(i == 4) {
                s.insert(0, p1[n % 10] + " " + c + " ");
            }

            else s.insert(0, p2[n % 10] + " ");
        
        }

        n /= 10;
        i++;
    }

    return s;
}

int main(void) {
    
    int sum = 0;

    for(int i = 1; i <= 1000; i++) {
        sum += char_count(number_to_word(i));
    }

    cout << sum << endl;

    return 0;
}
