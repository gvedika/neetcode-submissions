class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        else{
            unordered_map<char,int> freq ;
            for(char ch: s){
                freq[ch]++;
            }
            for(char ch:t){
                freq[ch]--;
            }
            for(auto p : freq){
               if(p.second != 0)
                    {
                        return false;
                    }

            }

            return true;
        }
    }
   
};