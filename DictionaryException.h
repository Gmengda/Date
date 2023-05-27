#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct TreeNode
{
	char word[20];
	char translation[20];
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;


//初始化插入节点
TNode* CreatTreeNode(const char* w, const char* t);

//初始化词典
void InitDictionary(TNode** root, FILE* dic);

//初始化插入单词
void InsertTreeWord(TNode** root, const char* w, const char* t);

//插入单词
void InsertWord(TNode** root, const char* w, const char* t, FILE* dic);

//删除单词
void DelWord(TNode** root, const char* w);

//删除文件中的单词
void DelTxtWord(TNode** root, const char* w);

//创建节点
TNode* CreatNode(const char* w, const char* t, FILE* dic);

//前序遍历
void PreOrder(TNode* root, FILE* dic);
//中序遍历
void InOrder(TNode* root, FILE* dic);
//后序遍历
void PostOrder(TNode* root, FILE* dic);
//树节点
int TreeSize(TNode* root);
//树的深度
int TreeHeight(TNode* root);
//寻找树节点
TNode* TreeFind(TNode* root,const char* x);

//寻找树父亲节点
TNode* TreeFindParent(TNode* root, TNode* child);

//销毁树
void Desert(TNode** root);

void DestoryNode(TNode* root);
