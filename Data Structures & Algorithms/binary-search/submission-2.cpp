class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size();
        
        int l = 0;
        /*
        [-1,0,2,4,6,8]

        if mid is  idnex 2, num 2 

        right = idnex 5 num 8

        l = idnes 0 so -1 
        if nums[m] >= target;


        */        
        while( l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target ){
                r=mid;
            }else{
                l = mid+1;
            }
        }
        if (l < nums.size() && nums[l] == target){
            return l;
        }
    return  -1;
    }
};
