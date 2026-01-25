class Solution {
public:
void helper(int open,int n, string s, vector<string>& ans){
    if(s.size()==n*2){
        if(open!=0)
        return ;
        ans.push_back(s);
        return ;
    }

    //open and increase
    helper(open+1, n,s+"(",ans);

    //close and decrease
    if(open>0)
     helper(open-1, n,s+")",ans);


}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,n,"",ans);
        return ans;
    }
};