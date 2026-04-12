class Solution {
public:
string w; 
    int pass(int i, int j, int k, vector<vector<vector<int>>> &dp){
        if(k==w.size())
        return 0;

        if(dp[i+1][j+1][k]!=-1)
        return dp[i+1][j+1][k];
        

        //to options, use my left hand
        int pos=w[k]-'A';
        int x=pos/6,y=pos%6;

        int left=pass(pos,j,k+1,dp);
        int right=pass(i,pos,k+1,dp);

        int costLeft=-0;
        if(i!=-1){
            int oldx=i/6,oldy=i%6;
            costLeft=abs(oldx-x)+abs(oldy-y);

        }
        int costRight=-0;
        if(j!=-1){
            int oldx=j/6,oldy=j%6;
            costRight=abs(oldx-x)+abs(oldy-y);
            
        }

        return dp[i+1][j+1][k]=min(costLeft+left,costRight+right);
    }
    int minimumDistance(string word) {
        w=word;


        vector<vector<vector<int>>> dp(27, vector<vector<int>> (27, vector<int> (word.size()+1,-1)));

        return pass(-1,-1,0,dp);
    }
};