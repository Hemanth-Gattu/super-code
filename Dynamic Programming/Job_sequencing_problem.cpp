struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static comp(Job a,Job b){
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int dp[101];
        memset(dp,-1,sizeof(dp));
        int sum=0;
        int job_count=0;
        for(int i=0;i<n;i++){
            int job_deadline=arr[i].dead-1;
            int job_profit=arr[i].profit;
            
            // cout<<job_deadline<<" "<<dp[job_deadline]<<endl;
            if(dp[job_deadline]==-1){
                dp[job_deadline]=job_profit;
                sum+=job_profit;
                job_count++;
            }
            else{
                
                while(job_deadline>=0 && dp[job_deadline]!=-1){
                    job_deadline--;
                }
                if(job_deadline>=0){
                    dp[job_deadline]=job_profit;
                sum+=job_profit;
                job_count++;
                }
            }
        }
        vector<int>ans;
        ans.push_back(job_count);
        ans.push_back(sum);
        return ans;
        
    } 
};
