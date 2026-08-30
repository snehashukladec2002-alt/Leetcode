class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minidx =0;
        int maxidx = 0;

        for(int i =0;i<n;i++){
            if(nums[i]<nums[minidx]){
                minidx =i;
            }
            if(nums[i]>nums[maxidx]){
                maxidx = i;
            }
        }
        int first = min(minidx,maxidx);
        int second = max(minidx,maxidx);

        int case1 = second +1;
        int case2 = n-first;
        int case3 = first+1+n-second;

        return min({case1,case2,case3});
        
    }
};