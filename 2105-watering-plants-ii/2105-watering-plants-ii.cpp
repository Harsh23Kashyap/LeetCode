class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int ba=0,capA=capacityA,capB=capacityB;
        int i=0,j=plants.size()-1;
        while(i<=j)
        {
            if(i!=j)
            {
                if(plants[i]<=capA)
                    capA-=plants[i];
                else
                {
                    ba++;
                    capA=capacityA-plants[i];
                }
                if(plants[j]<=capB)
                    capB-=plants[j];
                else
                {
                    capB=capacityB-plants[j];
                    ba++;
                }
                i++,j--;
                
            }
            else
            {
                if(plants[i]<=capA or plants[i]<=capB)
                    break;
                else
                {
                    ba++;
                     break;
                }
            }
        }
        return ba;
        
    }
};