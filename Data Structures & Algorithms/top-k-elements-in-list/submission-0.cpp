class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> res;
        for(int n:nums){
            mp[n]++;
        }
        for(auto pr:mp)
        {
            q.push({pr.second,pr.first});
            if(q.size()>k)
                q.pop();
        }
        for(int i=0;i<k;i++)
        {
            pair<int,int> p = q.top();
            res.push_back(p.second);
            q.pop();
        }
        return res;
    }
};