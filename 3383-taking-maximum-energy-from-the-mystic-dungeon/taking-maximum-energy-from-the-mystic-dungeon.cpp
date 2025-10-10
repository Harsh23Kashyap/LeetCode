class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> maxi(energy.size(),-1);

        for(int i=energy.size()-1;i>=0;i--){
            maxi[i]=((i+k<energy.size())?maxi[i+k]:0)+energy[i];
        }
        return *max_element(maxi.begin(),maxi.end());
    }
};
