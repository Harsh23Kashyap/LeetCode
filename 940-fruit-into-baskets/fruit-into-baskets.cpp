class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0;
        unordered_map<int,int> u;
        int sz=0;
        while(left<=right and right<fruits.size()){
            u[fruits[right]]++;
            while(u.size()>2 and left<right){
                u[fruits[left]]--;
                if(u[fruits[left]]==0){
                    u.erase(fruits[left]);
                }
                left++;
            }
            sz=max(sz,right-left+1);
            // cout<<sz<<endl;
            right++;
        }
        return sz;
    }
};