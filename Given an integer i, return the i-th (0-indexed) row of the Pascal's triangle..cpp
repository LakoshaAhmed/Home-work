#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) 
{ 
    vector<int> currow(rowIndex + 1, 0); 
    currow[0] = 1; 
    
    for (int i = 1; i <= rowIndex; i++) 
    {
        currow[i] = 1;
        for (int j = i - 1; j > 0; j--) 
        {
            currow[j] = currow[j] + currow[j - 1]; 
        }
    }

    return currow; 
}    

int main()
{
    int n;
    cout << "Enter the row number: ";
    cin >> n; 
    if (n < 0) 
    {
        cout << "ERROR: Row number cannot be negative!" << endl; 
    }
    else 
    { 
        vector<int> arr = getRow(n); 
        
        for(int i = 0; i < arr.size(); i++)
        {
            if (i == arr.size() - 1) 
                cout << arr[i]; 
            else
                cout << arr[i] << ", "; 
        } 
        cout << endl; 
    }
    return 0; 
}
