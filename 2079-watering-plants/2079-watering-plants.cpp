class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int s=0,cap=capacity;
        for(int i=0;i<plants.size();i++)
        {
            if(plants[i]<=cap)
            {
                s++;
                cap-=plants[i];
            }
            else
            {
                cap=capacity-plants[i];
                s+=i+i+1;
            }
            //cout<<"After "<<plants[i]<<" steps-"<<s<<endl;
        }
        return s;
        
    }
};