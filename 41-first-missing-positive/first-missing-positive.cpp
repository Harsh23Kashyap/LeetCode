class Solution {
public:
bool isContained(const unordered_map<char, int>& a,
                 const unordered_map<char, int>& b) {

    for (auto& [ch, freq] : a) {
        if (b.find(ch) == b.end() || b.at(ch) < freq) {
            return false;
        }
    }
    return true;
}

    int firstMissingPositive(vector<int>& nums) {
        

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0)
            nums[i]=INT_MAX-1;
            // if(nums[i]==0)

        }

        for(int j=0;j<nums.size();j++){
            int val=abs(nums[j])-1;
            if(val>=nums.size()){
                continue;
                
            }
            nums[val]=abs(nums[val])*-1;
        }

        for(int j=0;j<nums.size();j++){
            if(nums[j]>=0)
            return j+1;
        }

        for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<endl;

        return nums.size()+1;

    }
};