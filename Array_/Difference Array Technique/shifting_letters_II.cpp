class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();

        // step1 create a difference array
        vector<int>diff(n,0);

        for(auto query:shifts){
               
                int l = query[0];
                int r = query[1];

                int dir = query[2];

                int x;
                if(dir == 1){
                    x = 1;
                }
                else{
                     x = -1;
                }

                diff[l] += x;

                if(r + 1 < n){
                     diff[r+1] -= x;
                }
        }


        // step 2 create a cummulative sum array
        for(int i = 1; i <n;i++){
              diff[i] = diff[i-1] + diff[i];
        }

        // step 3 shift the chacters

        for(int i = 0;i < n;i++){
              
                int shift = diff[i] % 26;

                if(shift < 0){
                     shift += 26;
                }

                int value = ((s[i] - 'a') + shift) % 26;
                s[i] = 'a' + value;
        }

        return s;
        
    }
};