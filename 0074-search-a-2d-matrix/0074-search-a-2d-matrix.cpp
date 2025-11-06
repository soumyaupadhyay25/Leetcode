class Solution {
public:
    bool searchMatrix(vector<vector<int>>& vec, int target) {
        
// Index= (row_index * colm) + (colm_index)

// row_index = Index/colm
// colm_index = Index%colm

// Index is from 0 to (row*colm)-1
int row=vec.size(),colm=vec[0].size();
int left=0;
int right=(row*colm)-1;
int i,j;

int mid;
while(left<=right){
    mid=left+((right-left)/2);
    i=mid/colm;
    j=mid%colm;
    
    if(vec[i][j]==target) return true;
    else if(vec[i][j]>target) right=mid-1;
    else left=mid+1; 
}

return false;
        
    }
};