class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> out(nums.size()-k+1);
        d.push_back(nums[0]);
        for(int i=1;i<k;i++){
            while(!d.empty() && d.back()<nums[i]){
                d.pop_back();
            }
            d.push_back(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            out[i-k]=d.front();
            if(nums[i-k]==d.front()){
                d.pop_front();
            }
            while(!d.empty() && d.back()<nums[i]){
                d.pop_back();
            }
            d.push_back(nums[i]);
        }
        out[nums.size()-k] = d.front();
        return out;
    }
};