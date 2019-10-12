class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int tmp = 0;
        for(auto it=nums.begin(); it!=nums.end();){
            if(it==nums.begin()){
                tmp = *it;
                it++;
                continue;
            }
            if(*it == tmp){
                it = nums.erase(it);
            }
            else{
                tmp = *it;
                it++;
            }
        }
        return nums.size();
    }
};
