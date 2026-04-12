class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> m;

        for(int i=0;i<nums.size();i++){
            int it=nums[i];
            // look for element such that 
            // bigegrelemnt +valeudiff
            int x=it+valueDiff;

            auto nex=m.upper_bound(x);
            if(nex!=m.begin()){

                --nex;
                int val=*nex;
                if(abs(val-it)<=valueDiff)
                return true;
            }


            x=it-valueDiff;
            nex=m.lower_bound(x);
            if(nex!=m.end()){
                int val=*nex;
                if(abs(val-it)<=valueDiff)
                return true;
            }


            if(i>=indexDiff){
                m.erase(m.find(nums[i-indexDiff]));
            }
            m.insert(it);
        }
        return false;
    }
};