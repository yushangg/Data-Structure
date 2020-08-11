/*
图的邻接矩阵存储结构定义
*/
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vex[MaxVertexNum];		//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];		//邻接矩阵、边表
	int vexnum, arcnum;		//图当前的定点数和弧的数目
}MGraph;

/*
二、4
写出从图的邻接表表示转换成邻接矩阵表示的算法
*/
void Connvert(ALGraph& G, int arcs[M][N) {
	for (int i = 0; i < n; i++) {		//遍历以各个顶点表结点为头的边链表
		p = (G->v[i]).firstarc;		//取出顶点i的第一条边
		while (p != NULL) {		//遍历边链表
			arcs[i][p->data] = 1;
			p = p->nextarc;
		}
	}
}