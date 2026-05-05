class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1){
            if(n=="0")
                return "1";
            
            return to_string(stoi(n)-1);
        }
        int len=n.size();
        bool even=(len%2==0);
        long long real=stoll(n);
        vector<string> aa;
        vector<string> options;
        string fhh=n.substr(0,(len+1)/2);
        string n99(n.size(),'9');
        string n9(n.size()-1,'9');
        string n10(n.size()-1,'0');
        string n100(n.size()-2,'0');
        long long fh=stoll(fhh);
        aa.push_back(to_string(fh));
        aa.push_back(to_string(fh+1));
        aa.push_back(to_string(fh-1));
        options.push_back(n99);
        options.push_back(n9);
        options.push_back("1"+n10+"1");
         options.push_back("1"+n100+"1");
        for(int i=0;i<aa.size();i++){
           
            string currres=aa[i];
            string rev="";
            if(even){
                  rev=currres;
                reverse(rev.begin(),rev.end());
            }
            else{
                  rev=currres;
                rev.pop_back();
                reverse(rev.begin(),rev.end());
            }
            options.push_back(currres+rev);
        }
        
        long long res=LONG_LONG_MAX;
        for(int i=0;i<options.size();i++){ 
            if(options[i]==n)
            continue;
            string currres=options[i];
            cout<<options[i]<<endl;
            long long curr=stoll(currres);
            
            if(abs(curr-real)<abs(res-real)){
                res=curr;

            }
            else if(abs(curr-real)==abs(real-res)){
                // cout<<" here "<<" "<<curr<<" "<<res<<endl;;
                if(curr<res)
                    res=curr;
            }
            // cout<<res<<endl;

        }
        return to_string(res);




        
    }
};