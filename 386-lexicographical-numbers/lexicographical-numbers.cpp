class Solution {
public:
    static bool cmp(int &a, int& b){
        string s1=to_string(a);
        string s2=to_string(b);
        return s1<s2;
    }
    void pass(int i, vector<int>& ans, int n){
        if(i>n){
            return;
        }
        ans.push_back(i);

        for(int j=0;j<=9;j++){
            pass(i*10+j,ans,n);
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // iota(a.begin(),a.end(),1);
        // sort(a.begin(),a.end(),cmp);

        for(int i=1;i<=9;i++){
            pass(i,ans,n);
        }
        

        return ans;
    }
};