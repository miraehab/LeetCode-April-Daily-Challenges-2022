class KthLargest {
    int k;
    multiset<int> s_nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); ++i){
            s_nums.insert(nums[i]);
        }
    }
    
    int add(int val) {
        s_nums.insert(val);
        auto it = s_nums.rbegin();
        int counter = 1;
        while(counter < k){ 
            ++it;
            ++counter;
        }
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */