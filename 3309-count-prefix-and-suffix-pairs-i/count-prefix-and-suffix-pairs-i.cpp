class Solution {
public:
bool isValid(string s1,string s2){
    if(s1.size()>s2.size())
    return false;

    int i=0,j=0;
    while(i<s1.size() and j<s2.size()){
        if(s1[i]!=s2[j])
            return false;
        i++,j++;
    }

    if(i!=s1.size())
    return false;

    i=0,j=s2.size()-s1.size();
    while(i<s1.size() and j<s2.size()){
        if(s1[i]!=s2[j])
            return false;
        i++,j++;
    }

    if(i!=s1.size())
    return false;

    return true;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;

        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isValid(words[i],words[j]))
                c++;
            }
        }
        return c;
    }
};