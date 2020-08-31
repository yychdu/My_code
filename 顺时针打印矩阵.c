/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrix == NULL || matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * matrixColSize[0];
    int *res = calloc(*returnSize, sizeof(int));

    int i = 0;
    int urow, rcol, drow, lcol, r, c;
    urow = -1;
    lcol = -1;
    drow = matrixSize;
    rcol = matrixColSize[0];

    while (i < *returnSize) {
        //right
        r = urow + 1;
        for (c = lcol + 1; i < *returnSize && c < rcol; c++) {
            res[i] = matrix[r][c];
            i++;
        }
        urow++;

        //down
        c = rcol - 1;
        for (r = urow + 1; i < *returnSize && r < drow; r++) {
            res[i] = matrix[r][c];
            i++;
        }
        rcol--;

        //left
        r = drow - 1;
        for (c = rcol - 1; i < *returnSize && c > lcol; c--) {
            res[i] = matrix[r][c];
            i++;
        }
        drow--;

        //up
        c = lcol + 1;
        for (r = drow - 1; i < *returnSize && r > urow; r--) {
            res[i] = matrix[r][c];
            i++;
        }
        lcol++;
    }

    return res;
}


作者：cuizhigang
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/zhe-shi-yi-dao-teng-xun-de-mian-shi-ti-by-cuizhiga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。