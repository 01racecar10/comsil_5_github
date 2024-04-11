#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;
template <typename T> // �߰�
//LinkedList Node
class Node {
public:
	//�����͸� ������ ����
	T data; // int -> T
	//��屸��ü �̿�; ��������� �ּҸ� ������ ������
	Node* link;

	Node(T element) { // int -> T
		data = element;
		link = 0;
	}
};

//LinkedList Class
template <typename T> // �߰�
class LinkedList {
protected:
	//ù��° ����� �ּҸ� ������ ������
	Node<T> *first; // Node -> Node<T>
	int current_size;
public:
	//������, �ʱ�ȭ 
	LinkedList() {
		first = 0;
		current_size = 0;
	};

	//��� ������ ����
	int GetSize() {
		return current_size;
	};

	//�� �տ� ���Ҹ� ����, LinkedList�� Stack �Ѵ� ����
	void Insert(T element); // int -> T

	//�� ���� ���Ҹ� ����, ���� ���߿� ���� ���� ����  - LinkedList
	virtual bool Delete(T &element); // int -> T

	//����Ʈ ���
	void Print();
};


//�� ��带 �� �տ� ���̰� ���� ����
template <typename T> // �߰�
void LinkedList<T>::Insert(T element) { // LinkedList -> LinkedList<T>, int -> T
	//��� ����
	Node<T> *newnode = new Node<T>(element); // Node -> Node<T>

	//�� ��尡 ù��° ��带 ����Ŵ
	//newnode�� �������̱� ������ -> �� ����� �Լ�, ������ �ҷ��� newnode.link�� ���� ����
	newnode->link = first;
	first = newnode;
	current_size++;
}

//������ ����� ���� �����ϸ鼭 �޸𸮿��� �Ҵ� ����
template <typename T> // �߰�
bool LinkedList<T>::Delete(T &element) { // LinkedList -> LinkedList<T>, int -> T

	if (first == 0)
		return false;

	Node<T> * current = first; // Node -> Node<T>
	Node<T> * previous = 0; // Node -> Node<T>

	//������ ������ ã�ư��� �ݺ���
	while (1) {
		if (current->link == 0) {  //������ ��带 ã�°�
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;

	return true;
}

//����Ʈ�� ����ϴ� Print �Լ�
template <typename T> // �߰�
void LinkedList<T>::Print() { // LinkedList -> LinkedList<T>
	Node<T> *i; // Node -> Node<T>
	int index = 1;

	if (current_size != 0) {
		for (i = first; i != NULL; i = i->link) {
			if (index == current_size) {
				cout << "[" << index << "|";
				cout << i->data << "]->";
			}

			else {
				cout << "[" << index << "|";
				cout << i->data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif