#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include "stdio.h"
#include "stdlib.h"
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;//int类型
typedef int Status;//int类型
typedef struct Lnode {//声明结构体类型是Lnode
	ElemType data;  //学生学号
//	string _name;//姓名
	char _name[100] = { 0 };
	 ElemType _ret;//成绩
	struct Lnode* next;//
}Lnode, * LinkList;//定义结构体变量是Lnode，定义结构体指针变量是LinkList


//以下是建立单链表
void CreatList_L(LinkList& head)//传递一个头指针
{
	LinkList tail, p;
	int n, i;
	p = (Lnode*)malloc(sizeof(Lnode));//开辟一个节点，赋值給p指针
	head = tail = p;
	head->next = NULL;
	printf("Please input length of a list:\n");
	scanf("%d", &n);//输入单链表的长度
	printf("Please input values of the list:\n");//输入链表的节点data的值
	for (i = 1; i <= n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("请输入学号: ");
		scanf("%d", &p->data);//输入学号
		printf("请输入姓名: ");
		scanf("%s", &p->_name);//输入姓名
		printf("请输入成绩: ");
		scanf("%d", &p->_ret);//输入成绩
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("A list has been created successfully!\n");
}


//以下是输出单链表
void OutputList_L(LinkList L) {//外部传进来一个指向链表节点的指针
	LinkList p = L->next;//找到该节点的next
	if (p == NULL) {
		printf("\n No list\n");
		return;
	}
	printf("The list is:\n");
	while (p) {
		printf(" 姓名：%s ", p->_name);//输出姓名
		printf("学号：%d ", p->data);//输出学号
		printf("成绩：%d", p->_ret);//输出成绩
		p = p->next;
	}
	printf("\n");
}
//在第i个元素之前插入一个元素
Status ListInsert_L(LinkList L, int i, ElemType e, char* name,ElemType ret) {//L是头节点指针，e是data
	LinkList p, s;
	int j = 0;
	//请将该算法补充完整

		p = L;//p指向哨兵位
		s =p;
		while (p!=nullptr)
		{
			if (j == i)//i=0时，要在哨兵位前插入节点，本身哨兵位不算是元素，但我不清楚能不能，所以也算进去
			{
				LinkList cur = (Lnode*)malloc(sizeof(Lnode));
				cur->data = e;
				strcpy(cur->_name, name);
				cur->_ret = ret;
				cur->next = p;
				s->next = cur;
				return 1;//返回true
			}
			else
			{
				s = p;
				p = p->next;
				j++;
			}
		
	}
		//i>单链表节点个数，插入失败
	return 0;//返回false
}

// 删除第 i 个元素
	Status ListDelete_L(LinkList L, int i, ElemType & e) {
		LinkList p, q;
		int j = 0;
		//请将该算法补充完整
		p = L;
		q = p;
		if (i == 0)
		{
			return 0;//要是不能删除哨兵位就加上这个循环，理论上是不能删除的
		}
		while (p != nullptr)
		{
			if (j == i)
			{
				q->next = p->next;
				delete p;
				p = nullptr;
				return 1;
			}
			else
			{
				q = p;
				p = p->next;
				j++;
			}

		}
		return 0;//i>单链表节点个数，删除失败
	}



	void main()
	{
		LinkList L;//节点指针对象
		int choice, i;
		ElemType e;//学号
		char name[100];//姓名
		ElemType ret=0;// 成绩--初始化为0
		choice = 1;//flag
		printf("We should create a list first!");
		CreatList_L(L);//创建一个单链表--该单链表是带哨兵位的单链表，即头节点data不包含数据
		OutputList_L(L);//输出空的单链表

		while (choice != 0) {
			printf("please give your choice:insert 1,delete 2, output 3, exit 0:\n");//输入1为插入值，2为删除，3为输出
			scanf("%d", &choice);
			if (choice == 0) break;//0直接退出
			else if (choice == 1) {//插入值，即创建节点插入单链表
				printf("Please input the inserting position 、student id、name and grades!\n");

				scanf("%d%d%s%d", &i, &e,&name,&ret);//i是插入的位置，e是插入的值即新节点的data值
				if (ListInsert_L(L, i, e,name,ret)) {//L是哨兵位即头节点
					printf("The inserting action has been done!\n");
					OutputList_L(L);//输出单链表
				}
				else printf("The inserting position is error!please do again!\n");
			}
			else if (choice == 2) {
				printf("Please input the deleting position :!\n");
				scanf("%d", &i);
				if (ListDelete_L(L, i, e)) {
					printf("The deleting action has been done,the deleting elem is %d!\n", e);
					OutputList_L(L);
				}
				else printf("The deleting position is error!please do again!\n");
			}
			else if (choice == 3) {
				OutputList_L(L);
			}
			else if(choice!=0)
      printf("choice error\n");       
   } 
} 
