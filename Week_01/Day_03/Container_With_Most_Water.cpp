class Solution {
public:
    int maxArea(vector<int>& height) {
       int l=0,r=height.size()-1;
       int maxi =0;
       while(l<r){
        int area = (r-l) * min(height[r],height[l]);
          maxi = max(maxi, area);
          if(height[l]>height[r]){
            r--;
          }else{
            l++;
          }
       }
       return maxi;
    }
};
