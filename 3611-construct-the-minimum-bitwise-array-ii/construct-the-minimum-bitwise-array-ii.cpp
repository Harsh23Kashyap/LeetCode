class Solution {
public:
    //i only have two optons
    // for any num,  i can be like if its 7 -> 111 - i can do like 110 -> 6 

    int res(int a){
        bool found=false;
        int mini=1;
        for(int i=0;i<32;i++){
            int numform=(1<<i);
            if(numform>a){
                if(found)
                return mini;
                return -1;
            }
if (((1 << i) & a) != 0){
                int changenum=a;
                changenum=changenum ^((1<<i));
                if((changenum | (changenum+1)) == a){
                    found= true;
                    mini=changenum;
                }
            }
        }
        return found?mini:-1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int> ans;

        for (int n : nums) {

            int aa=-1;
            if(n!=2){
                aa=res(n);
            }
            ans.push_back(aa);
        }

        return ans;
    }
};