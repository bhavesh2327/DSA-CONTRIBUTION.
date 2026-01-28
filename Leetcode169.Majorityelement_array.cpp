/*
========================================================
Problem: Majority Element
========================================================

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than
⌊n / 2⌋ times. You may assume that the majority element
always exists in the array.

--------------------------------------------------------
Example:
Input:  nums = [2,2,1,1,1,2,2]
Output: 2

--------------------------------------------------------
Constraints:
1 ≤ nums.length ≤ 5 * 10^4
-10^9 ≤ nums[i] ≤ 10^9

--------------------------------------------------------
Approaches Used:
1. Brute Force Approach (O(n^2), O(1) space)
2. HashMap / Frequency Count Approach (O(n), O(n) space)

========================================================
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // ------------------------------------------------
        // Approach 1: Brute Force (O(n^2))
        // ------------------------------------------------
        /*
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
        */

        // ------------------------------------------------
        // Approach 2: HashMap / Frequency Count (O(n))
        // ------------------------------------------------
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            if (freq[nums[i]] > n / 2) {
                return nums[i];
            }
        }

        return -1; // Majority element always exists
    }
};
