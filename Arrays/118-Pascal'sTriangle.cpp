class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1));
        }

        for (int i = 0; i < numRows; i++) {
            int j = 0;
            if (j == 0)
                ans[i][0] = 1;
            while (j < i - 1) {
                ans[i][j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
                j++;
            }
            if (i != 0)
                ans[i][i] = 1;
        }
        return ans;
    }
};
