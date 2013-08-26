#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	string s1("C++");
	string s2("is");
	string s3("powerfull");
	string s4("language");

	queue<string> q;
	q.push(s1);
	q.push(s2);
	q.push(s3);
	q.push(s4);

	cout << "size of queue is " << q.size() << endl;

	string temp = q.back();
	cout << temp << endl;

	while (!q.empty())
	{
		temp = q.front();
		cout << temp << " ";
		q.pop();
	}
	cout << endl;

	return 0;

}

