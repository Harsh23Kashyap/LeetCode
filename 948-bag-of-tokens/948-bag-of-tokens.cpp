class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0,maxi=0;
        bool runs=true;
        while(i<=j and runs)
        {
           // cout<<power<<endl;
            runs=false;
            if(tokens[i]<=power)
            {
                power-=tokens[i++];
                score++;
                runs=true;
            }
            else 
            {
                if(score>0)
                {
                    power+=tokens[j--];
                    score--;
                    runs=true;
                }
            }
            maxi=max(maxi,score);
        }
        return maxi;
    }
};