#ifndef __STACK_H__
#define __STACK_H__

#include "LinkedList.h"


//1. ���ø� Ŭ������ Ȯ���ؾ���
//2. Stack�������� Delete �Լ� �������ؾ���
//����: first, current_size�� class�� ��� �����̱� ������ this �����͸� ����Ͽ� �����;���

//LinkedList class�� ��ӹ���
template <typename T>
class Stack : public LinkedList<T> {
	public:
		bool Delete(T& element) {
			//first�� 0�̸� false��ȯ
			if (this->first == 0) return false;
			// LinkedList�� �޸� Stack�� current�� ����Ű�� ���� ����
			element = this->first->data;
			Node<T>* t = this->first;
			this->first = this->first->link;
			delete t;
			this->current_size--;
			return true;
		}
};
#endif