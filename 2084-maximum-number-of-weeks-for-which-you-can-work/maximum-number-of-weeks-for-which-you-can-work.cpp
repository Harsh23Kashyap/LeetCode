class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
       long long  maxi=*max_element(milestones.begin(),milestones.end());
       long long  sum=accumulate(milestones.begin(),milestones.end(),0ll);

        long long rem=sum-maxi;

        if(maxi<=rem)
        return sum;

        return 2*rem+1;

        


    }
};