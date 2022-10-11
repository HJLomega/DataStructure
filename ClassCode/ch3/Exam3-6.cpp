#include<iostream>
using namespace std;
const int MaxSize=100;						//ջ�����Ԫ�ظ��� 
template <typename T>
class STACK									//��Getmin()��ջ��
{
	T data[MaxSize];                 		//�����ջ��Ԫ�أ���ʼΪ��
    T mindata[MaxSize];              		//���minջ��Ԫ�أ���ʼΪ��
	int top;
	int mintop;
public:
	STACK():top(-1),mintop(-1) {}			//���캯�� 
private:		
	//minջ�򻯵Ļ��������㷨
	bool minempty()               			//�ж�minջ�Ƿ��
  	{
	  	return mintop==-1;
	}
	void minpush(T e)              			//Ԫ��e��minջ
	{
		mintop++;
		mindata[mintop]=e;
	}
	T minpop()                 				//Ԫ�س�minջ
  	{
   		T x=mindata[mintop];
		mintop--;
		return x;
	}
	T mingettop()              				//ȡminջջ��Ԫ��
  	{
    	return mindata[mintop];
    }
public:
	//��ջ���������㷨
  	bool empty()                    		//�ж���ջ�Ƿ��
  	{
  		return top==-1;
	}
	bool push(T x)                   		//Ԫ�ؽ���ջ
  	{
  		if (top==MaxSize-1)					//��ջ������false 
  			return false;
	  	if (empty() || x<=Getmin())
			minpush(x);						//ջ�ջ���x<=minջ��Ԫ��ʱ��minջ
     	top++;
		data[top]=x;            			//��x����ջ
		return true;
	}
	bool pop(T &x)                      	//Ԫ�س���ջ
  	{
 		if (empty())						//ջΪ�յ��������ջ�����
			return false;
    	x=data[top];               			//����ջ��ջx
    	top--;
    	if (x==mingettop())	    			//��ջ��Ԫ��Ϊ��СԪ��
      		minpop();             			//minջ��ջһ��
    	return true;
    }
	bool gettop(T &e)                   	//ȡ��ջջ��Ԫ��
	{
		if (empty())						//ջΪ�յ��������ջ�����
			return false;
		e=data[top];						//ȡջ��ָ��λ�õ�Ԫ��
		return true;
	}
	T Getmin()			        			//��ȡջ����СԪ��
  	{
    	return mingettop();					//����minջ��ջ��Ԫ�ؼ���ջ����СԪ��
	}
};
int main()
{
	STACK<int> st;							//����ջ���� 
	int e;
	cout <<"Ԫ��5,6,3,7���ν�ջ" << endl;
	st.push(5);
	st.push(6);
	st.push(3);
	st.push(7);
	cout << "  ����СԪ�ز���ջ" << endl;
	while (!st.empty())
    {
		cout << "    ��СԪ��: " << st.Getmin() << endl;
		st.pop(e);
    	cout << "    ��ջԪ��: " << e << endl;
    }
	return 0;
}
