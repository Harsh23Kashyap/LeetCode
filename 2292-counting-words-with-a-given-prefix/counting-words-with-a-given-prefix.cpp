class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int c=0;

        for(auto it:words){
            if(it.size()< pref.size())
            continue;

            int i=0,j=0;
            bool found=true;
            while(i<it.size() and j<pref.size())
            {
                if(it[i]!=pref[j])
                    {
                        found=false;
                        break;
                    }
                i++,j++;
            }
            if(found and j==pref.size())
                c++;
        }
        return c;
    }
};