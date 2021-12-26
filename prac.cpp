 #include<iostream>
#include<conio.h>
#include<cstring>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include <algorithm>
#include<stack>
using namespace std;
int na1=0,ca1=0;
char first[1000][100],firs[1000][100],follow[1000][100],follo[1000][1000];
int check[1000];
void addnext(int,int,int);
int first1(int);
int follow1(int);
void replacet(int,int);
int nopipe(int);
void factoring(int index);
void fg();
char arr1[1000][1000];
char backup[1000][1000];
int conflict[100][100];

char prs[100];
char part[100][100][100],terminal[100],parts[100][100][100];
int nu[100],tt=0;
int trans[100][100];
string table[100][100];
ifstream file;
ofstream ofile;
ifstream fin;
ofstream fout;
void immediate();
void convert();
void parse();
int global=90,rules;
int main()
{
    cout<<"\n Enter number of rules in the grammar";
    cin>>rules;
    cout<<endl;
    for(int i=0;i<rules;i++)
    {
        cout<<"\n Enter rule "<<i<<endl;
        cin>>grammar[i];
        if(grammar[i][0]>=97 && grammar[i][0]<=122 )
        {
            cout<<"\n First character should be non terminal so enter again ";
            i=i-1;
        }
    }

    for(int i=0;i<rules;i++)
        flag[i]=0;
for(int i=0;i<rules;i++)
    {
         if(flag[i]==0)
         {
              strcpy(G[cg],grammar[i]);
              char ch= grammar[i][0];
              for(int j=i+1;j<rules;j++)
               {
               if(ch==grammar[j][0])
               {
                 flag[j]=1;
                 int len=strlen(grammar[j]);
                 int u=3;
                 char x[100];
                 int cstr=0;
                 while(u<=len)
                 {
                     x[cstr++]=grammar[j][u];
                     u++;
                 }
                 strcat(G[cg],"|");
                 strcat(G[cg],x);
               }
               }
            cg++;
           flag[i]=1;
         }
    }
 ofstream of;
    of.open("result1.txt",ios::trunc);
    for(int i=0;i<cg;i++)
    {
        Nonterminal[i]=G[i][0];
        of<<G[i]<<"\n";
        strcpy(backup[i],G[i]);
        Number[i]=i;
    }
    of.close();
 convert();
  of.open("result.txt",ios::trunc);
    of.close();
 if(LL1==0)
    {
    ch='y';
    while(ch=='y')
    {
    memset(prs,'\0',100);
    cout<<endl<<" Enter the string to be parsed";
    cin>>prs;
    prs[strlen(prs)]='$';
      cout<<endl;
parse();
  cout<<endl;
    cout<<"\n More string to parse ";
    cin>>ch;
    else
    {
        cout<<"\n String can't be parsed because G is not LL1";
void parsetable()
{  for(int i=0;i<100;i++)
    for(int j=0;j<100;j++)
                conflict[i][j]=0;}
     for(int i=0;i<cg;i++)
    {strcpy(S[i],G[i]);
        cout<<S[i]<<endl;}
     for(int i=0;i<cg;i++)
{ int k=0;
for(int j=3;j<strlen(G[i]);j++)
    {
        int num=0;
         while(G[i][j]!='\0')
    {

for(int i=0;i<cg;i++)
{
    for(int j=3;j<strlen(S[i]);j++)
    {
        if(!isupper(S[i][j]) && S[i][j]!='|'&& S[i][j]!='e')
        {
            int flag=0;
            for(int k=0;k<strlen(terminal);k++)
            {
                if(terminal[k]==S[i][j] )
                    flag=1;
            }
            if(flag==0)
            terminal[strlen(terminal)]=S[i][j];
for(int i=0;i<cg;i++)
{
    int flag=0;
    char ch=S[i][0];
    for(int j=0;j<nu[i];j++)
    {
        char str[1000];
        memset(G[i],'\0',1000);
        memset(str,'\0',1000);
        str[0]=ch;
        strcat(str,"->");
        strcat(str,part[i][j]);
        strcpy(G[i],str);
        for(int t=0;t<cg;t++)
        memset(first[t],'\0',1000);
        for(int t=0;t<cg;t++)
        check[t]=0;
        for(int t=0;t<cg;t++)
        {if(check[t]==0){
            int j= first1(t);
            check[t]=1;
       sort(first[p], first[p] + SIZE);
        int pi=0;

        if(SIZE==1)
        {
            for(int i=0;i<SIZE;i++)
            firs[p][pi++]=first[p][i];
       else
        {
         for(int i=0;i<SIZE;i++)
         {
          if(first[p][i]!=first[p][i+1])
          firs[p][pi++]=first[p][i];
       flag=0;
        for(int t=0;t<strlen(firs[i]);t++)
