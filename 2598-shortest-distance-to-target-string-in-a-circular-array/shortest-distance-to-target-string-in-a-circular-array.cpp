class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(target==words[startIndex])
        return 0;
        int l=startIndex,r=startIndex;
        int c=0;
        do{ 
             r=(r+1)%words.size();
            l=(l==0)?words.size()-1:l-1;
            c++;
            if(words[l]==target or words[r]==target)
                return c;
            
           
        }while(l!=r);
        return -1;
    }
};