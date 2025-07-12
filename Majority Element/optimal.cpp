// Boyer-Moore Majority Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int el;

        for(int i = 0; i < nums.size(); i++){
            if(c == 0){
                c = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                c++;
            }
            else{
                c--;
            }
        }

        int c2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el){
                c2++;
            }
        } 

        if(c2  > nums.size() / 2){
            return el;
        }

        return -1;
    } 
};
