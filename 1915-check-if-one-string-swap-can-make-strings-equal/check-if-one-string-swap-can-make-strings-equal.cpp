class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        vector<int> vc;
        for(int i=0;i<s1.size();i++){
       if(s1[i]!=s2[i]){
        c++;
        vc.push_back(i);
       }
        }
        if(c==0)
        return true;

        if(c!=2)
        return false;
        // cout<<vc[0]<<" "<<vc[1]<<endl;
        if(s1[vc[0]]==s2[vc[1]] and s1[vc[1]]==s2[vc[0]])
        return true;

        return false;
    }
};