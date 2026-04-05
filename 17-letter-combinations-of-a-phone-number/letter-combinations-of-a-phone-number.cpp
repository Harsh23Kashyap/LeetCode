class Solution {
public:
    void pass(int i, string s, unordered_map<int, string> &u, string c, vector<string> &ans){
        if(i==s.size()){
            cout<<c<<endl;
            ans.push_back(c);
            return;
        }
        for(auto it:u[s[i]-'0']){
            cout<<it<<endl;
            c+=it;
            cout<<c<<endl;
            pass(i+1,s,u,c,ans);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> u;
        u[2]="abc";
        u[3]="def";
        u[4]="ghi";
        u[5]="jkl";
        u[6]="mno";
        u[7]="pqrs";
        u[8]="tuv";
        u[9]="wxyz";

        vector<string> ans;
         pass(0,digits,u, "", ans);
         return ans;
    }
};