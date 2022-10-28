class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=-1;
        int b=-1;
        int counta=0;
        int countb=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                counta++;
            }
            else if(nums[i]==b){
                countb++;
            }
            else if(counta==0){
                a=nums[i];
                counta++;
            }
            else if(countb==0){
                b=nums[i];
                countb++;
            }
            else{
                counta--;
                countb--;
            }
        }
        
        counta=0;
        countb=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                counta++;
            }
            else if(nums[i]==b){
                countb++;
            }
        }
        vector<int>ans;
        if(counta>n/3){
            ans.push_back(a);
        }
        if(countb>n/3){
            ans.push_back(b);
        }
        return ans;
    }
};
