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