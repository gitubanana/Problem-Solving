class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        for (const int &num : nums) {
            sum += num;
        }
        return sum % k;
    }
};