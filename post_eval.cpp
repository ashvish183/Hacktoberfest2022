#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
	int data ;
	node *next ;
};
class stack
{
	private : 
	node *head;
	public :
	stack()
	{
		head = NULL;
	}
	void push(int a)
	{
		node * temp = new node();
		temp ->data = a ;
		temp -> next = head ; 
		head = temp ;
	}
	int pop()
	{
		node *temp = head ;
		head = temp->next ;
		int a = temp->data ;
		delete temp;
		return a;
	}
	int see_top()
	{
		if(is_empty())
			return 0 ;
		node * temp = head ;
		return (temp->data);
	}
	int is_empty()
	{
		if(head == NULL)
			return 1;
		else
			return 0 ;
	}
};
int is_digit(char a)
{
	if(a >= '0' && a<= '9')
		return 1;
	else
		return 0;
}
int is_operand(char a)
{
	switch(a)
	{
		case '+' : return 1;
		case '-' : return 1;
		case '*' : return 1;
		case '/' : return 1;
		default  : return 0;
	}
}

float operation(float a , float b , char sym)
{
	float ans ;
	switch(sym)
	{
		case '+' : ans = a + b ;
			   break;
		case '-' : ans = a - b ;
			   break ;
		case '*' : ans = a*b ;
			   break ;
		case '/' : ans = a/b ;
			   break ;
		default  : break ;
	}
	return ans ;
}
int main()
{
	char exp[100];
	stack s ; 
	float  num=0 , num1=0 , num2=0 ;
	int l , i ;
	cout << "Enter the posfix expression : ";
	cin.getline(exp,100);
	l=strlen(exp);
	for(i=0;i<l;i++)
	{
		if(is_digit(exp[i]))
		{
			num = 0;
			while(exp[i]!=' ')
			{
				int a = exp[i++]- '0';
				num = 10*num + a ;
			}
			s.push(num);
		}
		else if(is_operand(exp[i]))
		{
			num2 = s.see_top();
			s.pop();
			num1 = s.see_top();
			s.pop();
			num = operation(num1 , num2 , exp[i]);
			s.push(num);
		}
		else
			continue;
	}

	num = s.see_top();
	s.pop();
	cout << "Answer : " << num ;
	return 0 ;
}