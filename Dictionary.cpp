#define _CRT_SECURE_NO_WARNINGS 1
#include "DictionaryException.h"



void InitSystem()
{
	system("title �ʵ�����");
	system("color f0");
	system("mode con cols=80 lines=40");

}



//��ʼ���ʵ�
void InitDictionary(TNode** root, FILE* dic)
{
	InsertWord(root,"word", "����", dic);
	InsertWord(root, "insert", "���", dic);
	InsertWord(root, "day", "����", dic);
	InsertWord(root, "copy", "����", dic);
	InsertWord(root, "static", "��̬", dic);
	InsertWord(root, "find", "Ѱ��", dic);
	InsertWord(root, "add", "���", dic);
	InsertWord(root, "dictionary", "�ʵ�", dic);
	InsertWord(root, "choice", "����", dic);
	InsertWord(root, "play", "��ˣ", dic);
	InsertWord(root, "public", "������", dic);
	InsertWord(root, "private", "˽�е�", dic);
	InsertWord(root, "protected", "������", dic);

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
////��ʼ������ڵ�
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

//�����ڵ�
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

//////��ʼ�����뵥��
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

//���뵥��
//�ظ����ܵĿ���û�н����������Ҫ�����ʼ
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
////ɾ���ļ��еĵ���
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


//ɾ������
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



//ǰ�����
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


//�������
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


//�������
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


//���ڵ�
int TreeSize(TNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;
}


//�������
int TreeHeight(TNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}




//Ѱ�����ڵ�
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

//Ѱ�����ڵ�
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