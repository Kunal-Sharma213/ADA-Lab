
#include <bits/stdc++.h>
using namespace std;
int carAssembly(int a[][100],
				int t[][100],
				int *e, int *x, int num)
{
	int first, second, i;

	first = e[0] + a[0][0];
	second = e[1] + a[1][0];
	for(i = 1; i < num; ++i)
	{
		int up = min(first + a[0][i],
					second + t[1][i] +
							a[0][i]);
		int down = min(second + a[1][i],
						first + t[0][i] +
								a[1][i]);
		first = up;
		second = down;
	}
	return min(first + x[0],
			second + x[1]);
}

int main()
{
    int num;
    cin >> num;
    int timeSpent[2][num], timeSwitch[2][num];
    for(int i = 0; i < 2;i ++){
        for(int j = 0; j < num; j++) cin >> timeSpent[i][j];
    }
    for(int i = 0; i < 2;i ++){
        for(int j = 0; j < num; j++) cin >> timeSwitch[i][j];
    }
int e[2];
for(int i = 0; i < 2; i++) cin >> e[i];
int x[2];
for(int i = 0; i < 2; i++) cin >> x[i];

cout << carAssembly(timeSpent, timeSwitch, e, x, num); 
}

