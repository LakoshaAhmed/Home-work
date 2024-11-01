#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Find the coordinates of the overlapping rectangle
        int x1 = max(rec1[0], rec2[0]);
        int y1 = max(rec1[1], rec2[1]);
        int x2 = min(rec1[2], rec2[2]);
        int y2 = min(rec1[3], rec2[3]);

        // Check if there is an overlap
        return x1 < x2 && y1 < y2;
    }
};

int main() {
    Solution solution;
    vector<int> rec1(4), rec2(4);

    // User input for the first rectangle
    cout << " Note after add x1 click enter after add x2 click enter and so on \n Enter the coordinates for the first rectangle (x1, y1, x2, y2):";
    cin >> rec1[0] >> rec1[1] >> rec1[2] >> rec1[3];

    // User input for the second rectangle
    cout << "Enter the coordinates for the second rectangle (x1, y1, x2, y2): ";
    cin >> rec2[0] >> rec2[1] >> rec2[2] >> rec2[3];

    // Validate rectangle coordinates
    if (rec1[0] >= rec1[2] || rec1[1] >= rec1[3] || rec2[0] >= rec2[2] || rec2[1] >= rec2[3]) {
        cout << "Invalid rectangle coordinates." << endl;
        return 1; // Exit with an error code
    }

    // Check for overlap
    cout << (solution.isRectangleOverlap(rec1, rec2) ? "Overlap" : "No Overlap") << endl;

    return 0;
}
