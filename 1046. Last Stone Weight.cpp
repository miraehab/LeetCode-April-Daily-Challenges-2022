class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        sort(stones.begin(), stones.end());
        int right = stones.size()-1, left = right-1;
        for(int i = 0; i < stones.size(); ++i){
            if(stones[right] == stones[left]){
                stones[right] = 0;
                stones[left] = 0;
            }else{
                stones[right] -= stones[left];
                stones[left] = 0;
            }
            sort(stones.begin(), stones.end());
        }
        return stones[right];
    }
};