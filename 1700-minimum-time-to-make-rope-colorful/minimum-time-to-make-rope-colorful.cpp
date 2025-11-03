class Solution {
public:

    int minCost(string colors, vector<int>& neededTime) {

      int i=0, j=0;
      int n = colors.size();
      int minTime = 0;
   
      while(i<n && j<n)
      {
         int maxTime=0;
         int curTotal=0;

         while(j<n && colors[i] == colors[j])
         {
          maxTime = max(maxTime, neededTime[j]);
          curTotal += neededTime[j];
          j++;
         }

        i = j;
        minTime += (curTotal- maxTime);
      }
        return minTime;
    }
};