class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        int fd=0;
        int st=0,end=0;
        for(int i=0;i<meetings.size();i++){
           

            if(meetings[i][0]>end){
                fd+=meetings[i][0]-end-1;

            }
            end=max(meetings[i][1],end);
        }
        return fd+(days-end);
    }
};