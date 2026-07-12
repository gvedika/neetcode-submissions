class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for(int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Min Heap (frequency, number)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Step 3: Push every (frequency, number) pair
        for(auto it : freq)
        {
            pq.push({it.second, it.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 4: Store answer
        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};