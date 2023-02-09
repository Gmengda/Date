#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
char *my_strncpy(char *dest,const char *src, int count)
{
	char *ret = dest;
	assert(dest);
	assert(src);
    while(count && (*dest++ = *src++))
	{
		count--;
	}
	if(count > 0)
	{
		while(--count)
		{
			*dest++ = '\0';
		}
	}
	return ret;
}
int main()
{
		char arr[20] = { 'a', 'b', 'c', 'd', 'e', 'f','g','h' };
		char*p = "bit";
		int count = 0;
		printf("请输入拷贝的字符个数：\n");
		scanf("%d", &count);
		char*ret = my_strncpy(arr, p,5);
		printf("%s\n", ret);
		return 0;
}