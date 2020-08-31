/**
 * 
 * @param matrix int整型二维数组 the matrix
 * @param matrixRowLen int matrix数组行数
 * @param matrixColLen int* matrix数组列数
 * @return int整型
 */


int minPathSum(int** matrix, int matrixRowLen, int* matrixColLen ) {
    // write code here
    int row = matrixRowLen;
    int col = matrixColLen[0];
    int dp[row][col];
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < row; i++)
        dp[i][0] = matrix[i][0] + dp[i - 1][0];
    for (int i = 1; i < col; i++)
        dp[0][i] = matrix[0][i] + dp[0][i - 1];
    for (int i = 1; i < row; i++)
        for(int j = 1; j < col; j++)
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    return dp[row - 1][col - 1];
}   