#include<iostream>
using namespace std;
const int MAX_VERTEX = 10;
void get_info(int* line, int* col);
class MGraph
{
private:
    char vertex[MAX_VERTEX];             //�洢�����Ϣ������
    int arc[MAX_VERTEX][MAX_VERTEX];     //�ڽӾ���/�洢�ߵ���Ϣ
    int vertexNum;                      //ʵ�ʽ����
    int arcNum;                         //����
public:
    MGraph(char v[], int n, int e);
   // ~MGraph();                    //���������������������Ϊʲô�ᱨ��������
    void DFSTraverse(int v);       //������ȱ���
    void BFSTraverse(int v);       //������ȱ���
    void pf();                     //�򵥴�ӡ�ڽӾ����鹹�����ȷ��
};
MGraph::MGraph(char v[], int n, int e)
{
    this->vertexNum = n;
    this->arcNum = e;
    for (int i = 0; i < vertexNum; i++)    //��ʼ�������Ϣ  ע��ѭ�������ǽ�����vertexNum
    {
        vertex[i] = v[i];
    }
    for (int i = 0; i < vertexNum; i++)   //��ʼ���ڽӱ���Ϣ   /ע��ѭ�������ǽ�����vertexNum
    { 
        for (int j = 0; j < vertexNum; j++)
        {
            arc[i][j] = 0;
        }
    }
    for (int i = 0; i < arcNum; i++)    //ע��ѭ���������ܱ���
    {
        int line = 0, col = 0;
        get_info(&line, &col);
        arc[line][col] = 1;
        arc[col][line] = 1;
    }
}
void get_info(int* line,int* col)     //��װһ����������ĺ����������ڹ��캯����������������
{
    
    cin >> *line >> *col;
}
void MGraph::pf()
{
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            cout<<arc[i][j]<<' ';
        }
        cout << endl;
    }
}
int main()
{
    char v[4] = { 'A','B','C','D' };
    int n, e;
    scanf_s("%d %d", &n, &e);
    MGraph graph(v, n, e);
    graph.pf();
    getchar();
    getchar();
}
//4 4
//0 1
//0 3
//1 2
//1 3             ��������
//0 1 0 1
//1 0 1 1
//0 1 0 0
//1 1 0 0