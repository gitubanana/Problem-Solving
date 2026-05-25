class Solution {
private:
    int reverse(int n) {
        int ret = 0;

        while (n > 0) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};