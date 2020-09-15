#include <stdio.h>

int main() 
{
int n;
freopen("smallsort.in", "r", stdin);
freopen("smallsort.out", "w", stdout);
scanf("%d", &n);
int a[n];
for (int i = 0; i < n; i++)
scanf("%d", &a[i]);
int k;
for (int i = n - 1; i >= 0; i--) 
{
	for (int j = 0; j < i; j++)
	{
		if (a[j] > a[j + 1]) 
		{
			k = a[j];
			a[j] = a[j + 1];
			a[j + 1] = k;
		}
	}
}
for (int i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}