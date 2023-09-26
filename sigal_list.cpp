#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include "stdio.h"
#include "stdlib.h"
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;//int����
typedef int Status;//int����
typedef struct Lnode {//�����ṹ��������Lnode
	ElemType data;  //ѧ��ѧ��
//	string _name;//����
	char _name[100] = { 0 };
	 ElemType _ret;//�ɼ�
	struct Lnode* next;//
}Lnode, * LinkList;//����ṹ�������Lnode������ṹ��ָ�������LinkList


//�����ǽ���������
void CreatList_L(LinkList& head)//����һ��ͷָ��
{
	LinkList tail, p;
	int n, i;
	p = (Lnode*)malloc(sizeof(Lnode));//����һ���ڵ㣬��ֵ�opָ��
	head = tail = p;
	head->next = NULL;
	printf("Please input length of a list:\n");
	scanf("%d", &n);//���뵥����ĳ���
	printf("Please input values of the list:\n");//��������Ľڵ�data��ֵ
	for (i = 1; i <= n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		printf("������ѧ��: ");
		scanf("%d", &p->data);//����ѧ��
		printf("����������: ");
		scanf("%s", &p->_name);//��������
		printf("������ɼ�: ");
		scanf("%d", &p->_ret);//����ɼ�
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("A list has been created successfully!\n");
}


//���������������
void OutputList_L(LinkList L) {//�ⲿ������һ��ָ������ڵ��ָ��
	LinkList p = L->next;//�ҵ��ýڵ��next
	if (p == NULL) {
		printf("\n No list\n");
		return;
	}
	printf("The list is:\n");
	while (p) {
		printf(" ������%s ", p->_name);//�������
		printf("ѧ�ţ�%d ", p->data);//���ѧ��
		printf("�ɼ���%d", p->_ret);//����ɼ�
		p = p->next;
	}
	printf("\n");
}
//�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
Status ListInsert_L(LinkList L, int i, ElemType e, char* name,ElemType ret) {//L��ͷ�ڵ�ָ�룬e��data
	LinkList p, s;
	int j = 0;
	//�뽫���㷨��������

		p = L;//pָ���ڱ�λ
		s =p;
		while (p!=nullptr)
		{
			if (j == i)//i=0ʱ��Ҫ���ڱ�λǰ����ڵ㣬�����ڱ�λ������Ԫ�أ����Ҳ�����ܲ��ܣ�����Ҳ���ȥ
			{
				LinkList cur = (Lnode*)malloc(sizeof(Lnode));
				cur->data = e;
				strcpy(cur->_name, name);
				cur->_ret = ret;
				cur->next = p;
				s->next = cur;
				return 1;//����true
			}
			else
			{
				s = p;
				p = p->next;
				j++;
			}
		
	}
		//i>������ڵ����������ʧ��
	return 0;//����false
}

// ɾ���� i ��Ԫ��
	Status ListDelete_L(LinkList L, int i, ElemType & e) {
		LinkList p, q;
		int j = 0;
		//�뽫���㷨��������
		p = L;
		q = p;
		if (i == 0)
		{
			return 0;//Ҫ�ǲ���ɾ���ڱ�λ�ͼ������ѭ�����������ǲ���ɾ����
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
		return 0;//i>������ڵ������ɾ��ʧ��
	}



	void main()
	{
		LinkList L;//�ڵ�ָ�����
		int choice, i;
		ElemType e;//ѧ��
		char name[100];//����
		ElemType ret=0;// �ɼ�--��ʼ��Ϊ0
		choice = 1;//flag
		printf("We should create a list first!");
		CreatList_L(L);//����һ��������--�õ������Ǵ��ڱ�λ�ĵ�������ͷ�ڵ�data����������
		OutputList_L(L);//����յĵ�����

		while (choice != 0) {
			printf("please give your choice:insert 1,delete 2, output 3, exit 0:\n");//����1Ϊ����ֵ��2Ϊɾ����3Ϊ���
			scanf("%d", &choice);
			if (choice == 0) break;//0ֱ���˳�
			else if (choice == 1) {//����ֵ���������ڵ���뵥����
				printf("Please input the inserting position ��student id��name and grades!\n");

				scanf("%d%d%s%d", &i, &e,&name,&ret);//i�ǲ����λ�ã�e�ǲ����ֵ���½ڵ��dataֵ
				if (ListInsert_L(L, i, e,name,ret)) {//L���ڱ�λ��ͷ�ڵ�
					printf("The inserting action has been done!\n");
					OutputList_L(L);//���������
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
