class Solution {
public:
vector<int> curr;
vector<int> original;
    Solution(vector<int>& nums) {
        curr=nums;
        original=nums;

    }
    
    vector<int> reset() {
        curr=original;
        return curr;
    }
    
    vector<int> shuffle() {
        int n=curr.size();
        for(int i=0;i<curr.size();i++){
            int k=rand()%(curr.size()-i);
            int toshuff=k+i;
            swap(curr[i],curr[toshuff]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */