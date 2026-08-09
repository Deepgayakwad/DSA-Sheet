class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int n = nums.size();

        




        unordered_map<int,int>fre;
        for(int i = 0;i < n;i++){
              
              fre[nums[i]]++;
        }

        




        map<int,int>mpp;
        for(int i = 0;i < n;i++){
              
              int l = max(nums[i] - k,0);
              int r = nums[i] + k;
          
              mpp[l] += 1;

              mpp[r+1] -= 1;




        }

         
    for(int i = 0;i < n; i++){
              
              if(mpp.find(nums[i])==mpp.end()){
                  
                  mpp[nums[i]] = 0;
              }
        }



        int result = 1;
        int cum = 0;

        for(auto &it:mpp){
              

              cum = cum + it.second;
              it.second = cum;

              int total = it.second;
              int already = fre[it.first];

              int needConvert = total-already;

              int canConvert = min(needConvert,numOperations);

              result = max(result,canConvert + already);


        }


       return result;
        
    }
};