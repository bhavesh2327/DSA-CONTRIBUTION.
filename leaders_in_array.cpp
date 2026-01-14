🏆 Leaders in an Array (C++)
📌 Problem Statement

Given an array of integers, an element is called a leader if it is greater than or equal to all the elements to its right.
The rightmost element is always a leader.

🧠 Approach

Traverse the array from right to left

Keep track of the maximum element seen so far

If the current element is greater than or equal to the maximum, it is a leader

Store the leaders and reverse the result to maintain the original order

✅ Example

Input

arr = [16, 17, 4, 3, 5, 2]


Output

[17, 5, 2]

💻 C++ Implementation
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int maxi = INT_MIN;
        int n = arr.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        // Reverse to maintain original order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

⏱ Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(n) (for storing leaders)

🚀 Key Notes

No sorting is required

Efficient single-pass solution

Works for all edge cases (including negative numbers)
