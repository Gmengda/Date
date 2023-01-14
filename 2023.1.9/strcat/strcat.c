#define _CRT_SECURE_NO_WARNINGS 1

char* my_strcat(char* m, char* n)
{

	char* z = m;
	assert(m && n);
	while (*m)
	{
		m++;
	}
	while (*m++ = *n++) { ; }
	return z;
}