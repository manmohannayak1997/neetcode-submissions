class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
                vector<int> res(nums.size(),1);
        int postfix = 1 ;
        int prefix = nums[0] ;
        for(int i=1;i<nums.size();i++)
        {
           
            res[i] = prefix;
            prefix*=nums[i];
            
        }
        for(int i :res)cout<<i<<"\t";
        for(int i=nums.size()-1;i>=0;i--)
        {
           
            res[i] = res[i]*postfix;
            postfix*=nums[i];
        }
        for(int i :res)cout<<"\n"<<i<<"\t";
        return res;

    }
};
