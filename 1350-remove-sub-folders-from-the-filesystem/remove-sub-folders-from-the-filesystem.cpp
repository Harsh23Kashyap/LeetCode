class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> u(folder.begin(),folder.end());
        vector<string> ans;
        for(auto dir:folder){
            string check="";
            bool found=false;
            for(auto it:dir){
                if(it=='/'){
                    if(u.find(check)!=u.end()){
                        found=true;
                        break;
                    }
                }
                check+=it;
            }
            if(!found){
                ans.push_back(dir);
            }
        }
        return ans;

    }
};