class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int curr=0;
        for(auto it:commands)
        {
            if(it=="RIGHT")
                curr++;
            else if(it=="LEFT")
                curr--;
            else if(it=="DOWN")
                curr+=n;
                else
                    curr-=n;
        }
        return curr;
    }
};