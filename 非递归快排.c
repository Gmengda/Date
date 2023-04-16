void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort3(a, begin, end);
		// [begin,keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi+1);
		}

		if (begin < keyi-1)
		{
			STPush(&st, keyi-1);
			STPush(&st, begin);
		}
	}

	STDestroy(&st);
}