/*
ͼ���ڽӾ���洢�ṹ����
*/
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vex[MaxVertexNum];		//�����
	EdgeType Edge[MaxVertexNum][MaxVertexNum];		//�ڽӾ��󡢱߱�
	int vexnum, arcnum;		//ͼ��ǰ�Ķ������ͻ�����Ŀ
}MGraph;

/*
ͼ���ڽӱ�洢�ṹ����
*/
#define MaxVertexNum 100
typedef struct ArcNode {		//�߱���
	int adjvex;			//�û���ָ��Ķ����λ��
	struct ArcNode* next;	//ָ����һ������ָ��
	//InfoType info;	// Ȩֵ
}ArcNode;
typedef struct VNode {		//�����ڵ�
	VertexType data;		//������Ϣ
	ArcNode* first��		//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;		//�ڽӱ�
	int vexnum, arcnum;		
}ALGraph;

/*
����4
д����ͼ���ڽӱ��ʾת�����ڽӾ����ʾ���㷨
*/
void Connvert(ALGraph& G, int arcs[M][N) {
	for (int i = 0; i < n; i++) {		//�����Ը����������Ϊͷ�ı�����
		p = (G->v[i]).firstarc;		//ȡ������i�ĵ�һ����
		while (p != NULL) {		//����������
			arcs[i][p->data] = 1;
			p = p->nextarc;
		}
	}
}