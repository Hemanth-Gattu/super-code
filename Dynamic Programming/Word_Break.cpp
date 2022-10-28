public:
    
    int solve(string A,unordered_map<string,int>mp){
        int s=A.size();
        if(s==0){
            return 1;
        }
        if(mp[A]){
            return 1;
        }
        for(int i=1;i<s;i++){
            string a=A.substr(0,i);
            string b=A.substr(i);
            if(mp[a]&& solve(b,mp)==1){
                return 1;
            }
        }
        return 0;
    }

    int wordBreak(string A, vector<string> &B) {
        unordered_map<string,int>mp;
        for(int i=0;i<B.size();i++){
            mp[B[i]]=1;
        }
        return solve(A,mp);
    }
