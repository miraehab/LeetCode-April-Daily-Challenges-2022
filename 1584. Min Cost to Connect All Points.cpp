class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int Cost = 0;
        int edgesUsed = 0;
        
        vector<bool> in_MST(n);
        vector<int> min_Dist(n, INT_MAX);
        min_Dist[0] = 0;
        
        while (edgesUsed < n) {
            int Min_Edge = INT_MAX;
            int currNode = -1;
            
            for (int j = 0; j < n; ++j) {
                if (!in_MST[j] && Min_Edge > min_Dist[j]) {
                    Min_Edge = min_Dist[j];
                    currNode = j;
                }
            }
            
            Cost += Min_Edge;
            ++edgesUsed;
            in_MST[currNode] = true;
            
            for (int next = 0; next < n; ++next) {
                int weight = abs(points[currNode][0] - points[next][0]) + 
                             abs(points[currNode][1] - points[next][1]);
                
                if (!in_MST[next] && min_Dist[next] > weight) {
                    min_Dist[next] = weight;
                }
            }
        }
        
        return Cost;
    }
};