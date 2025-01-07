class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for(int i=0;i<words.size();i++){
            string it=words[i];
            for(int j=0;j<words.size();j++)
            {
                int found = words[j].find(it);
                if (i!=j and found != string::npos)
                {
                    ans.push_back(it);
                    break;
                } 
            }
        }
        return ans;
    }
};