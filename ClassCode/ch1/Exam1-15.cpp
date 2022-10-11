#include <iostream>
using namespace std;
const int MaxSize=100;                     	//集合的最多元素个数(常数)
class Set								 	//集合类
{
	int *data;			  					//data存放集合元素
	int length;		                    	//length为集合的长度
public:
	Set()									//构造函数 
	{	
		data=new int[MaxSize];			  	//data存放集合元素
		length=0;		                    //length为集合的长度
	}
	~Set()									//析构函数 
	{
		delete[] data;
	}
	int getlength()					    	//返回集合的长度
  	{
	  	return length;
	}
	int get(int i)					    	//返回集合的第i个元素
  	{
	  	if (i<0 || i>=length)         		//检测参数i的正确性
	  		throw "参数i错误";
    	return data[i];
    }
	bool IsIn(int e)				       	//判断e是否在集合中
  	{
	  	for (int i=0;i<length;i++)
      		if (data[i]==e)
				return true;
		return false;
	}
	void add(int e)				        	//将元素e添加到集合中
  	{	if (!IsIn(e))			    		//元素e不在集合中
    	{	data[length]=e;
   			length++;
   		}
   	}
	void delelem(int e)			        	//从集合中删除元素e
  	{	int i=0;
    	while (i<length && data[i]!=e)
     		i++;
    	if (i>=length)
      		return;			            	//未找到元素e直接返回
    	for (int j=i+1;j<length;j++)		//找到元素e后通过移动实现删除
      		data[j-1]=data[j];
      	length--;
	}

	Set &Copy()                     		//返回当前集合的复制集合
  	{	static Set s1;
  		for (int i=0;i<length;i++)
  			s1.data[i]=data[i];
     	s1.length=length;
     	return s1;
	}
   	
 	void display()				     		//输出集合中的元素
  	{
	  	for (int i=0;i<length-1;i++)
      		printf("%d ",data[i]);
     	printf("%d\n",data[length-1]);
	}
	Set &Union(Set &s2)                  	//求s3=s1∪s2(s1为当前集合)
  	{	Set &s3=Copy();              		//将当前集合复制到s3
    	for (int i=0;i<s2.getlength();i++) 	//将s2中不在当前集合中的元素添加到s3中
      	{	int e=s2.get(i);
     		if (!IsIn(e))
         		s3.add(e);
    	}
    	return s3;					     	//返回s3
    }
	Set &Inter(Set &s2)          	      	//求s3=s1∩s2(s1为当前集合)
  	{	static Set s3;
    	for (int i=0;i<length;i++)			//将s1中出现在s2中的元素复制到s3中
      	{	int e=data[i];
     		if (s2.IsIn(e))
         		s3.add(e);
    	}
   		return s3;					     	//返回s3
   	}
	Set &Diff(Set &s2)                   	//求s3=s1-s2(s1为当前集合)
  	{	static Set s3;
    	for (int i=0;i<length;i++)       	//将s1中不出现在s2中的元素复制到s3中
      	{	int e=data[i];
        	if (!s2.IsIn(e))
         		s3.add(e);
    	}
		return s3;					     	//返回s3
	}
};
int main()
{
	Set s1,s2;
	s1.add(1);
	s1.add(4);
	s1.add(2);
	s1.add(6);
	s1.add(8);
	printf("集合s1: "); s1.display();
	printf("s1的长度为%d\n",s1.getlength());
	s2.add(2);
	s2.add(5);
	s2.add(3);
	s2.add(6);
	printf("集合s2: "); s2.display();
	printf("集合s1和s2的并集->s3\n");
	Set &s3=s1.Union(s2);
	printf("集合s3: "); s3.display();
	printf("集合s1和s2的差集->s4\n");
	Set &s4=s1.Diff(s2);
	printf("集合s4: "); s4.display();
	printf("集合s1和s2的交集->s5\n");
	Set &s5=s1.Inter(s2);
	printf("集合s5: "); s5.display();
	return 0;
}

