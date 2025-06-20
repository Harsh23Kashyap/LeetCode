class Solution {
public:
    int maxDistance(string st, int k) {
       int n=0,s=0,e=0,w=0;
       int dx=0,dy=0;
       int maxi=0;
      
       int maxdist=0;
       for(int i=0;i<st.size();i++){
            switch(st[i]){
                case 'N':
                    n++;
                    break;
                 case 'E':
                    e++;
                    break;
                 case 'W':
                    w++;
                    break;
                 case 'S':
                    s++;
                    break;

            }
            int td=min(min(n,s),k);
            int lr=min(min(e,w),k-td);

            maxdist=max(maxdist, abs(n-s)+td*2+abs(e-w)+lr*2);


       }

       return maxdist;

    }
};
