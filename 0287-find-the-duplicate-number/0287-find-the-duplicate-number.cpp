class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 ;
        int fast =0 ;
        int n = nums.size();
        // 1 . First detect cycle
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            
            if(slow == fast ){
                break;
            }
        }
        // 2. Meeting point of cycle
        slow = 0 ;
        while(slow != fast){
            slow = nums[slow];
            fast= nums[fast];
        }
        return slow;
    }
};