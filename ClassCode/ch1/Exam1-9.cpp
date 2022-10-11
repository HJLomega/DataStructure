#include<iostream>
using namespace std;
template <typename T>
class Array
{
	T *data;					//T为类型参数
	int length;
public:
	Array(int n=1)				//构造函数
	{	data=new T[n];			//为动态数组分配内存空间
		length=0;
	}
	~Array()					//析构函数
	{
		delete [] data;
	}
	void add(T x)				//添加一个元素x
	{
		data[length]=x;
		length++;
	}		
	void display()
	{	for (int i=0;i<length;i++)
			cout << data[i] << " ";
		cout << endl;
	}
};
int main()
{
	Array<char> ac(3);			//定义模板类的对象ac
	ac.add('x');
	ac.add('y');
	ac.add('z');
	cout << "ac: ";
	ac.display();				//输出: x y z 

	Array<int> ai(5);			//定义模板类的对象ai
	ai.add(1);
	ai.add(2);
	ai.add(3);
	ai.add(4);
	ai.add(5);
	cout << "ai: ";
	ai.display();				//输出: 1 2 3 4 5
	return 0;
}

