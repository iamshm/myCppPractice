// GFG problem special Stack
// https://practice.geeksforgeeks.org/problems/special-stack/1/?category[]=Stack&page=1&query=category[]Stackpage1

#include<bits/stdc++.h>
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

class Stack {
private:
	static const int max = 100; //Size of main Stack
	int arr[max];
	int top;
public:
	Stack() {top = -1 ;}
	bool isEmpty();
	bool isFull();
	int pop();
	void push (int x) ;
};

bool Stack :: isEmpty() {
	if (top == -1) return true;
	return false;
}

bool Stack :: isFull() {
	if (top == max - 1) return true;
	return false;
}

int Stack :: pop() {
	if (isEmpty()) {
		std::cout << "Stack Underflow" << std::endl;
		abort();
	}
	int x = arr[top];
	top--;
	return x;
}

void Stack :: push (int x) {
	if (isFull()) {
		std::cout << "Stack OverFlow" << std::endl;
		abort();
	}
	top++;
	arr[top] = x;
}

class SpecialStack : public Stack {
	Stack min;
public:
	int pop();
	void push(int x) ;
	int getMinm();
};

int SpecialStack::getMinm() {
	int x = min.pop();
	min.push(x);
	return x;
}

void SpecialStack::push(int x)
{
	if (isEmpty() == true) {
		Stack::push(x);
		min.push(x);
	}
	else {
		Stack::push(x);
		int y = min.pop();
		min.push(y);
		if (x < y)
			min.push(x);
		else
			min.push(y);
	}
}

int SpecialStack::pop()
{
	int x = Stack::pop();
	min.pop();
	return x;
}
int main()
{
	shm();
	SpecialStack s;
	s.push(10);
	s.push(20);
	s.push(30);
	std::cout << s.getMinm() << std::endl;
	s.push(5);
	s.push(8);
	std::cout << s.getMinm() << std::endl;
	return 0;
}

