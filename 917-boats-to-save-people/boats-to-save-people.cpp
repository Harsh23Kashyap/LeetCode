class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int c=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                c++;
                i++,j--;
            }
            else
            {
                c++;
                j--;
            }
        }
        return c;
    }
};