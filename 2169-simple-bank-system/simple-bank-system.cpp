class Bank {
public:
vector<long long> balances;
    Bank(vector<long long>& balance) {
        balances=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!validAccount(account1) or !validAccount(account2) )
        return false;
        if(money>balances[account1-1])
            return false;

        balances[account1-1]-=money;
        balances[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
         if(!validAccount(account))
        return false;
        balances[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccount(account))
        return false;
        cout<<account<<" "<<money<<endl;
        if(money>balances[account-1])
            return false;

        balances[account-1]-=money;
        return true;
    }
    private:
     bool validAccount(int account){
        return account<=balances.size() and account>=1;

    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */