
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> a(n);// adj list for weighted graph
        for(int i =0;i<times.size(); i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s-1].push_back({d-1,w});    
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;// min heap

        vector<int> dist(n,INT_MAX);// infinity array
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int distance = p.first;
            int node = p.second;
            if(distance > dist[node]){
                continue;

            }
            for(int j=0; j<a[node].size(); j++){
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if(distance +wt< dist[neigh]){
                    dist[neigh]= distance +wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX){

        
        return -1;}

        ans = max(ans, dist[i]);
        }

    return ans;



    }
};