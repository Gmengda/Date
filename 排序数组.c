/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}



void ShellSort(int* a, int n)
{

	int get = n;
	while (get > 1)
	{
		get = get / 3 + 1;
		for (int i = 0; i < n - get; i++)
		{
			int end = i;
			int tmp = a[i + get];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + get] = a[end];
					end -= get;
				}
				else
				{
					break;
				}
			}
			a[end + get] = tmp;
		}
	}
}




void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				Swap(&a[j], &a[i]);
				min = a[i];
			}
		}
	}
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{

		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);

		--end;
	}
}


void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool falg = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				falg = true;
			}
		}
		if (!falg)
		{
			break;
		}
	}
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


int* sortArray(int* nums, int numsSize, int* returnSize){
    SelectSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}