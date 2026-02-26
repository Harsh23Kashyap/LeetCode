class Solution {
public:
//1101 -> 1110-> 111 - 1011-. 1+2+8-11 1100
    int numSteps(string s) {
        
        int curr=0;
        while(s!="1"){
            // cout<<s<<endl;
            if(s[s.size()-1]=='1'){
                s[s.size()-1]='0';
                int j=s.size()-2;
                while(j>=0){
                    cout<<"FInding s"<<s<<endl;
                    if(s[j]=='0'){
                        s[j]='1';
                        break;
                    }
                    else{
                        s[j]='0';
                    }
                    j--;
                }
                if(j==-1){
                    // cout<<"hi"<<endl;
                    s="1"+s;
                }
                // cout<<s<<endl;
                curr++;
            }
            else{
                int j=s.size()-1;
                while(j>=0){
                    if(s[j]=='0'){
                        curr++;
                        j--;
                    }
                    else break;
                    
                }
                s=s.substr(0,j+1);
            }
            // cout<<curr<<endl;
        }
        return curr;
    }
};


//11000 -> 24 
// 11->24/2=12/2=6/2=3
//100 - 4
//4-4/2-2/2
//1