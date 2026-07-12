class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap -> (distance, point)
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>
        > pq;

        // Traverse all points
        for(auto point : points)
        {
            // Compute squared distance
            int x = point[0];
            int y = point[1];
            int distance = x * x + y * y;

            // Push (distance, point) into heap
            pq.push({distance,point});

            
            // If heap size > k
            //     pop()
            if(pq.size()>k){
                pq.pop();
            }

        }

        vector<vector<int>> ans;
        // TODO:
        // While heap is not empty
        // {
        //     Add point to answer
        //     Pop heap
        // }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};