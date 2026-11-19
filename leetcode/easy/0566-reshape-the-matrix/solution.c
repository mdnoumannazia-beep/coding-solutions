#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];

    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(sizeof(int) * m);
        int** res = (int**)malloc(sizeof(int*) * m);

        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = matColSize[i];
            res[i] = (int*)malloc(sizeof(int) * matColSize[i]);
            for (int j = 0; j < matColSize[i]; j++) {
                res[i][j] = mat[i][j];
            }
        }
        return res;
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    int** ans = (int**)malloc(sizeof(int*) * r);

    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        ans[i] = (int*)malloc(sizeof(int) * c);
    }

    int total = m * n;
    for (int idx = 0; idx < total; idx++) {
        ans[idx / c][idx % c] = mat[idx / n][idx % n];
    }

    return ans;
}