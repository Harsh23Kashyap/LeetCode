class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="*123456789";
        vector<int> ans;
        string st=to_string(low);
        string end=to_string(high);
        int n=st.size();
        int firstChar=st[0]-'0';
        while(firstChar+n-1<s.size())
        {
            string firstWindow=s.substr(firstChar,n);
            if(stoi(firstWindow)>high) break;
            if(stoi(firstWindow)>=low)
            ans.push_back(stoi(firstWindow));
            firstChar++;
        }


        cout<<firstChar<<endl;
        for(int k=st.size()+1;k<=end.size();k++){
           cout<<k<<endl;
           int i=1;
           while(i+k-1<s.size()){
            string firstWindow=s.substr(i,k);
            if(stoi(firstWindow)>high) break;
            ans.push_back(stoi(firstWindow));
            i++;
           }

        }
        return ans;
        
    }
};