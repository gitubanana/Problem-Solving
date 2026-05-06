class Elem {
public:
    int data, idx;

    inline bool operator<(const Elem &other) const {
        return this->data < other.data;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Elem> arr(nums.size());

        for (int i = 0; i < arr.size(); i++) {
            arr[i].data = nums[i];
            arr[i].idx = i;
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size()-1;
        do {
            int sum = arr[left].data + arr[right].data;
            if (sum == target) {
                return {arr[left].idx, arr[right].idx};
            }

            if (sum > target) {
                right--;
            } else {
                left++;
            }

        } while (left <= right);

        throw exception();
    }
};