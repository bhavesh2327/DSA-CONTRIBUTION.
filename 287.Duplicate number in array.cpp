#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 1️⃣ Brute Force (Searching) — O(n^2)
    int findDuplicate_BruteForce(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1;
    }

    // 2️⃣ Sorting Approach — O(n log n)
    // (Modifies array)
    int findDuplicate_Sorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }

    // 3️⃣ HashSet Approach — O(n) space
    int findDuplicate_HashSet(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x))
                return x;
            s.insert(x);
        }
        return -1;
    }

    // 4️⃣ Binary Search on Value Range — O(n log n), O(1) space
    int findDuplicate_BinarySearch(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int x : nums)
                if (x <= mid) count++;

            if (count > mid)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    // 5️⃣ Floyd’s Cycle Detection (Slow & Fast Pointer) — BEST
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
