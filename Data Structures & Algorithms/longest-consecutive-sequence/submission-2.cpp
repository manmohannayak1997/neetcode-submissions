class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        int res = 0;
        int length,element;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                length = 1;
                element = nums[i];
                 while(s.find(element+1)!=s.end())
            {
                element++;
                length++;
            }
            res = max(res,length);
            }
           
        }
        return res;
    }
};
