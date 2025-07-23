class Solution {
public:
    pair<int,string> pass(string s, string val, int v){
        stack<char> st;
        int ans=0;
    // cout<<"Going for "<<val<<endl;
        for(int i=0;i<s.size();i++){
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
               string check = "";
                check += st.top(); 
                check += s[i];

                // cout<<check<<endl;
                if(check==val){
                    ans+=v;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        string pass="";
        while(!st.empty()){
            pass+=st.top();
            st.pop();
        }
        return {ans,pass};
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        pair<int,string> score=pass(s,x>y?"ab":"ba",x>y?x:y);
        ans+=score.first;
        score=pass(score.second,x<y?"ba":"ab",x<y?x:y);

        if(x==y){
            int currscore=ans+score.first;
            score=pass(s,"ab",x);
            int ns=score.first;
            score=pass(score.second,"ab",y);
            return max(currscore,ns+score.first);

        }
        return ans+score.first;
    }
};