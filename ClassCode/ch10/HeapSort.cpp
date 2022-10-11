#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void siftDown(vector<int> &R,int low,int high)	//R[low..high]的自顶向下筛选
{	int i=low;
 	int j=2*i+1;			        		//R[j]是R[i]的左孩子
 	int tmp=R[i];							//tmp临时保存根结点
 	while (j<=high)							//只对R[low..high]的元素进行筛选
  	{	if (j<high && R[j]<R[j+1])
      		j++;							//若右孩子较大,把j指向右孩子
     	if (tmp<R[j]) 						//tmp的孩子较大
      	{	R[i]=R[j];						//将R[j]调整到双亲位置上
        	i=j; j=2*i+1;					//修改i和j值,以便继续向下筛选
        }
     	else break;							//若孩子较小，则筛选结束
  	}
	R[i]=tmp;								//原根结点放入最终位置
}

void siftUp(vector<int> &R,int j)  			//自底向上筛选:从叶子结点j向上筛选
{	int i=(j-1)/2;   						//i指向R[j]的双亲
 	while (true)
  	{	if (R[j]>R[i])           			//若孩子较大
      		swap(R[i],R[j]);				//交换
     	if (i==0) break;					//到达根结点时结束
     	j=i; i=(j-1)/2;						//继续向上调整
	}
}
void HeapSort(vector<int> &R,int n) 		//堆排序
{
	for (int i=n/2-1;i>=0;i--)				//从最后一个分支结点开始循环建立初始堆
  		siftDown(R,i,n-1);					//对R[i..n-1]进行筛选

	//for (int j=n/2;j<n-1;j++)				//循环建立初始堆
	//	siftUp(R,j);				    	//对R[j]进行筛选(R[j]为叶子结点)

  	printf("初始堆:   "); disp(R,0,n-1); 
 	for (int i=n-1;i>0;i--)       			//进行n-1趟排序,每一趟排序后无序区元素个数减1
  	{	swap(R[0],R[i]);					//将无序区中最后一个元素与R[0]交换，有序区为R[i..n-1]
  		printf("归位R[%d]: ",i);disp(R,0,n-1); 
    	siftDown(R,0,i-1);		   			//对无序区R[0..i-1]继续筛选
  		printf("调整为堆: "); disp(R,0,n-1); 
	}
}

int main() 
{
	vector<int> a={6,8,7,9,0,1,3,2,4,5};
	int n=a.size();
	printf("排序前:   "); disp(a,0,n-1); 
	HeapSort(a,n);
	printf("排序后:   "); disp(a,0,n-1); 
	return 0;
}
	

