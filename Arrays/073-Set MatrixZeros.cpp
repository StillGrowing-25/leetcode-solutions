//Brute force
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<vector<int>> vector;
//         for(int i =0; i<matrix.size(); i++){
//             for(int j =0; j<matrix[0].size();j++){
//                 if(matrix[i][j]==0)
//                 vector.push_back({i,j});
//             }
//         }
//         for(const auto& row: vector){
//             for(int i =0; i<matrix.size();i++)
//                 matrix[i][row[1]] = 0;
//             for(int j = 0; j<matrix[0].size();j++)
//                 matrix[row[0]][j] = 0;
//         }
//     }
// };
//Optimal solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
          // Zero the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
