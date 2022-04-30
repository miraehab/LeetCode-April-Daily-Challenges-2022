class Solution {
    vector<vector<int>> directions = { {-1,0}, {0,-1}, {0,1}, {1, 0} };

    bool is_Valid(vector<vector<int>>& heights, int maxi) {
        queue<pair<int,int>> q;
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        q.push({0,0});
        seen[0][0] = true;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            
            if(r == rows - 1 && c == cols - 1) return true;

            for(auto& dir : directions) {
                int dr = dir[0] + r;
                int dc = dir[1] + c;
                if(dr < 0 || dr >= rows) continue;
                if(dc < 0 || dc >= cols) continue;
                if(seen[dr][dc]) continue;
                if(abs(heights[r][c] - heights[dr][dc]) > maxi) continue;
                seen[dr][dc] = true;
                q.push({dr, dc});
            }
        }
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int L = 0;
        int R = INT_MAX;
        int best = INT_MAX;
        while(L <= R) {
            int M = L + (R-L) / 2;  
            if(is_Valid(heights, M)) {
                R = M - 1;
                best = min(best, M);
            }else {
                L = M + 1;
            }
        }
        return best;
    }
};