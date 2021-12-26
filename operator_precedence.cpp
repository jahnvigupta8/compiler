#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char stack[10],s[10];
int top=0,i,j,k,ptr=0,p;
char prod[5][5]={
"=>>>",
"<><>",
"<>>>",
"<<<="
};
char c[4]={'i','+','*','$'};
char symbol,next;
char G[3][7]={
"E->E+E",
"E->E*E",
"E->id",
 };
int f(char ch)
{
switch(ch)
{
case '+':return 0;
case '*':return 1;
case 'i':return 2;
case '$':return 3;
default :
cout<<"\n ERROR entry";
exit(0);}}
int main()
{
printf("Grammar\n");
for(j=0;j<3;j++)
{
for(k=0;k<6;k++)
cout<<G[j][k];
cout<<endl;
}
cout<<"\nOPERATOR PRECEDENCE TABLE \n";
//cout<<"\n ---------------------------------------------------------------------------\n";
cout<<"\t"<<'i'<<"\t"<<'+'<<"\t"<<'*'<<"\t"<<'$'<<"\t";
cout<<"\n        -------------------------\n";
for(j=0;j<4;j++)
{
  cout<<c[j]<<"\t";
for(k=0;k<5;k++)
cout<<prod[j][k]<<"\t";
cout<<endl;
}
cout<<endl;
cout<<"Enter the string : ";
gets(s);
stack[top]='$';
s[strlen(s)]='$';
cout<<s;
 next=s[ptr];
 symbol=prod[f(stack[top])][f(next)];
/*cout<<stack[top]<<"\t";
for(int i=0;i<strlen(s);i++)
    cout<<s[i];*/
while(1){
       if(stack[top]=='$'&&s[ptr]=='$')
            {cout<<"\nParsing Successful";
            break;
            }
            else {
if (symbol=='<' || symbol=='=')
{
    stack[++top]=symbol;
    stack[++top]=next;
    //cout<<"\t    shift\n";
    ptr++;
}
else if(symbol=='>')
{

   char handle[5]={'\0'};
   stack[++top]=symbol;
   int u=top;
   while(stack[top]!='<')
   {top--;}
   int q=0;
  for( k=top;k<=u;k++)
   {
       handle[q]=stack[k];

       q++;
       stack[k]='\0';}
   handle[q]='\0';
top--;
   //cout<<"\t"<<handle<<" reduce"<<"\n";
    }
next=s[ptr];
symbol=prod[f(stack[top])][f(next)];
/*for(int i=0;i<=top;i++)
    cout<<stack[i];
cout<<"\t";
for(int j=ptr;j<=strlen(s);j++)
    cout<<s[j];
    */}}
}

