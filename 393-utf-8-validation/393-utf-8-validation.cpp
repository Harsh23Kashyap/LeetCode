class Solution {
public:
    bool validUtf8(vector<int>& data) 
    {
        int len = data.size();
        int cur = -1,i=0;
        for(;i<len;i++){
            if (data[i]<=127&&data[i]>=0)continue; // if data[i] is 1 byte
            else if(data[i]<=223&&data[i]>=192)cur=1; // if data[i] is 2 bytes
            else if(data[i]<=239&&data[i]>=224)cur=2; // if data[i] is 3 bytes
            else if(data[i]<=247&&data[i]>=240)cur=3; // if data[i] is 4 bytes
            else return 0; 
            if(i+cur>=len)return 0; // checking if n-1 characters exist
			// checking n-1 characters
            while(cur--){ 
                i++;
				 // checking in [128,191]
                if(data[i]<128||data[i]>191)return 0;
            }
        }
        return 1;
        
    }
};