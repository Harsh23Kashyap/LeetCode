class Solution {
public:
    int c(int a){
        int c=0;
        while(a>0){
            a=a&(a-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
       vector<int> ans;
       for(int i=0;i<=n;i++){
        ans.push_back(c(i));
       }
       return ans;
    }
};