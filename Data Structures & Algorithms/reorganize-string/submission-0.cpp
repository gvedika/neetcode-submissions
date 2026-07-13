class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        // Count frequency of every character
        for(char ch : s)
        {
            freq[ch]++;
        }

        // Max Heap -> (frequency, character)
        priority_queue<pair<int,char>> pq;

        // Push all characters into heap
        for(auto it : freq)
        {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(pq.size() > 1)
        {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if(first.first > 0)
                pq.push(first);

            if(second.first > 0)
                pq.push(second);
        }

        if(!pq.empty())
        {
            if(pq.top().first > 1)
                return "";

            ans += pq.top().second;
        }

        return ans;
    }
};