class Cashier {
public:
    unordered_map<int,int> pro;
    int cn;
    int no;
    int disc;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        
        no=n;
        cn=n;
        for(int i=0;i<products.size();i++)
            pro[products[i]]=prices[i];
        
        
        disc=discount;
        
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        double total=0;
        for(int i=0;i<product.size();i++)
        {
            
            total+=pro[product[i]]*amount[i];
        }
        if(cn==1)
        {
            cn=no;
            return total*0.01*(100-disc);
        }
        cn--;
        return total;
        
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */