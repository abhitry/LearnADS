#include<iostream>
using namespace std;
#define MAX 50
class stack{
	int top;
	char data[MAX];
	public:
		stack()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(int x)
		{
			if(!full())
			{
				top++;
				data[top]=x;
			}
			else{
				cout<<"\nStack Full";
			}
		}
		char pop()
		{
			if(!empty())
			{
				char x;
				x =data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nstack empty";
			}
		}
		void display()
		{
			for(int i=0;i<=top;i++)
			{
				cout<<data[i]<<" ";
			}
		}
};
int priority(char ch)
{
	if(ch=='/'||ch=='*')
	{
		return 2;
	}
	else if(ch=='+'||ch=='-')
	{
		return 1;
	}
}
int main()
{
	char infix[50];
	cout<<"\nenter infix expression:";
	cin.getline(infix,50);
	char postfix[50];
	int i =0,j =0;
	stack stk;
	char stkop,expop,ch;
	while(infix[i]!='\0')
	{
		ch=infix[i];
		//cout<<ch;
		if(ch=='('||ch=='{'||ch=='[')
		{
			stk.push(ch);
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
			expop=ch;
			while(stk.empty()==0)
			{
				stkop=stk.pop();
				if(stkop=='('||stkop=='{'||stkop=='[')
				{
					stk.push(stkop);
					break;
				}
				else if(priority(stkop)>=priority(expop)){
					postfix[j] =stkop;
					j++;
				}
				else{
					stk.push(stkop);
					break;
				}
			}
			stk.push(expop);
		}
		else if(ch=='}'||ch==')'||ch==']')
		{
			if(ch=='}')
			{
				stkop=stk.pop();
				while(stkop!='{')
				{
					postfix[j]=stkop;
					j++;
					stkop=stk.pop();
				}
			}
			if(ch==')')
			{
				stkop=stk.pop();
				while(stkop!='(')
				{
					postfix[j]=stkop;
					j++;
					stkop=stk.pop();
				}
			}
			if(ch==']')
			{
				stkop=stk.pop();
				while(stkop!='[')
				{
					postfix[j]=stkop;
					j++;
					stkop=stk.pop();
				}
			}
		}
		else{
			postfix[j] =ch;
			j++;
		}
		i++;	
	}
	while(stk.empty()==0)
	{
		ch=stk.pop();
		postfix[j]=ch;
		j++;
	}
	postfix[j]='\0';
	cout<<postfix;
	return 0;
}