class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        bool runs=true;
        int sc=0;
        int best=0;
        while(i<=j and runs){
            runs=false;
            if(power>=tokens[i]){ 
                sc++;
                power-=tokens[i];
                runs=true;
                i++;
            }
            else{
                if(sc>=1){
                    sc--;
                    power+=tokens[j];
                    j--;
                    runs=true;
                }
            } 
            best=max(best,sc);
        }
        return best;
    }
};