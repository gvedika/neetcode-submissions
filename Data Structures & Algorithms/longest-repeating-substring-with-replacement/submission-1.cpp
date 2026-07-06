class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> freq(128, 0);

        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            while((right - left + 1) - maxFreq > k){
                freq[s[left] ]--;
            left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
        
    }
};