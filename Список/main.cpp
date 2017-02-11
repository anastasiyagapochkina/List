#include <iostream>
#include <conio.h>
#include <locale>

using namespace std;

struct A
{
	int key;
};

struct List
{
	A a;
	List *next;
};
// ������� ������ �� �����
void print_list(List *l)
{
	List *print = l;
	while(print)
	{
		cout << print->a.key << "->";
		print = print->next;
	}
	cout << "NULL" << endl;
}

// �������������� ������
void init_list(List **begin)
{
	*begin = new List;
	A a[5] = {1,2,7,19,50};
	(*begin)->a.key = 0;
	(*begin)->next = NULL;
	List *end = *begin;
	for(int i = 0; i < 5; i++)
	{
		end->next = new List;
		end = end->next;
		end->a = a[i];
		end->next = NULL;
	}
}

// ������� � ������
void add_begin(List **begin, const A &a)
{
	List *t = new List;
	t->a = a;
	t->next = *begin;
	*begin = t;
}

// ������� � �����
void add_end(List **begin, const A &a)
{
	List *p = *begin;
	List *t = new List;
	t->a = a;
	t->next = NULL;
	while (1)
	{
		if(!p->next)
		{
			p->next = t;
			break;
		}
		p = p->next;
	}
}

// ������� � ����� ����� ������
void insert(List **begin, const A &a)
{
	List *ins = new List;
	ins->a = a;
	if(!*begin)
	{
		ins->next = NULL;
		*begin = ins;
		return;
	}
	List *t = *begin;
	if(t->a.key >= ins->a.key)
	{
		ins->next = t;
		*begin = ins;
		return;
	}
	List *t1 = t->next;
	while(t1)
	{
		if((t->a.key < ins ->a.key) && (ins->a.key <= t1->a.key))
		{
			t->next = ins;
			ins->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
	t->next = ins;
	ins->next = NULL;
}

// �������� �� ������
void delete_elem(List **begin, const A &a)
{
	//������ ����
	if(*begin == NULL)
		return;
	List *t = *begin;
	if(t->a.key == a.key)
	{
		*begin = t->next;
		delete t;
		return;
	}
	List *t1 = t->next;
	while (t1)
	{
		if(t1->a.key == a.key)
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t= t1;
		t1 = t1->next;
	}
}

// ����������� ������
void free_mem(List **begin)
{
	if(*begin == 0)
		return;
	List *p = *begin;
	List *t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	List *begin = NULL;
	A a = {-1};
	A b = {10};
	A c = {7};
	A d = {100};
	init_list(&begin);
	print_list(begin);
	add_begin(&begin, a);
	print_list(begin);
	add_end(&begin, d);
	print_list(begin);
	insert(&begin, b);
	print_list(begin);
	delete_elem(&begin, c);
	print_list(begin);
	free_mem(&begin);
	_getch();
	return 0;
}