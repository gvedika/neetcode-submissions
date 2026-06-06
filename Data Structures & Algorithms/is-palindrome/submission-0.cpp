class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right) {

            // skip non-alphanumeric
            if(!isalnum(s[left])) {
                left++;
                continue;
            }

            if(!isalnum(s[right])) {
                right--;
                continue;
            }

            // compare (case insensitive)
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
