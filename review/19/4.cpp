/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地)构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {//未遍历
                    int aera = DFS(grid, i, j);
                    max = aera > max ? aera : max;
                }
            }
        }
        return max;
    }

    int DFS(vector<vector<int>>& grid, int x, int y) {
        int aera = 1;
        int m = grid.size();
        int n = grid[0].size();

        grid[x][y] = 10;//标记为已经遍历

        if (range_check(x - 1, y, m, n) && grid[x - 1][y] == 1) {
            aera += DFS(grid, x - 1, y);
        }
        if (range_check(x + 1, y, m, n) && grid[x + 1][y] == 1) {
            aera += DFS(grid, x + 1, y);
        }
        if (range_check(x, y - 1, m, n) && grid[x][y - 1] == 1) {
            aera += DFS(grid, x, y - 1);
        }
        if (range_check(x, y + 1, m, n) && grid[x][y + 1] == 1) {
            aera += DFS(grid, x, y + 1);
        }
        return aera;
    }
    bool range_check(int x, int y, int m, int n) {

        return x >= 0 && x < m&& y >= 0 && y < n;
    }
};