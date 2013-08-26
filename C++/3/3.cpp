#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T i;
	Node<T> * next;

	Node(T, Node<T> *);
};

template <typename T>
Node<T>::Node(T i, Node<T>* next)
{
	this->i = i;
	this->next = next;
}

template <typename T>
class List
{
public:
	List();
	void add(T);
	void list_for_each(void);

private:
	Node<T> * head_node;
};

template <typename T>
List<T>::List()
{
	this->head_node = new Node<T>(0, NULL);
}

template <typename T>
void List<T>::add(T i)
{
	Node<T> * node = new Node<T>(i, NULL);

	Node<T> * cur = this->head_node;
	for (; cur->next != NULL; cur = cur->next)
		;

	cur->next = node;
}

template <typename T>
void List<T>::list_for_each(void)
{
	Node<T> * cur = this->head_node->next;

	for (; cur != NULL; cur = cur->next)
		cout << cur->i << " "; 
	
	cout << endl;
}

int main()
{
	List<int> int_list;
	int_list.add(1);
	int_list.add(2);
	int_list.add(3);
	int_list.add(4);
	int_list.add(5);
	int_list.list_for_each();

	List<char> char_list;
	char_list.add('a');
	char_list.add('b');
	char_list.add('c');
	char_list.add('d');
	char_list.add('e');
	char_list.list_for_each();

	List<float> float_list;
	float_list.add(1.2);
	float_list.add(3.4);
	float_list.add(5.6);
	float_list.add(7.8);
	float_list.add(9.1);
	float_list.list_for_each();

}



