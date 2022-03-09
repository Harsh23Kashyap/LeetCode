class Solution {
public:
    bool same(vector<int>& p1, vector<int>& p2)
    {
        return p1[0]==p2[0] and p1[1]==p2[1];
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        if(same(p1,p2) or same(p2,p3) or same(p3,p4) or same(p4,p1) or same(p1,p3) or same(p2,p4))
            return false;
        int d1=pow(p2[0]-p1[0],2)+pow(p2[1]-p1[1],2);
        int d2=pow(p3[0]-p2[0],2)+pow(p3[1]-p2[1],2);
        int d3=pow(p4[0]-p3[0],2)+pow(p4[1]-p3[1],2);
        int d4=pow(p1[0]-p4[0],2)+pow(p1[1]-p4[1],2);
        int d5=pow(p1[0]-p3[0],2)+pow(p1[1]-p3[1],2);
        int d6=pow(p2[0]-p4[0],2)+pow(p2[1]-p4[1],2);
        
        set<int> s;
        s.insert(d1);
        s.insert(d2);
        s.insert(d3);
        s.insert(d4);
        s.insert(d5);
        s.insert(d6);
        
        return s.size()==2;
        
       
        
        
        
        
        
    }
};