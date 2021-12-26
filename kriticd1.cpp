#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char lhs;
    string str1;
    string prod1,prod2;
    string temp1;
    string temppr1,temppr2;
    vector <string> alpha;
    vector <string> beta;
    vector <string> parts;
    vector <string> parts2;
    cout<<"Enter Production \n";
    cin>>str1;
    lhs=str1[0];
    str1=str1.substr(3);
    str1+='\0';
    for(int i=0;i<str1.length();i++)
    {
    	if(str1[i]!='|' && str1[i]!='\0')
    	{
    		temp1+=str1[i];
		}
		else
		{
            if(temp1[0]==lhs)
			{
                alpha.push_back(temp1.substr(1));
				temp1.erase();
			}
            else
			{
                beta.push_back(temp1);
				temp1.erase();
            }
        }
    }
	if(alpha.size()==0)
	{
        cout<<"Grammar is not left-recursive";
    }
	else
    {
	    cout<<"the grammar without left recursion"<<endl;
		cout<<lhs<<"->";
		prod1+=lhs;
		prod1+='-';
		prod1+='>';
		int i;
		for(i = 0; i <(beta.size()-1); i++)
		{
            cout<<beta[i]<<lhs<<"' | ";
			prod1+=beta[i];
			prod1+=lhs;
			prod1+='\'';
			prod1+='|';
        }
		cout<<beta[i]<<lhs<<"'"<<endl;
		prod1+=beta[i];
		prod1+=lhs;
		prod1+='\'';
		prod1+='\0';
		
		cout<<lhs<<"'"<<"-> ";
		prod2+=lhs;
		prod2+='\'';
		prod2+='-';
		prod2+='>';
		for(i = 0; i<(alpha.size()); i++)
		{
            cout<<alpha[i]<<lhs<<"' |";
			prod2+=alpha[i];
			prod2+=lhs;
			prod2+='\''; 
			prod2+='|';
        }
        cout<<"E"<<endl;
        prod2+='E';
        prod2+='\0';
    }  
   return 0;
}
