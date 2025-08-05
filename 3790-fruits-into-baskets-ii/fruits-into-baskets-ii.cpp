class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int i=0,j=0,c=0;
        unordered_set<int> u;
       for(int i=0;i<fruits.size();i++){
        bool found=false;
        for(int j=0;j<baskets.size();j++){
            if(u.find(j)==u.end() and baskets[j]>=fruits[i]){
                found=true;
                u.insert(j);
                break;
            }

        }
        if(!found)
            c++;
       }
        return c;
    }
};