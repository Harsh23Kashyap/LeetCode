class Solution {
public:
unordered_map<string,string> parent;
string find(string x){
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}
void unite(string a, string b){
    string pa=find(a);
    string pb=find(b);
    parent[pb]=pa;
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, string> names;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
               parent[accounts[i][j]]=accounts[i][j];
            }
        }

        for(int i=0;i<accounts.size();i++){
            string n=accounts[i][0];
            string p=accounts[i][1];
            names[p]=n; 
            for(int j=2;j<accounts[i].size();j++){
                unite(accounts[i][j],p);
                names[accounts[i][j]]=n;
            }
        }

        unordered_map<string, set<string>> mails;
         for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
               string myprent=find(accounts[i][j]);
               mails[myprent].insert(accounts[i][j]);
            }
        }


        vector<vector<string>> ans;
        for(auto it:mails){
            string n=names[it.first];
            vector<string> curr;
            curr.push_back(n);
            for(auto nit:it.second)
                curr.push_back(nit);
            ans.push_back(curr);
        }
        return ans;

        
    }
};