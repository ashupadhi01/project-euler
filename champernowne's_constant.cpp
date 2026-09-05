#include <iostream>
#include <cmath>
using namespace std;

int champernowne_const(int digit_idx) {
    long long int cum_num_digits = 0, num_digits, req_num_digit, digit_offset_idx, dig_idx, num_offset_idx, req_digit;
    string req_num;

    for(int i = 1; i > 0; i++) {
        num_digits = pow(10, i - 1) * 9 * i;

        if(num_digits + cum_num_digits <= digit_idx) {
            cum_num_digits += num_digits;
        }

        else {
            req_num_digit = i;
            break;
        }
    }

    digit_offset_idx = digit_idx - cum_num_digits;
    num_offset_idx = digit_offset_idx / req_num_digit + (digit_offset_idx % req_num_digit != 0);
    
    dig_idx = digit_offset_idx % req_num_digit;
    req_num = to_string((long long) pow(10, req_num_digit - 1) + num_offset_idx - 1);

    return req_num[(dig_idx + req_num_digit - 1) % req_num_digit] - '0';
}

int main(void) {
    int product = 1;

    for(int i = 0; i <= 6; i++) {
        product *= champernowne_const(pow(10, i));
    }

    cout << product << endl;

    return 0;
}

/*
NOTE:

We find out the natural number in which the required digit happens to lie. Then, we find the offset of the required digit in the block where block represents the sequence of natural numbers having the same length. We use the length of the number in which the required digit happens to lie to narrow down to the exact number which contains the required digit.

We keep accumulating all the digits that occur in a given block to find out the block in which required digit lies. For this I am running a loop. I wondered whether a closed form solution could replace it. To compute the total number of digits up to a given block, we have a sequence which goes on like this: 1 * pow(10, 0) + 2 * pow(10, 1) + ... + k * pow(10, k-1)

This is an arithmetic-geometric sequence for which the closed form solution exists. Sum of all digits for all blocks including the numbers having length k: S(k) = [pow(10, k) * (9 * k - 1) + 1] / 9.
But finding `k` from S(k) requires inverting this equation, which is not possible. We cannot isolate `k` by any algebraic manipulation as there are both exponential & multiplicative terms in the same variable.   
*/
