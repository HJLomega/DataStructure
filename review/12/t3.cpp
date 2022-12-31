/*
请编写算法将图的邻接矩阵存储改为邻接表存储。
*/

//邻接矩阵的数据类型定义如下：
#define  MAXV  100
#define INF  0x7fffffff
typedef char InfoType ;
typedef struct {
    int no;				// 顶点编号
    InfoType info;		    // 顶点其他信息
} VertexType;			        // 顶点类型
typedef struct {  		             // 图的定义
    int edges[MAXV][MAXV]; 	 // 邻接矩阵
    int vexnum, arcnum;   	     // 顶点数,弧数
    VertexType vexs[MAXV];	 // 存放顶点信息
} MGraph;

//邻接表存储结构的定义如下：
typedef struct ANode {  	    // 弧的结点结构类型
    int adjvex;               // 该弧的终点位置
    struct ANode* nextarc;     // 指向下一条弧的指针
    InfoType info;   	       // 该弧的相关信息
} ArcNode;
typedef struct Vnode {                  // 邻接表头结点的类型
    VertexType data;            	    // 顶点信息
    ArcNode* firstarc;                 // 指向第一条弧
} VNode;
typedef VNode AdjList[MAXV];	  // AdjList是邻接表类型
typedef struct {
    AdjList adjlist;         	// 邻接表 
    int n, e;           		// 图中顶点数n和边数e
} ALGraph;          		    // 图的类型


void tansform(MGraph *mg, ALGraph *alg) {
    alg->n = mg->vexnum;
    alg->e = mg->arcnum;
    for (int i = 0; i < alg->n; i++) {
        VNode* node = &alg->adjlist[i];
        node->data = mg->vexs[i];
        //头插法插入  
        for (int j = 0; j < alg->n; j++) {
            if (mg->edges[i][j] != INF && mg->edges[i][j] != 0) { //有边且不是自己,插入
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