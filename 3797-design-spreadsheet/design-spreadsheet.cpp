class Spreadsheet {
public:
unordered_map<string,int> u;
int row=0;
    Spreadsheet(int rows) {
        row=rows;
    }
    
    void setCell(string cell, int value) {
        if(!isPossible(cell))
        return;

        u[cell]=value;
    }
    
    void resetCell(string cell) {
        if(u.find(cell)!=u.end() and isPossible(cell))
            u[cell]=0;
    }
    
    int getValue(string formula) {
        stringstream ss(formula.substr(1));
        string item;
        int ans=0;
         while (getline(ss, item, '+')) {   
            if(item[0]>='A' and item[0]<='Z'){
                 if(u.find(item)!=u.end() and isPossible(item))
                    ans+=u[item];
                else
                    ans+=0;
            }
            else
            {
                int temp=stoi(item);
                ans+=temp;
            }
        }
    return ans;

        
    }

    bool isPossible(string cell){
        int tot=0;
        for(int i=0;i<cell.size();i++){
            if(cell[i]>='A' and cell[i]<='Z'){
                continue;
            }
            else{
                int c=cell[i]-'0';
                tot=tot*10+c;

            }
        }
        return tot<=row;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */