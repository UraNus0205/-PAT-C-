#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[10] = { 1,2,2,3,3,3,5,5,5,5};
	int* lowerPos = lower_bound(a, a + 10, -1);
	int* upperPos = upper_bound(a, a + 10, -1);
	cout << lowerPos - a << " " << upperPos - a << endl;


	lowerPos = lower_bound(a, a + 10, 1);
	upperPos = upper_bound(a, a + 10, 1);
	cout << lowerPos - a << " " << upperPos - a << endl;

	lowerPos = lower_bound(a, a + 10, 3);
	upperPos = upper_bound(a, a + 10, 3);
	cout << lowerPos - a << " " << upperPos - a << endl;

	lowerPos = lower_bound(a, a + 10, 4);
	upperPos = upper_bound(a, a + 10, 4);
	cout << lowerPos - a << " " << upperPos - a << endl;

	lowerPos = lower_bound(a, a + 10, 6);
	upperPos = upper_bound(a, a + 10, 6);
	cout << lowerPos - a << " " << upperPos - a << endl;

	return 0;
}

