class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
    // base conditions
        vector<int> ans;
        int len=(words[0].size())*words.size();
        if(len>s.size()||s.length()==0||words.size()==0)
        {
            return ans;
        }
        // word ka arrangement karlo 
        // sliding window ek bnana padega words[0].size *words.size()
        
        // create a map of words
        unordered_map<string,int>mp1;
        for(int i=0;i<words.size();i++)
        {
            mp1[words[i]]++;
        }
        // creating running map to store worsd[0].size() * words.size() lenght sliding window to accomodate all words
        
        unordered_map<string,int>mp2;
        int inc=words[0].size();
        
        
         for(int i=0;i<=s.size()-len;i++)
         {
             bool flag=false;
             for(int j=i;j<i+len;j=j+inc)
             {
                 string temp=s.substr(j,inc);
                 mp2[temp]++;
                 // checking that two map is equal or not of sliding window of lenght=len
                 if(mp2==mp1)
                 {
                     flag=true;
                 }
             }
             if(flag==true)
             {
                 ans.push_back(i);
             }
             mp2.clear();
         }
        return ans;
    }    
};
