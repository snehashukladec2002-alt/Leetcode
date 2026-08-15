class Solution {
public:
    void solve(string &s, int index, vector<string> &ans) {
        if (index == s.length()) {
            ans.push_back(s);
            return;
        }

        // If digit, don't change it
        if (isdigit(s[index])) {
            solve(s, index + 1, ans);
        }
        else {
            // lowercase
            s[index] = tolower(s[index]);
            solve(s, index + 1, ans);

            // uppercase
            s[index] = toupper(s[index]);
            solve(s, index + 1, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};