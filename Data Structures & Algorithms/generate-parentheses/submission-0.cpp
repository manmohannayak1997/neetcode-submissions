class Solution {
    private:
    void backtrack(int n,vector<string> &res,string &combination , int open,int close){
        if(open == close && open == n)
        {
            res.push_back(combination);
            return;
        }
        if(open < n)
        {
            combination +="(";
            backtrack(n,res,combination,open+1,close);
            combination.pop_back();
        }
        if(close < open)
        {
            combination +=")";
            backtrack(n,res,combination,open,close+1);
            combination.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int open;
        int close;
        vector<string> res;
        string combination;
        backtrack(n,res,combination,0,0);
        return res;
        
    }
};
