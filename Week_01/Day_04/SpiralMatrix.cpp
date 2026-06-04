class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
      int m = matrix.size();
      int n = matrix[0].size();
      int left =0, top =0;
      int bottom = m-1, right = n-1;
      
      while(top<=bottom && left <=right){
        for(int i = left; i<=right; i++){
            nums.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++){
            nums.push_back(matrix[i][right]);
        }
        right--;
        
        if(bottom>=top){
            for(int i = right; i>=left; i--){
                nums.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        if(right>=left){
            for(int i=bottom; i>=top; i--){
                nums.push_back(matrix[i][left]);
            }
            left++;
        }
      }
      return nums;  
    }
};
