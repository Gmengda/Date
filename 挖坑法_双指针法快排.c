//快排
void QuestSort(int* a, int left, int right);

//快排挖坑法
void QuestSort1(int* a, int left, int right);

//快排双指针法
void QuestSort2(int* a, int left, int right);

//基本交换
void Swap(int* p1, int* p2);

//三数取中
int git_mid_num(int* a, int left, int right);

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int git_mid_num(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if(a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

void QuestSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int kid = git_mid_num(a,left,right);
	if (kid != left)
	{
		Swap(&a[kid], &a[left]);
	}
	while (left < right)
	{
		while (left < right && a[right] >= a[kid])
		{
			right--;
		}
		while (left < right && a[left] <= a[kid])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[kid]);
	kid = left;
	QuestSort(a,begin,kid - 1);
	QuestSort(a,kid + 1,end);

}


void QuestSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int kid = git_mid_num(a, left, right);
	int num = a[kid];
	if (kid != left)
	{
		Swap(&a[kid], &a[left]);
	}


	while (left < right)
	{
		while (left <right && a[right]>=num)
		{
			right--;
		}
		Swap(&a[right], &a[kid]);
		kid = right;
		while (left <right && a[left]<=num)
		{
			left++;
		}
		Swap(&a[left], &a[kid]);
		kid = left;
	}
	QuestSort1(a, begin, kid - 1);
	QuestSort1(a, kid + 1, end);
}

void QuestSort2(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mind = git_mid_num(a, left, right);
	if (mind != left)
	{
		Swap(&a[mind], &a[left]);
	}
	int begin = left;
	int end = right;
	int kid = left;
	int n1 = left,n2 = left + 1;
	while (n2 <= right)
	{
		if (a[n2] < a[kid] && ++n1 != n2)
		{
			Swap(&a[n1], &a[n2]);
		}
		n2++;
	}
	Swap(&a[kid], &a[n1]);
	kid = n1;
	QuestSort2(a, begin, kid - 1);
	QuestSort2(a, kid + 1, end);
}
