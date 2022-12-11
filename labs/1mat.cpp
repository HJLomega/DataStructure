#include <fstream>
#include <iostream>
#include <vector>
/*
����һ��m��n������������������һ��x��y���Ӿ���ʹ�Ӿ���������Ԫ�صĺ����
*/
//�����ⷨ�����Ż�
using namespace std;
int sum(vector<vector<int> > mat,int i0,int j0,int n,int x,int y) {
	int result = 0;
	for (int i = i0; i < i0 + x; i++) {
		for (int j = j0; j < j0 + y; j++) {
			result += mat[i][j];
		}
	}
	return result;
}
int main() {
	ifstream f("in.txt");

	//��mnxy
	int m, n, x, y;
	f >> m;
	f >> n;
	f >> x;
	f >> y;
	if (!f.is_open()) {
		cout << "Could not open the file\n";
		return -1;
	}
	//������
	vector<int > temp(n, 0);
	vector<vector<int> > mat(m,temp);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			f>>num;
			mat[i][j] = num;
		}
	}

	//������Ӿ���
	int max = 0;
	for (int i = 0; i < m - x + 1; i++) {
		for (int j = 0; j < n - y + 1; j++) {
			int temp = sum(mat, i, j, n, x, y);
			max = temp > max ? temp : max;
		}
	}
	cout<<max;
}