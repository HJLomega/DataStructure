#include <iostream>
using namespace std;
const int MaxSize=100;                     	//���ϵ����Ԫ�ظ���(����)
class Set								 	//������
{
	int *data;			  					//data��ż���Ԫ��
	int length;		                    	//lengthΪ���ϵĳ���
public:
	Set()									//���캯�� 
	{	
		data=new int[MaxSize];			  	//data��ż���Ԫ��
		length=0;		                    //lengthΪ���ϵĳ���
	}
	~Set()									//�������� 
	{
		delete[] data;
	}
	int getlength()					    	//���ؼ��ϵĳ���
  	{
	  	return length;
	}
	int get(int i)					    	//���ؼ��ϵĵ�i��Ԫ��
  	{
	  	if (i<0 || i>=length)         		//������i����ȷ��
	  		throw "����i����";
    	return data[i];
    }
	bool IsIn(int e)				       	//�ж�e�Ƿ��ڼ�����
  	{
	  	for (int i=0;i<length;i++)
      		if (data[i]==e)
				return true;
		return false;
	}
	void add(int e)				        	//��Ԫ��e��ӵ�������
  	{	if (!IsIn(e))			    		//Ԫ��e���ڼ�����
    	{	data[length]=e;
   			length++;
   		}
   	}
	void delelem(int e)			        	//�Ӽ�����ɾ��Ԫ��e
  	{	int i=0;
    	while (i<length && data[i]!=e)
     		i++;
    	if (i>=length)
      		return;			            	//δ�ҵ�Ԫ��eֱ�ӷ���
    	for (int j=i+1;j<length;j++)		//�ҵ�Ԫ��e��ͨ���ƶ�ʵ��ɾ��
      		data[j-1]=data[j];
      	length--;
	}

	Set &Copy()                     		//���ص�ǰ���ϵĸ��Ƽ���
  	{	static Set s1;
  		for (int i=0;i<length;i++)
  			s1.data[i]=data[i];
     	s1.length=length;
     	return s1;
	}
   	
 	void display()				     		//��������е�Ԫ��
  	{
	  	for (int i=0;i<length-1;i++)
      		printf("%d ",data[i]);
     	printf("%d\n",data[length-1]);
	}
	Set &Union(Set &s2)                  	//��s3=s1��s2(s1Ϊ��ǰ����)
  	{	Set &s3=Copy();              		//����ǰ���ϸ��Ƶ�s3
    	for (int i=0;i<s2.getlength();i++) 	//��s2�в��ڵ�ǰ�����е�Ԫ����ӵ�s3��
      	{	int e=s2.get(i);
     		if (!IsIn(e))
         		s3.add(e);
    	}
    	return s3;					     	//����s3
    }
	Set &Inter(Set &s2)          	      	//��s3=s1��s2(s1Ϊ��ǰ����)
  	{	static Set s3;
    	for (int i=0;i<length;i++)			//��s1�г�����s2�е�Ԫ�ظ��Ƶ�s3��
      	{	int e=data[i];
     		if (s2.IsIn(e))
         		s3.add(e);
    	}
   		return s3;					     	//����s3
   	}
	Set &Diff(Set &s2)                   	//��s3=s1-s2(s1Ϊ��ǰ����)
  	{	static Set s3;
    	for (int i=0;i<length;i++)       	//��s1�в�������s2�е�Ԫ�ظ��Ƶ�s3��
      	{	int e=data[i];
        	if (!s2.IsIn(e))
         		s3.add(e);
    	}
		return s3;					     	//����s3
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
	printf("����s1: "); s1.display();
	printf("s1�ĳ���Ϊ%d\n",s1.getlength());
	s2.add(2);
	s2.add(5);
	s2.add(3);
	s2.add(6);
	printf("����s2: "); s2.display();
	printf("����s1��s2�Ĳ���->s3\n");
	Set &s3=s1.Union(s2);
	printf("����s3: "); s3.display();
	printf("����s1��s2�Ĳ->s4\n");
	Set &s4=s1.Diff(s2);
	printf("����s4: "); s4.display();
	printf("����s1��s2�Ľ���->s5\n");
	Set &s5=s1.Inter(s2);
	printf("����s5: "); s5.display();
	return 0;
}

