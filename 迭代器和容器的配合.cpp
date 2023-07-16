	// 迭代器跟算法进行配合
	reverse(v.begin(), v.end());
	reverse(lt.begin(), lt.end());

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;