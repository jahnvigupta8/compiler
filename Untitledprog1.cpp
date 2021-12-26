#include<bits/stdc++.h>
using namespace std;
string pro[10][10];
int row=0;
int col=0;
int i,j;
int flag=0;
char l;
string r;
string cc;
int main()
{	
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			pro[i][j]=' ';
		}
	}
	
	while(1)												//for insertion of transitions in 2d matrix
	{
		cout<<"Insert transition left side"<<endl;
		cin>>l;
		pro[row][col]=l;
		col++;
		while(1)
		{
			cout<<"Insert transition right side"<<endl;
			cin>>r;
			pro[row][col]=r;
			col++;
			cout<<"Want to insert more right transitions"<<endl;
			char c;
			cin>>c;
			if(c=='y')
				continue;
			else
				break;			
		}	
		cout<<"Want to insert more left transitions"<<endl;
			char ch;
			cin>>ch;
			if(ch=='y')
				{
				row++;
				col=0;
				continue;
				
				}
			else
				break;
	}
	
	cout<<endl;
	int flag1=0;
	int k=row+1;
	int z=1;
	string p,s,q,u,f;
	
	for(i=0;i<=row;i++)			//for accessing production one by one
	{
		for(j=1;j<10;j++)			//for accessing each right hand side production
		{	
			f=pro[i][0];
			s=pro[i][j];
			if(f[0]==s[0])
			{	flag1=1;
				for(int m=1;m<10;m++)		//for creating A->bA'
				{
					q=pro[i][m];
					if(f[0]==q[0])
						continue;
					else if(q[0]!=' ')
						{	
							p=pro[i][0];
							cc="1";
							p=p+cc;
							pro[k][0]=pro[i][0];
							u=pro[i][m];			
							u=u+p;
							pro[k][z]=u;
							z++;											
						}					
				}
				k++;
				break;			
			}
		}
		z=1;
		
		
		if(flag1==1)
		{for(j=1;j<10;j++)				//for creating A'->A'l
		{	
			f=pro[i][0];
			s=pro[i][j];
			if(f[0]==s[0])
			{
				
				s.erase(0,1);
				pro[k][0]=p;
				s=s+p;
				pro[k][z]=s;
				z++;
				flag=1;
			}
		}
		flag1=0;	
		}
		if(flag==1)      //for adding A'->E
		{
				pro[k][z]="E";
		flag =0;
		}
		z=1;	
		k++;
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			cout<<pro[i][j]<<"      ";
		}
		cout<<endl;
	}
	
	return 0;
	
}


