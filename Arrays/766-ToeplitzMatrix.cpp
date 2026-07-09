class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i, j ,x,y;

        for(i=0;i<n;i++){
            j=0;
            x = i, y=j;
            while((x+1)<n && (y+1)<m){
                if(matrix[x][y] != matrix[x+1][y+1])
                return false;
                x+=1;y+=1;
            }
        }
        for(j=1;j<m;j++){
            i=0;
            x= i, y=j;
            while((x+1)<n && (y+1)<m){
                if(matrix[x][y] != matrix[x+1][y+1])
                return false;
                x+=1;y+=1;
            }
        }
        return true;
    }
};
