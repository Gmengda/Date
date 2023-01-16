#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,89,100 };
	int n;
	int left = 0;
	int right = 9;

	scanf("%d",&n);

	while (left < right) 
	{
		if (n<arr[right] && n>arr[left]) {
			left++;
			right--;
		}
		else if (n == arr[left])
		{
			printf("%d\n", left);
			break;
		}
		else if (n == arr[right])
		{
			printf("%d\n", right);
			break;
		}
		else if(n>arr[right] || n<arr[left])
		{
			printf("ÕÒ²»µ½¡£\n");
			break;
		}
	}

	return 0;
}