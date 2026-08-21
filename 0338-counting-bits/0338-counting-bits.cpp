class Solution {
private:
    int popcount(int n) {
        int cnt = 0;

        while (n > 0) {
            n &= n-1;
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = popcount(i);
        }
        return ans;
    }
};