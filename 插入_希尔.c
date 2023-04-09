
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
	int get = 3;
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