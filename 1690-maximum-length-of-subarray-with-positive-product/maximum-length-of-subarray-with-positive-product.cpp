class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int currpos = 0, currneg = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                currpos = 0;
                currneg = 0;
            }
            else if(nums[i] > 0) {
                currpos++;
                currneg = currneg == 0 ? 0: currneg+1;
            }
            else { // nums[i] < 0

                swap(currpos,currneg);
                currpos = (currpos == 0) ? 0 : currpos + 1;
                currneg = (currneg == 0) ? 1 : currneg + 1;
            }

            maxi = max(maxi, currpos);
        }

        return maxi;
    }
};
