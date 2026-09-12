class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(),nums.end());
        generate(0,nums,path,res);
        return res;
        
    }
private:
    void generate(int index , vector<int> &nums , vector<int> &path , vector<vector<int>> &res){
        if(index == nums.size()){
            res.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        generate(index+1,nums,path,res);
        path.pop_back();
        while(index+1 < nums.size() && nums[index] == nums[index+1])
            index++;
        generate(index+1,nums,path,res);
    }
};
