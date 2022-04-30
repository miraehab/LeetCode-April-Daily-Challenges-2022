class Solution {
public:
    // Maximum number of vertices
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string& s, int vertex, vector<char>& chars, vector<int>& indices) {
        chars.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for (int adjacent : adj[vertex]) {
            if (!visited[adjacent]) {
                DFS(s, adjacent, chars, indices);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int dest = edge[1];
            
            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }
        
        for (int v = 0; v < s.size(); ++v) {
            if (!visited[v]) {
                vector<char> chars;
                vector<int> indices;
                
                DFS(s, v, chars, indices);
                sort(chars.begin(), chars.end());
                sort(indices.begin(), indices.end());

                for (int i = 0; i < chars.size(); ++i) {
                    s[indices[i]] = chars[i];
                }
            }
        }
        
        return s;
    }
};