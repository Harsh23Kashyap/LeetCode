class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ns="";
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            // cout<<j<<" "<<i<<" "<spaces[i]<<endl;
            if(i<spaces.size() and j==spaces[i]){
                ns+=" ";
                i++;
            }

            ns+=s[j];
        }
        return ns;
    }
};