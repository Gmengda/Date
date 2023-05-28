#define _CRT_SECURE_NO_WARNINGS 1
#include "DictionaryException.h"



void InitSystem()
{
	system("title 词典助手");
	system("color f0");
	system("mode con cols=80 lines=40");

}



//初始化词典
void InitDictionary(TNode** root, FILE* dic)
{
	InsertWord(root,"word", "单词", dic);
	InsertWord(root, "insert", "添加", dic);
	InsertWord(root, "day", "日子", dic);
	InsertWord(root, "copy", "复制", dic);
	InsertWord(root, "static", "静态", dic);
	InsertWord(root, "find", "寻找", dic);
	InsertWord(root, "add", "添加", dic);
	InsertWord(root, "dictionary", "词典", dic);
	InsertWord(root, "choice", "机会", dic);
	InsertWord(root, "play", "玩耍", dic);
	InsertWord(root, "public", "公开的", dic);
	InsertWord(root, "private", "私有的", dic);
	InsertWord(root, "protected", "保护的", dic);

	/*FILE* dic1 = fopen("text.txt", "r+");

	while (1)
	{
		int z;
		char w[20];
		char t[20];
		int i = 0;
		while ((z = fscanf(dic1, "%c", &w[i])) != EOF && w[i] != '\n')
		{
			i++;
		}
		i = 0;
		while ((z = fscanf(dic1, "%c", &t[i]))!=EOF && t[i] != '\n')
		{
			i++;
		}
		InsertTreeWord(root, w, t);
		if (z == EOF)
		{
			break;
		}
	}
	fclose(dic1);*/

}
//
////初始化插入节点
//TNode* CreatTreeNode(TNode** root, const char* w, const char* t)
//{
//	TNode* tmp = (TNode*)malloc(sizeof(TNode));
//	*root = tmp;
//	if (*root == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//	strcpy((*root)->word, w);
//	strcpy((*root)->translation, t);
//	(*root)->left = NULL;
//	(*root)->right = NULL;
//	return (*root);
//}

//创建节点
TNode* CreatNode(const char* w,const char* t, FILE* dic)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	if (node->translation == NULL || node->word == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	strcpy(node->word, w);
	strcpy(node->translation, t);
	node->left = NULL;
	node->right = NULL;
	//if (w[0] != ' ' && t[0] != ' ')
	//{
	//	fprintf(dic, "%s\n%s\n", w, t);
	//}
	return node;
}

//////初始化插入单词
////void InsertTreeWord(TNode** root, const char* w, const char* t)
////{
////	if (*root == NULL)
////	{
////		*root = CreatTreeNode(root, w, t);
////		return;
////	}
////	if ((*root)->left == NULL && (*root)->right == NULL)
////	{
////		CreatTreeNode(&(*root)->left, w, t);
////	}
////	else if ((*root)->right == NULL)
////	{
////		CreatTreeNode(&(*root)->right, w, t);
////	}
////	else
////	{
////		if (TreeSize((*root)->left) >= TreeSize((*root)->right))
////		{
////			InsertTreeWord(&((*root)->left), w, t);
////		}
////		else
////		{
////			InsertTreeWord(&((*root)->right), w, t);
////		}
////	}
////	return;
////}

//插入单词
//重复可能的可能没有解决！！！，要放在最开始
void InsertWord(TNode** root,const char* w,const char* t,FILE* dic)
{
	if (*root == NULL)
	{
		*root = CreatNode(w, t, dic);
		return;
	}
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		(*root)->left = CreatNode(w, t, dic);
	}
	else if ((*root)->right == NULL)
	{
		(*root)->right = CreatNode(w, t, dic);
	}
	else
	{
		if (TreeSize((*root)->left) >= TreeSize((*root)->right))
		{
			InsertWord(&((*root)->left), w, t, dic);
		}
		else
		{
			InsertWord(&((*root)->right), w, t, dic);
		}
	}
	return;
}

void NullTxt(const char* m)
{
	FILE* txt = fopen(m, "w");
	fclose(txt);
	return;
}
//
////删除文件中的单词
//void DelTxtWord(TNode** root, const char* w)
//{
//	FILE* dic = fopen("text.txt","r+");
//	FILE* txt = fopen("copy.txt","w");
//	char ch = !EOF;
//
//	while (1)
//	{
//		int z;
//		char t[20];
//		int i = 0;
//		while ((z = fscanf(dic, "%c", &t[i])) != EOF && t[i] != '\n')
//		{
//			i++;
//			if (t[i] == ' ')
//			{
//				i--;
//			}
//		}
//		strcat(t, "\n");
//		if (z == EOF)
//		{
//			break;
//		}
//		if (strcmp(t, (*root)->word) == 0 || strcmp(t, (*root)->translation) == 0)
//		{
//
//		}
//		else
//		{
//			fprintf(txt, "%s", t);
//		}
//	}
//
//	NullTxt("text.txt");
//
//	while ((ch = fgetc(txt)) != EOF)
//	{
//		fputc(ch, dic);
//	}
//	fclose(dic);
//	fclose(txt);
//	return;
//}


//删除单词
void DelWord(TNode** root, const char* w)
{
	if (strcmp((*root)->word, w) == 0)
	{
		TNode* node = *root;
		if (node->left == NULL)
		{
			(*root) = (*root)->right;
		}
		else
		{
			(*root) = (*root)->left;
		}
		free(node);
		return;
	}

	TNode* child = TreeFind(*root, w);
	TNode* parent = TreeFindParent(*root, child);

	if (child->left == NULL && child->right == NULL)
	{
		if (parent->left == child)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	else if (child->left == NULL && child->right != NULL)
	{
		if (parent->left == child)
		{
			parent->left = child->right;
		}
		else
		{
			parent->right = child->right;
		}
	}
	else
	{
		if (parent->left == child)
		{
			parent->left = child->left;
		}
		else
		{
			parent->right = child->left;
		}
	}
	free(child);
}



//前序遍历
void PreOrder(TNode* root, FILE* dic) {
	if (root == NULL) {
		return;
	}

	for (unsigned int i = 0; i < strlen(root->word); i++)
	{
		printf("%c", root->word[i]);
	}
	printf("      ");
	for (unsigned int i = 0; i < strlen(root->translation); i++)
	{
		printf("%c", root->translation[i]);
	}
	printf("\n");
	PreOrder(root->left, dic);
	PreOrder(root->right, dic);
}


//中序遍历
void InOrder(TNode* root, FILE* dic) {
	if (root == NULL) {
		return;
	}

	InOrder(root->left, dic);
	for (unsigned int i = 0; i < strlen(root->word); i++)
	{
		printf("%c", root->word[i]);
	}
	printf("      ");
	for (unsigned int i = 0; i < strlen(root->translation); i++)
	{
		printf("%c", root->translation[i]);
	}
	printf("\n");
	InOrder(root->right, dic);
}


//后序遍历
void PostOrder(TNode* root, FILE* dic)
{
	if (root == NULL)
	{
		return;
	}

	PostOrder(root->left, dic);
	PostOrder(root->right, dic);
	for (unsigned int i = 0; i < strlen(root->word); i++)
	{
		printf("%c", root->word[i]);
	}
	printf("      ");
	for (unsigned int i = 0; i < strlen(root->translation); i++)
	{
		printf("%c", root->translation[i]);
	}
	printf("\n");
}


//树节点
int TreeSize(TNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;
}


//树的深度
int TreeHeight(TNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}




//寻找树节点
TNode* TreeFind(TNode* root,const char* x)
{
	if (root == NULL)
		return NULL;

	if (strcmp(root->word,x) == 0 || strcmp(root->translation, x) == 0)
		return root;

	TNode* lret = TreeFind(root->left, x);
	if (lret)
		return lret;

	TNode* rret = TreeFind(root->right, x);
	if (rret)
		return rret;

	return NULL;
}

//寻找树节点
TNode* TreeFindParent(TNode* root, TNode* child)
{
	if (root == NULL)
		return NULL;

	if (root->left == child || root->right == child)
		return root;

	TNode* lret = TreeFindParent(root->left, child);
	if (lret)
		return lret;

	TNode* rret = TreeFindParent(root->right, child);
	if (rret)
		return rret;

	return NULL;
}

void DestoryNode(TNode* root)
{
	free(root);
	return;
}

void Desert(TNode** root)
{
	if (root == NULL)
	{
		return;
	}
	if ((*root) == NULL)
	{
		return;
	}

	Desert(&(*root)->left);
	Desert(&(*root)->right);

	DestoryNode(*root);
	*root = NULL;
	return;
}