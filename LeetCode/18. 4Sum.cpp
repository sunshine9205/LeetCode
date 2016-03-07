class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > out;
        set<vector<int> > ret;
        if(nums.size()<4) return out;
        
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-3;++i){
            for(int j = i+1;j<nums.size()-2;++j){
                int l = j+1,r = nums.size()-1;
                while(l<r){
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ret.insert(v);
                        ++l;
                        --r;
                    }
                    else if(sum<target) {
                        ++l;
                    }
                    else{
                        --r;
                    }
                }
            }
        }
    
        set<vector<int> >::iterator it;
        for(it=ret.begin();it!=ret.end();it++){
            out.push_back(*it);
        }
    
        return out;
    }
};