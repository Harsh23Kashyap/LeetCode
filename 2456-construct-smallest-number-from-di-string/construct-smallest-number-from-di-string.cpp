class Solution {
public:
    string smallestNumber(string pattern) {
       int num=1;
       string s="";
       stack<int> st;
       for(int i=0;i<=pattern.size();i++){
        st.push(num++);
        char ch=pattern[i];
        if(i==pattern.size() or ch=='I'){
            while(!st.empty()){
            s+=to_string(st.top());
            st.pop();
        }
        }
       }
       while(!st.empty()){
            s+=to_string(st.top());
            st.pop();
       }
       return s;
    }
};