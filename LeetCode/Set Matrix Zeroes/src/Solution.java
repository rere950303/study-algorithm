//
// Matrix(Set Matrix Zeroes)
// https://leetcode.com/problems/set-matrix-zeroes/
// Created by hyungwook on 2022/03/11.
//

public class Solution {

    public void setZeroes(int[][] matrix) {
        boolean rZero = false;
        boolean cZero = false;
        int m = matrix.length;
        int n = matrix[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i == 0) {
                        rZero = true;
                    }
                    if (j == 0) {
                        cZero = true;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (rZero) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (cZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
