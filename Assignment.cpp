//Name:Murtaj Sheikh Mohammad Tahsin //Matric no : 1817537
//Name:Shahriar Fahim //Matric no :  1734075
#include<iostream>
#include<iomanip>
using namespace std;
const int ROWS = 8;
const int COLS = 3;
void truth(int [ROWS][COLS]);
int main()
{
	int i,j;
	int value[ROWS][COLS];
	for(i=0;i<ROWS;++i)
	{
		cout<<"Row "<<i+1<<endl;
		for(j=0;j<COLS;j++)
		{
		 if(j==0)
		 {
		  cout<<"Enter value for p:";
	     }
	     else if(j==1)
	     {
	     	cout<<"Enter value for q:";
		 }
		 else if(j==2)
		 {
		 	cout<<"Enter value for r:";
		 }
		    cin>>value[i][j];
		}
   
		if(value[i][j]>1 && value[i][j]<0)
		{
			cout<<"Invalid input."<<endl;
			return 0;
		}
	}
	truth(value);
	return 0;
}
void truth(int values[ROWS][COLS])
{
	int i,j;
	int p,q,r;
	cout<<"  "<<"p"<<"  "<<"q"<<"  "<<"r"<<"   "<<"!(p || q)"<<"   "<<"!p && !q"<<"   "<<"(p || q) && !r"<<"   "<<"!(p || (!q && r))"<<endl;
	for(i=0;i<ROWS;++i)
	{
		for(j=0;j<COLS;++j)
		{
			cout<<setw(3)<<values[i][j];
			if(j==0)
			{
				p=values[i][j];
			}
			else if(j==1)
			{
				q=values[i][j];
			}
			else if(j==2)
			{
				r=values[i][j];
			}
		}
		cout<<"       "<<!(p || q);
		cout<<"          "<<!p && !q;
		cout<<"         "<<(p || q) && !r;
		cout<<"                    "<<!(p || (!q && r));
		cout<<endl;
	}
}
