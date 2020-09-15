#include <iostream>
using namespace std;
int main()
{
	freopen("turtle.in", "r", stdin);
	freopen("turtle.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	int a[h][w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> a[i][j];
	for (int i = h - 2; i >= 0; i--)
		a[i][0] += a[i + 1][0];
	for (int i = 1; i < w; i++)
		a[h - 1][i] += a[h - 1][i - 1];
	for (int i = h - 2; i >= 0; i--)
	{
		for (int j = 1; j < w; j++)
		{
			if (a[i][j - 1] >= a[i + 1][j])
				a[i][j] += a[i][j - 1];
			else
				a[i][j] += a[i + 1][j];
		}
	}
	cout << a[0][w - 1];
}