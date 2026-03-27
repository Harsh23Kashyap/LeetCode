class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int l=0,r=h.size()-1;
        int c=0;
        int ml=0,mr=0;
        while(l<=r){
            if(h[l]<=h[r]){
                if(ml<h[l])
                ml=h[l];
                else
                c+=ml-h[l];
                l++;
            }
            else{
                if(mr<h[r])
                mr=h[r];
                else
                c+=mr-h[r];
                r--;
            }
        }
        return c;
        
    }
};