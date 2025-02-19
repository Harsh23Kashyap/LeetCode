class Solution {
public:
vector<int> abc={'a','b','c'};
    void pass(string s, set<string> &st, int n){
        cout<<s<<endl;
        if(s.size()>n)
        return ;
        if(s.size()==n){
            st.insert(s);
            return;
        }
        for(auto it:abc){
            // cout<<it<<endl;
            if(s.empty() or it!=s[s.size()-1]){
                s+=it;
                pass(s,st,n);
                s.pop_back();
            }

        }
    }
    string getHappyString(int n, int k) {
        set<string> st;
        pass("",st,n);
        if(st.size()<k)
        return "";

        int i=1;
        for(auto it:st){
            if(i==k)
            return it;
            i++;
        }
        return "";
    }
};