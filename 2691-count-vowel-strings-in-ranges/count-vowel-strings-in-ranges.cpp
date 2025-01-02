class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(words.size(),0);

        for(int i=0;i<words.size();i++)
        {
            auto w=words[i];
            if((w[0]=='a' or w[0]=='e' or w[0]=='i' or w[0]=='o' or w[0]=='u') and (w[w.size()-1]=='a' or w[w.size()-1]=='e' or w[w.size()-1]=='i' or w[w.size()-1]=='o' or w[w.size()-1]=='u')){
                ans[i]=((i-1)>=0)?ans[i-1]+1:1;
            }
            else
                ans[i]=((i-1)>=0)?ans[i-1]:0;

        }
vector<int> res;
        for(auto it:queries){
            int st=it[0],e=it[1];
            int bst=(st==0)?0:ans[st-1];
            res.push_back(ans[e]-bst);
        }
        return res;
        
    }
};