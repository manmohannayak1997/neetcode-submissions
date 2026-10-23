class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
       vector<vector<string>> res;
       

       for(auto s:strs)
       {
        vector<int> counter(26,0);
        string key = "";
        for(auto c:s)
        {
            counter[c-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            key+=to_string(counter[i]);
            key+="*";
        }
        mp[key].push_back(s);
       }
       for(auto ele:mp)
       {
        res.push_back(ele.second);
       }

       return res;
    }
};
