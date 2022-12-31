/*
���д�㷨��ͼ���ڽӾ���洢��Ϊ�ڽӱ�洢��
*/

//�ڽӾ�����������Ͷ������£�
#define  MAXV  100
#define INF  0x7fffffff
typedef char InfoType ;
typedef struct {
    int no;				// ������
    InfoType info;		    // ����������Ϣ
} VertexType;			        // ��������
typedef struct {  		             // ͼ�Ķ���
    int edges[MAXV][MAXV]; 	 // �ڽӾ���
    int vexnum, arcnum;   	     // ������,����
    VertexType vexs[MAXV];	 // ��Ŷ�����Ϣ
} MGraph;

//�ڽӱ�洢�ṹ�Ķ������£�
typedef struct ANode {  	    // ���Ľ��ṹ����
    int adjvex;               // �û����յ�λ��
    struct ANode* nextarc;     // ָ����һ������ָ��
    InfoType info;   	       // �û��������Ϣ
} ArcNode;
typedef struct Vnode {                  // �ڽӱ�ͷ��������
    VertexType data;            	    // ������Ϣ
    ArcNode* firstarc;                 // ָ���һ����
} VNode;
typedef VNode AdjList[MAXV];	  // AdjList���ڽӱ�����
typedef struct {
    AdjList adjlist;         	// �ڽӱ� 
    int n, e;           		// ͼ�ж�����n�ͱ���e
} ALGraph;          		    // ͼ������


void tansform(MGraph *mg, ALGraph *alg) {
    alg->n = mg->vexnum;
    alg->e = mg->arcnum;
    for (int i = 0; i < alg->n; i++) {
        VNode* node = &alg->adjlist[i];
        node->data = mg->vexs[i];
        //ͷ�巨����  
        for (int j = 0; j < alg->n; j++) {
            if (mg->edges[i][j] != INF && mg->edges[i][j] != 0) { //�б��Ҳ����Լ�,����
                ArcNode* arc = new ArcNode();
                if (node->firstarc == nullptr) {
                    arc->adjvex = j;
                    node->firstarc = arc;
                    arc->nextarc = nullptr;
                    continue;
                }
                arc->adjvex = j;
                arc->nextarc = node->firstarc->nextarc;
                node->firstarc->nextarc = arc;
            }
        }
    }
}

void test() {
    MGraph* mg = &MGraph();
    mg->arcnum = 5;
    mg->vexnum = 5;
    int a[5][5] = {{0, 8, INF, 5, INF}, {INF,0,3,INF,INF}, {INF,INF,0,INF,6}, {INF,INF,9,0,INF}, {INF,INF,INF,INF,0}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mg->edges[i][j] = a[i][j];
        }
    }
    ALGraph *alg = &ALGraph();
    tansform(mg, alg);
    int temp;
}
int main() {
    test();
}