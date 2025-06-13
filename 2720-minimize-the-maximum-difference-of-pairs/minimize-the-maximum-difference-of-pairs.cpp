class Solution {
public:
    bool possible(int m, vector<int> &nn, int p){
       

        for(int i=0;i<nn.size()-1;i++){
            if(nn[i+1]-nn[i]<=m){
                i++;
                p--;
            }
            
            if(p==0)
            return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
         if(p==0)
        return 0;
        sort(nums.begin(),nums.end());
       int l=0,h=nums.back();
        int ans=h;
       while(l<=h){
        int m=l+(h-l)/2;

        if(possible(m,nums,p)){
            ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
       }
       return ans;
    }
};