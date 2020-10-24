#include<iostream>
using namespace std;
const int MAX_VERTEX = 10;
void get_info(int* line, int* col);
class MGraph
{
private:
    char vertex[MAX_VERTEX];             //存储结点信息的数组
    int arc[MAX_VERTEX][MAX_VERTEX];     //邻接矩阵/存储边的信息
    int vertexNum;                      //实际结点数
    int arcNum;                         //边数
public:
    MGraph(char v[], int n, int e);
   // ~MGraph();                    //这个析构函数的声明存在为什么会报错？？？？
    void DFSTraverse(int v);       //深度优先遍历
    void BFSTraverse(int v);       //广度优先遍历
    void pf();                     //简单打印邻接矩阵检查构造的正确性
};
MGraph::MGraph(char v[], int n, int e)
{
    this->vertexNum = n;
    this->arcNum = e;
    for (int i = 0; i < vertexNum; i++)    //初始化结点信息  注意循环变量是结点个数vertexNum
    {
        vertex[i] = v[i];
    }
    for (int i = 0; i < vertexNum; i++)   //初始化邻接表信息   /注意循环变量是结点个数vertexNum
    { 
        for (int j = 0; j < vertexNum; j++)
        {
            arc[i][j] = 0;
        }
    }
    for (int i = 0; i < arcNum; i++)    //注意循环变量是总边数
    {
        int line = 0, col = 0;
        get_info(&line, &col);
        arc[line][col] = 1;
        arc[col][line] = 1;
    }
}
void get_info(int* line,int* col)     //封装一个处理输入的函数而不是在构造函数中有输入输出语句
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
//1 3             样例与结果
//0 1 0 1
//1 0 1 1
//0 1 0 0
//1 1 0 0