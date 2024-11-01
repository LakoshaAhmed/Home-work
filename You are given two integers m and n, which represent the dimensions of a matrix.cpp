#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Initialize the matrix with -1
        int i = 0, j = 0, p = 0; // Start position and direction index
        vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // Right, Down, Left, Up

        while (head) {
            ans[i][j] = head->val; // Fill in the current value
            head = head->next; // Move to the next node
            
            // Move in the current direction
            int x = i + dirs[p][0];
            int y = j + dirs[p][1];

            // Check bounds and if the next cell is already filled
            if (x < 0 || y < 0 || x >= m || y >= n || ans[x][y] != -1) {
                p = (p + 1) % 4; // Change direction
                x = i + dirs[p][0]; // Update x and y based on new direction
                y = j + dirs[p][1];
            }

            // Update the current position
            if (head) { // Only update if there are still elements in the linked list
                i = x;
                j = y;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // User input for the linked list
    int numNodes;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; ++i) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode; // First node
            tail = head;
        } else {
            tail->next = newNode; // Append to the list
            tail = newNode; // Move tail to the new node
        }
    }

    // User input for the dimensions of the spiral matrix
    int m, n;
    cout << "Enter the number of rows (m) for the spiral matrix: ";
    cin >> m;
    cout << "Enter the number of columns (n) for the spiral matrix: ";
    cin >> n;

    // Generate the spiral matrix
    vector<vector<int>> result = solution.spiralMatrix(m, n, head);

    // Print the resulting matrix
    cout << "The resulting spiral matrix is:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up linked list (not shown for brevity)
    return 0;
}
