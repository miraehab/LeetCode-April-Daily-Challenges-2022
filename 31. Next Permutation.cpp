class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1;
        while(index > 0 && nums[index] <= nums[index-1]){
            --index;
        }
        if(index == 0){
            reverse(nums.begin(), nums.end());
        }else{
            bool special = false;
            int left = nums[index-1], left_index = index-1;
            while(index < nums.size()-1 && nums[index+1] <= nums[index] && nums[index+1] > left){
                index+=1;
                special = true;
            }
            int tmp = nums[index];
            if(special){ 
                nums[index] = left;
                nums[left_index] = tmp;
                sort(nums.begin()+left_index+1, nums.end());
            }else{ 
                nums[index] = nums[index-1];
                nums[index-1] = tmp;
                sort(nums.begin()+index, nums.end());
            }
        }
    }
};