// A+B for poly.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//class Base {
//public:
//	Base* next;
//};
class Node{
public:
	int expo;
	float coef;
	Node *next;
public:
	Node() { expo = 0; coef = 0; next = NULL; }
	~Node(){};
	void setValue(int exp, float coe, Node *next) {
		expo = exp; coef = coe; this->next = next;
	}
	void insert(Node *node) {
		node->next = this->next;
		this->next = node;
	}
};
class Head{
public:
	int num;            //number of expo
	Node *next;
public:
	Head(int num, Node *next) { this->num = num; this->next = next; }
	~Head(){}
	void addNum() { num++; }
	void print() {
		int i = 0;
		Node *tmp = next;
		cout << num;
		while (tmp != NULL) {
			cout << " " << tmp->expo << " " << tmp->coef;
			tmp = tmp->next;
		}
	}
	void insert(Node *node) {
		node->next = next;
		next = node;
	}
};



int main()
{
	int numA, numB;
	int i;

	cin >> numA;                               //get the data of list A
	int *expA = new int[numA];
	float *coeA = new float[numA];
	Node *nodeA = new Node[numA];
	Head *headA = new Head(numA, &nodeA[0]);
	for (i = 0; i < numA; i++) {
        cin >> expA[i] >> coeA[i];
		//scanf("%d %d", &expA[i], &coeA[i]);
		if (i < numA - 1)
			nodeA[i].setValue(expA[i], coeA[i], &nodeA[i + 1]);
		else
			nodeA[i].setValue(expA[i], coeA[i], NULL);
	}
//	headA->print();
		
	cin >> numB;                               //get the data of list B
	int  *expB = new int[numB];
	float *coeB = new float[numB];
	Node *nodeB = new Node[numB];
	Head *headB = new Head(numB, &nodeB[0]);
	for (i = 0; i < numB; i++) {
		cin >> expB[i] >> coeB[i];
		if (i < numB - 1)
			nodeB[i].setValue(expB[i], coeB[i], &nodeB[i + 1]);
		else
			nodeB[i].setValue(expB[i], coeB[i], NULL);
	}

	Node *preA, *preB;
	preA = nodeA, preB = nodeB;
	Node *tmp, *previous = NULL;

	while (preB != NULL) {
		//A=B, add the coefficient, then move back both
		if (preA->expo == preB->expo) {
			preA->coef += preB->coef;
			preA = preA->next;
			preB = preB->next;
//			headA->print();
		}

		else if (preA->expo < preB->expo) {
			tmp = preB;
			preB = preB->next;
			headA->insert(tmp);
			preA = headA->next;
			headA->addNum();
//			headA->print();
		}

		
		else if (preA->next != NULL && preA->next->expo >= preB->expo)
			preA = preA->next;

		else{
			tmp = preB;
			preB = preB->next;
			preA->insert(tmp);
			preA = preA->next;
			headA->addNum();
//			headA->print();
		}
	}

	headA->print();

	delete[] expA, expB, coeA, coeB, nodeA, nodeB;
    return 0;
}

