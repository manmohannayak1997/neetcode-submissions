class Solution {
    vector<string> res;
    vector<string> digittochar{"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
public:
    void backtrack(string &digits, const string &curstr , int index)
    {
        if(curstr.size() == digits.size())
        {
            res.push_back(curstr);
            return;
        }
        string key = digittochar[digits[index]-'0'];
        for(auto c:key)
        {
            backtrack(digits,curstr + c , index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0 )
            return res;
        backtrack(digits,"",0);
        return res;
    }
};
