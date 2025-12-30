class Solution {
public:
unordered_map<string, vector<char> > u;
unordered_set<string> fail;
    bool dfs(string s){
        if(s.size()==1)
        return true;

        if(fail.find(s)!=fail.end())
        return false;

        for(int i=0;i<s.size()-1;i++){
            string check="";
            check=check+s[i]+s[i+1];
            if(u.find(check)==u.end())
                return false;
        }
        vector<string> options;
        call(s, options,"",0);
        for(auto a:options){
            if (dfs(a))
                return true;
        }

        fail.insert(s);
        return false;

    }
    void call(string bottom, vector<string> &options, string a, int idx){

        if(idx+1>=bottom.size()){
            options.push_back(a);
            cout<<a<<endl;
            return;
        }
        string curr="";
        curr=curr+bottom[idx]+bottom[idx+1];
        for(int i=0;i<u[curr].size();i++){
            // cout<<u[curr][i]<<endl;
            call(bottom,options,a+u[curr][i],idx+1);
        }

        
        
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(auto it:allowed){
            string s="";
            s=s+it[0]+it[1];
            u[s].push_back(it[2]);
        }
        return dfs(bottom);
        
    }
};