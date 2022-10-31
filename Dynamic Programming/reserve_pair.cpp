class Solution {
public:
    
    int merge(vector<int>& nums,int s,int m,int e){
        
        int ans=0;
        int j=m+1;
        for(int i=s;i<=m;i++){
            while(j<=e && nums[i]>nums[j]*2LL){
                j++;
            }
            ans+=j-m-1;
        }
        
        vector<int> temp;
        int i=s;
         j=m+1;
        while(i<=m && j<=e){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m){
             temp.push_back(nums[i]);
                i++;
        }
          while(j<=e){
             temp.push_back(nums[j]);
                j++;
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
        return ans;
        
        
    }
    
    int mergesort(vector<int>& nums,int i,int j){
        if(i>=j){
            return 0;
        }
        int mid=(i+j)/2;
        int ans=mergesort(nums,i,mid);
        ans+=mergesort(nums,mid+1,j);
        ans+=merge(nums,i,mid,j);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size()-1;
        return mergesort(nums,0,n);
    }
};
