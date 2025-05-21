class Solution {
public:
    bool isDigit(char s){
        return s>='0' and s<='9';
    }
    string duplicate(int a, string b){
        string s="";
        while(a--){
            s=s+b;
        }
        return s;
    }
    string decodeString(string s) {
        
       stack<string> sc;
       stack<int> sf;
        int tc=0;
        string ts="";
        int i=0;
        string ans="";
      while(i<s.size()){
        if(isDigit(s[i])){
            tc=(s[i]-'0');
            i++;
            while(i<s.size() and isDigit(s[i])){
                tc=tc*10+(s[i]-'0');
                i++;
            }
            sf.push(tc);
            tc=0;
            i--;
        }
        else if(s[i]=='['){
            sc.push(ts);
            ts="";
        }
        else if(s[i]==']'){
            string get=duplicate(sf.top(),ts);
            sf.pop();
            if(sc.empty()){
                ans=ans+get;
                ts="";
            }
            else
                {
                    string tt=sc.top();
                    sc.pop();
                    ts=tt+get;
                }
        }
        else{
            ts=ts+s[i];
        }
        i++;
      }
      if(ts!="")
        ans=ans+ts;
      return ans;


    }
};