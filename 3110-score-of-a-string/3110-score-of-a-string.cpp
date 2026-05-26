class Solution {
public:
    int scoreOfString(const string &s) {
        int score = 0;

        for (int i = 1; i < s.length(); i++) {
            score += abs(s[i] - s[i-1]);
        }
        return score;
    }
};