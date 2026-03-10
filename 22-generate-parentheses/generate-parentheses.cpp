class Solution {
public:
void helper(int open,int n, string s, vector<string>& ans){
if(s.size()==n*2){
    if(open==0){
        ans.push_back(s);
        return;
    }
    return;
}

//add open
if(open<n)
    helper(open+1,n,s+"(",ans);

if(open>0)
  helper(open-1,n,s+")",ans);


}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,n,"",ans);
        return ans;
    }
};