class Solution {
public:
    bool diff(double a){
        return abs(a-24.0)<1e-5;
    }
    vector<double> compute(double a, double b){
        return {a+b,a-b,a*b,a/b};
    }
    bool backtrack(vector<double> c){

        if(c.size()==1){
            return diff(c[0]);
        }

        for(int i=0;i<c.size();i++){
            for(int j=0;j<c.size();j++){
                if(i==j)
                continue;

                vector<double> maths=compute(c[i],c[j]);

                for(int k=0;k<maths.size();k++){
                    vector<double> res;
                    res.push_back(maths[k]);

                    for(int l=0;l<c.size();l++){
                        if(l==i or l==j)
                        continue;

                        res.push_back(c[l]);
                    }

                    if(backtrack(res))
                        return true;
                    
                }
            }
        }
        return false;
        
        
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> cc(cards.begin(),cards.end());
        return backtrack(cc);
    }
};