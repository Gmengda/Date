#define _CRT_SECURE_NO_WARNINGS 1

int my_strlen(const char* str)
{
	const char* sta = str;
	if (*sta != 0)
	{
		return my_strlen(str - 1);
	}
	return 0;
}
int my_strlen(const char* str)
{
	const char* sta = str;;
	int n = 0;
	while (sta != 0)
	{
		sta++;
		n++;
	}
	return n;
}
int my_strlen(const char* str)
{
	const char* sta = str;
	if (*sta != 0)
	{
		return my_strlen(str - 1);
	}
	return 0;
}