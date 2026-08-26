class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1')
                ones++;

            // Too many 1s
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Remove unnecessary leading 0s
            while (left < right && s[left] == '0') {
                left++;
            }

            // Exactly k ones
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans == "" ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};