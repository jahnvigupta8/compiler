#include<iostream>
#include<cstring>
using namespace std;
char stack[10];
int top=0;
int lenght=0;
char inf[10];
int main()
{
	char prod[5][5]={"=>>>",
		"<><>",
		"<>>>",
		"<<<="};
		cout<<"\n\n OPERATOR PRECEDENCE RELATIONS \n";
		//cout<<"\n ---------------------------------------------------------------------------\n";
		cout<<"\t"<<'i'<<"\t"<<'+'<<"\t"<<'*'<<"\t"<<'s'<<endl;
		//cout<<"\n----------------------------------------------------------------------------\n";
		for(int i =0;i<4;i++)
		{
			cout<<"\t";
			for(int j =0;j<4;j++)
			{
				cout<<prod[i][j]<<"\t";
			}
			cout<<endl;
		}
		char G[4][10]={
			"E->E+E",
			"E->E*E",
			"E->i" };	
		for(int i =0;i<4;i++)
		{
			for(int j =0;j<10;j++)
			{
				cout<<G[i][j];
			}
			cout<<endl;
		}
		char str[100];
		cout<<"Enter the string : ";
		cin>>str;
		stack[top++]='s';
		int l = strlen(str);
		for(int k=0;k<l;k++)
		{
			if(str[k]=='i')
			{
				if(stack[top-1]=='i')
				{
					stack[top++]=str[k];
				}
				else if(stack[top-1]=='+')
				{
					stack[top++]=str[k];
				}
				else if(stack[top-1]=='*')
				{
					stack[top++]=str[k];
				}
				else if(stack[top-1]=='s')
				{
					stack[top++]=str[k];
					cout<<"yo1"<<endl;
				}
			}
			else if(str[k]=='+')
			{
				if(stack[top-1]=='i')
				{
					top--;
					inf[lenght++]='i';k--;
				}
				else if(stack[top-1]=='+')
				{
					top--;
					inf[lenght++]='+';k--;
				}
				else if(stack[top-1]=='*')
				{
					stack[top++]=str[k];
				}
				else if(stack[top-1]=='s')
				{
					stack[top++]=str[k];
				}
			}
			else if(str[k]=='*')
			{
				if(stack[top-1]=='i')
				{
					top--;
					inf[lenght++]='i';k--;
				}
				else if(stack[top-1]=='+')
				{
					stack[top++]=str[k];
				}
				else if(stack[top-1]=='*')
				{	
					top--;
					inf[lenght++]='*';k--;
				}
				else if(stack[top-1]=='s')
				{
					stack[top++]=str[k];
				}
			}
			else if(str[k]=='s')
			{
				if(stack[top-1]=='i')
				{
					top--;
					inf[lenght++]='i';k--;
				}
				else if(stack[top-1]=='+')
				{
					top--;
					inf[lenght++]='+';k--;
				}
				else if(stack[top-1]=='*')
				{	
					top--;
					inf[lenght++]='*';k--;
				}
				else if(stack[top-1]=='s')
				{
					
				}
			}
		}
		cout<<endl;	
		for(int i=0;i<lenght;i++)
		{
			cout<<inf[i];
		}	
}
