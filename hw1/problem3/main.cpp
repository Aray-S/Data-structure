#include "Stack.h"
#include "Stack.cpp"
int main()
{
	char note[100],pnote[100];
	int p=0;
	linkStack <int> s, checker;
	gets(note);
	for (int i; i<strlen(note); i++)
    {
        if (note[i]=='(') checker.push(note[i]);
        if (note[i]==')') if (checker.isEmpty()) return -1;
        else checker.pop();
    }
    if(!checker.isEmpty()) return -1;
	for(int i=0;i<strlen(note);i++)
	{
	    if (note[i]==' ') continue;
		if (note[i]=='(') s.push(note[i]);
		else
            if ((note[i]=='+')||(note[i]=='-')||(note[i]=='/')||(note[i]=='*'))
            {
                while((!s.isEmpty())&&(s.top_prior()>s.prior(note[i])))
                {
                    p++;
                    pnote[p]=s.pop();
                    p++;
                    pnote[p]=' ';
                }
                s.push(note[i]);
            }
            else
            if(note[i]==')')
            {
                while((!s.isEmpty())&&(s.top()!='('))
                {
                    p++;
                    pnote[p]=s.pop();
                    p++;
                    pnote[p]=' ';
                }
                s.pop();
            }
            else
            {
                p++;
                pnote[p]=note[i];
                if (note[i+1]>'9'||note[i+1]<'0') {p++; pnote[p]=' ';}
            }
	}
	while(!s.isEmpty())
	{
		p++;
		pnote[p]=s.pop();
	}
	for(int i=1;i<=p;i++) cout<<pnote[i];
	cout << endl;
	return 0;
}
