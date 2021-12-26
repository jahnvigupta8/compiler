#include<bits/stdc++.h>
using namespace std;
int isKeyword(char word[]){
    char keywords[73][10] = {"alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool","break","cin",
							"cout","case","catch","class","compl","concept","const","continue","default","delete",
							"do","double","else","enum","explicit","export","extern","false","float","for","friend",
							"goto","if","import","iostream","include","inline","int","long","module","mutable","namespace",
							"new","not","operator","or","private","protected","public","register","requires","return","short",
							"signed","sizeof","static","struct","switch","template","this","true","try","typedef","union",
							"unsigned","using","virtual","void","while","xor"};
    int i, flag = 0;
    
    for(i = 0; i < 73; ++i)
	{
        if(strcmp(keywords[i], word) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}
int isOperator(char word[]){
    char operators[30][10] = {"+","-","*","/","%","++","--","==","+=","-=",
							"!=",">=","<=","&&","||","!","&","^","|","~","<<",
							"*=","/=","%=","<<=",">>=","&=","|=","^=","="};
    int i, flag = 0;
    
    for(i = 0; i < 30; ++i)
	{
        if(strcmp(operators[i], word) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}
int isSpecialSymbol(char word[]){
    char special_symbols[16][10] = {"$","#",";",":",".","@","{","}","[","]","(",")","`","<",">",'"'};
    int i, flag = 0;
    
    for(i = 0; i < 16; ++i)
	{
        if(strcmp(special_symbols[i], word) == 0){
            flag = 1;
            break;
        }
	}
    return flag;
}
int isConstant(char word[])
{
	int i;
	i = strlen(word);
	if(isdigit(word[i-1]))
		return 1;
	else
		return 0;
}
int main()
{
	ifstream code;
	code.open("add.cpp");
	char code_opt[1000],s,d='\0';
	int j = 0,cnt = 0,dq = 0;
	while(1)
	{
		s = code.get();
		if(code.eof())
			break;
		if(s == 10)
		{
			cnt = 0;
			if(code_opt[j-1] != 32)
				code_opt[j++] = 32;
			continue;
		}
		if(s == 9)
		{
			cnt = 0;
			continue;
		}
		if(isalnum(s) || s == 32)
		{
			cnt = 0;
			if(s == 32)
			{
				if(code_opt[j-1] != 32)
					code_opt[j++] = 32;
			}
			else
				code_opt[j++] = s;
		}
		else
		{
			if(cnt)
			{
				code_opt[j-1] = s;
				code_opt[j++] = ' ';
				cnt = 0;
				continue;
			}
			if(isdigit(code_opt[j-1]) && s == 46)
			{
				code_opt[j++] = s;
				continue;
			}
			if(j != 0 && code_opt[j-1] != 32)
				code_opt[j++] = ' ';
			code_opt[j++] = s;
			code_opt[j++] = ' ';
			if(s == 43 || s == 45 || s == 42 || s == 47 || s == 37 || s == 38 || s == 124 || s == 60 || s == 61 || s == 62)
				cnt = 1;
		}
	}
	code.close();
//	for(int i =0;i<strlen(code_opt);i++)
//		cout<<code_opt[i];
//	cout<<endl;
	char word[50],cdq[2];
	cdq[0] = '"';
	cdq[1] = '\0';
	j = 0;
	for(int i=0;i<strlen(code_opt);i++)
	{
		if(dq == 0)
		{
			if(code_opt[i] == 32)
			{
				word[j] = '\0';
				if(strcmp(cdq, word) == 0)
					dq = 1;
				if(isKeyword(word) == 1)
                	cout<<setw(16)<<word<< " ---------- keyword\n" ;
            	else if(isOperator(word) == 1)
            		cout<<setw(16)<<word<< " ---------- operator\n" ;
            	else if(isSpecialSymbol(word) == 1)
            		cout<<setw(16)<<word<< " ---------- special symbol\n" ;
            	else if(isConstant(word) == 1)
            		cout<<setw(16)<<word<< " ---------- constant\n" ;
            	else
            		cout<<setw(16)<<word<< " ---------- identifier\n" ;
				j = 0;
				continue;
			}
			word[j++] = code_opt[i];
		}
		if(dq)
		{
			if(code_opt[i] == '"')
			{
				dq = 0;
				word[j-1] = '\0';
				cout<<setw(16)<<word<< " ---------- string\n" ;
				cout<<setw(16)<<'"'<< " ---------- special symbol\n" ;
				i++;
				j = 0;
				continue;
			}
			word[j++] = code_opt[i];
		}
	}
	return 0;
}
