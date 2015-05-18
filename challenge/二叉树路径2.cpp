#include<iostream>
#define MAX 1000
using namespace std;

typedef struct _NODE_
{
  int data;
  struct _NODE_ *lChild;
  struct _NODE_ *rChild;
}Node,*pNode,*pTree;
void FindPath(pTree pT,int stack[],int exceptedNum,int curNum,int p)
{
  curNum += pT->data;//路径和加上当前结点值
  stack[p++] = pT->data;//把当前结点纳入stack中
  bool isLeaf = (pT->lChild == NULL) && (pT->rChild == NULL);//是否为叶子结点
  if((curNum == exceptedNum) && isLeaf)//当前为叶子节点而且路径和恰为期待值
  {
    for(int i = 0; i < p-1; i++)//打印路径
    {
      cout<< stack[i] << ',';
    }
    cout << stack[p-1];
  }
  
  if(pT->lChild)//如果有左孩子,那么递归遍历左子树
  {
    FindPath(pT->lChild,stack,exceptedNum,curNum,p);
  }
  if(pT->rChild)//如果有右孩子
  {
    FindPath(pT->rChild,stack,exceptedNum,curNum,p);
  }
  p--;//返回父节点前要将栈回退,pop出当前栈顶元素
}
void FindPath(pTree pT,int exceptedNum)
{
  int stack[1000];//使用数组模拟一个栈
  if(pT == NULL)
  {
    return;
  }
  int curNum = 0;//当前路径和
  int p = 0;//栈顶指针
  FindPath(pT,stack,exceptedNum,curNum,p);
}	
void create(pTree *ppTree)
{
  int data;
  cin >> data;
  if(data == -1)
  {
    return;
  }
  *ppTree = new _NODE_;
  if(*ppTree == NULL)
  {
    return;
  }
  (*ppTree)->data = data;
  (*ppTree)->lChild = NULL;
  (*ppTree)->rChild = NULL;
  create(&(*ppTree)->lChild);
  create(&(*ppTree)->rChild);
}
int main()
{
  pTree pT = NULL;
  int n;
  cin >> n; 
  create(&pT);	
  FindPath(pT,n);
  return 0;
}
