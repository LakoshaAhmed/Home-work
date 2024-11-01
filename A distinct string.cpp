#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;

        // Count occurrences of each string
        for (const string& str : arr) {
            countMap[str]++;
        }

        // Iterate through arr again to find the k-th distinct string
        for (const string& str : arr) {
            if (countMap[str] == 1) { // Check if the string is distinct
                k--;
                if (k == 0) { // If k is 0, we found our k-th distinct string
                    return str;
                }
            }
        }

        return ""; // Return an empty string if there are not enough distinct strings
    }
};

int main() {
    Solution solution;
    vector<string> arr;
    int n, k;

    // User input for the number of strings
    cout << "Enter the number of strings: ";
    cin >> n;
    arr.resize(n); // Resize the vector to hold n strings

    // User input for the strings
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // User input for k
    cout << "Enter the value of k: ";
    cin >> k;

    // Find and display the k-th distinct string
    string result = solution.kthDistinct(arr, k);
    if (!result.empty()) {
        cout << "The " << k << "-th distinct string is: " << result << endl;
    } else {
        cout << "There is no " << k << "-th distinct string." << endl;
    }

    return 0;
}
