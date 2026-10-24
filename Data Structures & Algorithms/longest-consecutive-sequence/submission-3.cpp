class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 0;
        for(auto num:nums)
        {
            if(s.find(num-1)==s.end())
                {int length = 1;
                while(s.find(num+length) != s.end())
                {
                    length++;
                }

                res = max(res,length);
                }
        }
        return res;
    }
};
