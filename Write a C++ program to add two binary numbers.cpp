#include <iostream>
#include <cmath>
using namespace std;


unsigned int binsum(unsigned int b1, unsigned int b2) {
    unsigned int digits[20] = {0}; // Initialize the digits array
    int carry = 0;
    int i = 0;
    
    // Process the binary numbers until both are 0 and there's no carry
    while (b1 > 0 || b2 > 0 || carry > 0) {
        // Get the last digits of b1 and b2
        int bit1 = b1 % 10;
        int bit2 = b2 % 10;

        // Calculate sum of bits and carry
        int sum = bit1 + bit2 + carry;
        
        // The resulting bit (0 or 1)
        digits[i] = sum % 2;

        // Calculate carry for next iteration (0 or 1)
        carry = sum / 2;

        // Move to the next digit
        b1 /= 10;
        b2 /= 10;
        i++;
    }

    // Construct the result from the digits array
    unsigned int res = 0;
    for (int j = 0; j < i; j++) {
        if (digits[j] == 1) {
            res += pow(10, j);
        }
    }
    return res;
}

int main() {
    unsigned int b1;
    unsigned int b2;
    cout<<"the First Binary Number: "; 
    cin>> b1 ;
    cout << "the second Binary Number: "; 
    cin>>b2 ;
  
    unsigned int result = binsum(b1, b2);
    std::cout << "Sum of " << b1 << " and " << b2 << " in binary is: " << result << std::endl;
    return 0;
}
