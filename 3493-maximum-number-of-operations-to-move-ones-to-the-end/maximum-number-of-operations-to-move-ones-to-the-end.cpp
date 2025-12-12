class Solution {
public:
    int maxOperations(string s) {
        int ans=0,one=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one++;
            bool done=false;
            while(i+1<s.size() and s[i+1]=='0')
            {
                done=true;
                i++;
            }
            if(done){
                ans+=one;
            }
        }
       }
       return ans;



    }
};

/*
100110101.  ans=0, one=0
001110101    ans=1 one =1
001110101.    ans=1 one =3
000111101.    ans=4 one =3
000111101.    ans=4 one =4
             ans=8 one =4
*/