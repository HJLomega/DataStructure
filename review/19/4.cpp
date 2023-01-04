/*
����һ����СΪ m x n �Ķ����ƾ��� grid ��

���� ����һЩ���ڵ� 1 (��������)���ɵ���ϣ�����ġ����ڡ�Ҫ������ 1 ������ ˮƽ������ֱ���ĸ������� ���ڡ�����Լ��� grid ���ĸ���Ե���� 0������ˮ����Χ�š�

���������ǵ���ֵΪ 1 �ĵ�Ԫ�����Ŀ��

���㲢���� grid �����ĵ�����������û�е��죬�򷵻����Ϊ 0 ��
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
                if (grid[i][j] == 1) {//δ����
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

        grid[x][y] = 10;//���Ϊ�Ѿ�����

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