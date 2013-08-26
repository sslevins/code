#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// priority_queue<int, vector<int>, less<int> > q;
	priority_queue<int, vector<int>, greater<int> > q;

	q.push(100);
	q.push(200);
	q.push(300);

	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;

	return 0;

}

