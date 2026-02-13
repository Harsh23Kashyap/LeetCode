class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size()>2){
            
            string aa="";
            for(int i=0;i<s.size()-1;i++){
                int sum=((s[i]-'0')+(s[i+1]-'0'))%10;
                aa+=to_string(sum);
            }
            // cout<<aa<<endl;
            s=aa;
        }
        // cout<<s<<endl;
        return s[0]==s[1];
    }

};