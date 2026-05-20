unordered_map<char, string> digitMap = {
    pair<char, string>('2', "abc"),
    pair<char, string>('3', "def"),
    pair<char, string>('4', "ghi"),
    pair<char, string>('5', "jkl"),
    pair<char, string>('6', "mno"),
    pair<char, string>('7', "pqrs"),
    pair<char, string>('8', "tuv"),
    pair<char, string>('9', "wxyz")
};

const int MAX_DEPTH = 4;

vector<string> ans;
char str[MAX_DEPTH+1];

void backTracking(const string &digits, int depth=0) {
    if (depth == digits.length()) {
        ans.push_back(str);
        return;
    }

    for (const char &ch : digitMap[digits[depth]]) {
        str[depth] = ch;
        backTracking(digits, depth+1);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        str[digits.length()] = 0;
        backTracking(digits);
        return ans;
    }
};