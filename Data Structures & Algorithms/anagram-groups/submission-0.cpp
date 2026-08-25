class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            vector<int> counter(26,0);
            for(char ch:s){
                counter[ch-'a']++;
            }
            string key = to_string(counter[0]);
            for(int i=1;i<26;i++)
                key+=' '+to_string(counter[i]);
            mp[key].push_back(s);
        }
        for(auto &pair:mp){
            res.push_back(pair.second);
        }
        return res;
    }
};
