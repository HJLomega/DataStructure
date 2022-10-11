#include <iostream>
using namespace std;
const int initcap=5;						//顺序表的初始容量
template <typename T>
class SqList								//顺序表泛型类
{
public:
	T *data;								//存放顺序表中元素
	int capacity;							//顺序表的容量 
	int length;   							//存放顺序表的长度
	SqList()								//构造函数
	{
		data=new T[initcap];				//为data分配初始容量大小的空间
		capacity=initcap;
		length=0;							//初始时置length为0
	}
	~SqList()								//析构函数
	{
		delete [] data;						//释放空间 
		
	}
	SqList(const SqList<T> &s)					//复制初始化构造函数 
	{
		capacity=s.capacity;
		length=s.length;
		data=new T[capacity];				//为当前顺序表分配空间
		for (int i=0;i<length;i++)
			data[i]=s.data[i];
	}	
	void CreateList(T a[],int n)			//由数组a中元素整体建立顺序表
	{
		for (int i=0;i<n;i++)
		{
			if(length==capacity)			//出现上溢出时
				recap(2*length);			//扩大容量
     		data[length]=a[i];
     		length++;                   	//添加后元素个数增加1
		}
	}
	void Add(T e)	        				//在线性表的末尾添加一个元素e
	{
		if (length==capacity)    			//顺序表空间满时倍增容量
			recap(2*length);
		data[length]=e;						//添加元素e
		length++;    						//长度增1
	}
	int Getlength()							//求顺序表的长度 
	{
		return length;
	}
	bool GetElem(int i, T &e)				//求序号为i的元素
	{
		if (i<0 || i>=length)
			return false;					//参数错误时返回false
		e=data[i];							//取元素值
		return true;						//成功找到元素时返回true
	}
	bool SetElem(int i,T e)             	//设置序号为i的元素
	{
		if (i<=0 || i>=length)				//参数错误时返回false
			return false; 
 		data[i]=e;
 		return true;
 	}
	int GetNo(T e)						    //查找第一个为e的元素的序号
	{ 
		int i=0;
 		while(i<length && data[i]!=e)
  			i++;							//查找元素e
		if (i>=length)						//未找到时返回-1
 			return -1;
		else
  			return i;						//找到后返回其序号
	}
	bool Insert(int i, T e)                 //在线性表中序号i位置插入元素e
	{
		if (i<0 || i>length)				//参数i错误返回false
			return false;
		if(length==capacity)		    	//满时倍增容量
			recap(2*length);
		for(int j=length;j>i;j--)			//将data[i]及后面元素后移一个位置
			data[j]=data[j-1];
		data[i]=e;			        		//插入元素e
 		length++;				        	//长度增1
 		return true;
 	}

	bool Delete(int i) 		        		//在线性表中删除序号i的元素
	{
		if (i<0 || i>=length)				//参数i错误返回false
			return false;
		for(int j=i;j<length-1;j++)
			data[j]=data[j+1];         		//将data[i]之后的元素前移一个位置
		length--;                           //长度减1
		if (capacity>initcap && length<=capacity/4)
 			recap(capacity/2);       		//满足缩容条件则容量减半
 		return true;
	}
	void DispList()							//输出顺序表L中所有元素
	{
		for (int i=0;i<length;i++)			//遍历顺序表中各元素值
			cout << data[i] << " ";
		cout << endl;
	}
private:
	void recap(int newcap)					//改变顺序表的容量为newcap
	{
		if (newcap<=0) return;
		T *olddata=data;
 		data=new T[newcap];					//分配新空间
 		capacity=newcap;					//更新容量 
 		for(int i=0;i<length;i++)			//复制
			data[i]=olddata[i];
		delete [] olddata;  				//释放旧空间
	}
};
	
/*
//main函数用作调试
int main()
{
	int i;
	char e;
	SqList<char> L;							//建立元素类型为int的顺序表对象L
	cout << "创建顺序表L" << endl;
	L.Insert(0,'1');							//插入元素1
	L.Insert(1,'3');							//插入元素3
	L.Insert(2,'1');							//插入元素1
	L.Insert(3,'5');							//插入元素5
	L.Insert(4,'4');							//插入元素4
	L.Insert(5,'2');							//插入元素2
	cout << "顺序表L:"; L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=3; L.GetElem(i,e);
	cout << "序号为" << i << "的元素:" << e << endl;
	e='1';
	cout << "第一个" << e << "的元素序号=" << L.GetNo(e) << "\n";
	i=2; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=0; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=1; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=1; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=0; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	cout << "销毁顺序表L" << endl;
	return 0;
}

//另外一个调试main 
int main()
{
	int i,e;
	SqList<int> L;							//建立元素类型为int的顺序表对象L
	cout << "创建顺序表L" << endl;
	L.Insert(0,1);							//插入元素1
	L.Insert(1,3);							//插入元素3
	L.Insert(2,1);							//插入元素1
	L.Insert(3,5);							//插入元素5
	L.Insert(4,4);							//插入元素4
	L.Insert(5,2);							//插入元素2
	cout << "顺序表L:"; L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=3; L.GetElem(i,e);
	cout << "序号为" << i << "的元素:" << e << endl;
	e=1;
	cout << "第一个" << e << "的元素序号=" << L.GetNo(e) << "\n";
	i=2; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=0; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=1; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=1; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	i=0; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "顺序表L:";L.DispList();
	cout << "长度:" << L.length << "  容量:" << L.capacity << endl;
	cout << "销毁顺序表L" << endl;
	return 0;
}
*/
