class Solution {
public:
    int maxArea(vector<int>& height) {
         int max_water = 0;
        int start = 0, end = height.size()-1;
        while(start < end){
            int min_height = min(height[start],height[end]);
            max_water = max(max_water, min_height*(end-start));
            while(start < height.size() && height[start] <= min_height) ++start;
            while(end >= 0 && height[end] <= min_height) --end;
        }
        return max_water;
    }
};