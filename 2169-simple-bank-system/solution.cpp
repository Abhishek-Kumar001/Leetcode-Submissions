class Bank {
private:
    vector<long long> bankBalance;
    int noOfAccounts = 0; 
public:
    Bank(vector<long long>& balance) {
        int n = balance.size();
        noOfAccounts = n;
        bankBalance = balance;
        for(int i=0; i<n; i++) bankBalance[i] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > noOfAccounts) return false;
        if(account2 < 1 || account2 > noOfAccounts) return false;

        if(bankBalance[account1-1] >= money){
            bankBalance[account1-1] -= money;
            bankBalance[account2-1] += money;
            return true;
        } 
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > noOfAccounts) return false;

        bankBalance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > noOfAccounts) return false;
 
        if(bankBalance[account-1] >= money){        
           bankBalance[account-1] -= money;
           return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
