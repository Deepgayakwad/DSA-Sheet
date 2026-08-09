class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
          int maxi = *max_element(nums.begin(),nums.end());

          vector<int>diff(maxi+k+1,0);

          for(int i = 0;i < nums.size();i++){
               
                int l = max(nums[i] - k,0);
                int r = nums[i] + k;

                diff[l] += 1;
                
                if(r+1 < maxi+k+1){
                      
                      diff[r+1] -= 1;
                }
          }

          int cum = 0;
          for(int i = 0; i < maxi+k+1;i++){
             
                  cum = cum + diff[i];
                  diff[i] = cum;
          }

          unordered_map<int,int>mpp;
          for(int i = 0 ; i < nums.size();i++){
              
                mpp[nums[i]]++;
          }

          int result = 1;

          for(int i = 0;i < maxi+k+1;i++){
              
                 int total = diff[i];
                 int already = 0;
                 if(mpp.find(i)!=mpp.end()){
                      
                       already = mpp[i];
                 }

                 int needConvert = total-already;
                 int canConvert = already + min(needConvert,numOperations);
                 result = max(result,canConvert);
          }

          return result;

    }
};