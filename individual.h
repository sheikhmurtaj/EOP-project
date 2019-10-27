#include "libraries.h"
using namespace std;
struct Information //global structure variable
{
    double gross_annualIncome;
    double rentalIncome;
    string name;
    string idno; /*We have chosen three number '165544' 123366 154477
                you may type this number for checking as IDENTIFICATION NUMBER*/
    string maritalStatus;
    int childNum;
    int familyNum;
    int Dnum;
    int cEdreceiver; //college/university education receiver.
    double extraExpense;
    double passportNo;
    double taxableIncome;
    double taxRate;
    double payment;
    
	
} *info;  //POINTER DECLEARATION
Information *store = NULL ;
Information *next = NULL;
void individual();  //FUNCTION PROTOTYPES
void CheckIdentification();
void Checkingagain();
void caltax();
void payment();
void display();
void exit();
void deletereceipt();
extern void begining(void); 
void individual()
{
    string id;
    Information *info;
    info = new Information;
    system("CLS"); /*THIS STATEMENT HELPS TO CLEAR SCREEN*/

    cout<<"\tIDENTIFICATION NO :  ";
    cin>>info->idno;
    
	store=info;
    CheckIdentification();

}
void CheckIdentification()
{
	Information *info;
	info = store;
   if(info->idno.size() != 6)
   {
       system("CLS"); /*IN  THIS STATEMENT HELPS TO CLEAR SCREEN*/
       cout<<"\t INVALID IDENTICATION NO.PLEASE TRY AGAIN.\n";
       Sleep(1500);

       individual();
   }
   else
   {
   		
	    store=info;
    Checkingagain();

   }

}
void  Checkingagain()
{
    Information *info;
    info = store;
    system("CLS");  /* THIS STATEMENT HELPS TO CLEAR SCREEN*/
    if( info->idno == "165544" || info->idno == "123366" ||  info->idno == "154477" )
    {
        cout<<"\t YOU HAVE DONE THE ONLINE REGISTRATION .HAPPY TAX-PAYING. \n";
        
	    store=info;
	    Sleep(1000);
        caltax();

    }
   else{
        cout << "\033[2J\033[1;1H"; /*IN LINUX/WINDOWS THIS STATEMENT HELPS TO CLEAR SCREEN*/
    cout<<"\t SORRY YOU HAVEN'T DONE THE ONLINE REGISTRATION. PLEASE DO ONLINE REGISTRATION FIRST.\n";
    Sleep(1500);
    individual();
   }

}
void caltax()
{
 Information *info;
  info = new Information;
 info = store;
 cout << "\033[2J\033[1;1H";  /*IN LINUX/WINDOWS THIS STATEMENT HELPS TO CLEAR SCREEN*/
 cout<<"\t\t YOUR IDENTIFICATION IS : "<<info->idno<<endl;
 cin.ignore();
 cout<<"\t\t PLEASE ENTER YOUR NAME : ";
 getline(cin,info->name);
 cout<<"\t\t PLEASE ENTER YOUR GROSS ANNUAL INCOME :  ";
 cin>>info->gross_annualIncome;
 cout<<"\t\t PLEASE ENTER THE NUMBER OF YOUR FAMILY MEMBER: "; /*For comparing total college / education receiver from the family*/
 cin>>info->familyNum;
 cout<<"\t\t PLEASE ENTER YOUR MARITAL STATUS ([s/S]SINGLE/MARRIED[m/M]) : ";
 cin>>info->maritalStatus;
 if(info->maritalStatus == "MARRIED" || info->maritalStatus == "married"||info->maritalStatus == "m" || info->maritalStatus == "M" )
 {
     cout<<"\t\t PLEASE ENTER NUMBER OF CHILD : ";
     cin>>info->childNum;
     cout<<"\t\t PLEASE ENTER TOTAL TOTAL COLLEGE/UNIVERSITY EDUCATION RECEIVER FROM YOUR FAMILY : ";
     cin>>info->cEdreceiver;
     if(info->cEdreceiver > info->familyNum) /*Comparison between family member and college/university education receiver*/
     { 
        system("cls");
     	cout<<"\t\t EXCEEDING THE NUMBER OF FAMILY MEMBER.\n";
     	Sleep(1000);
     	caltax();
	 }
     cout<<"\t\t PLEASE ENTER YOUR EXTRA EXPENSE(MAX 3500) : ";
     cin>>info->extraExpense;
     if(info->extraExpense <= 3500 ) /*If extra-expense exceeds 3500,it will not be calculated as deductables*/
     {
         info->taxableIncome = (info->gross_annualIncome) - ((info->childNum*1000)+(info->cEdreceiver*1500)+(info->extraExpense));
        cout<<"\t\t YOUR TAXABLE INCOME IS : "<<setprecision(20)<<info->taxableIncome<<" RM "<<endl;
         
	    store=info;
        payment();
     }
      if(info->extraExpense > 3500 )
     {
         info->taxableIncome = (info->gross_annualIncome) - ((info->childNum*1000)+(info->cEdreceiver*1500));
        cout<<"\t\t YOUR TAXABLE INCOME IS : "<<setprecision(20)<<info->taxableIncome<<" RM "<<endl;
         
	    store=info;
        payment();
     }

 }
 else if(info->maritalStatus == "SINGLE" || info->maritalStatus == "single" || info->maritalStatus == "s" || info->maritalStatus == "S")
 {
     cout<<"\t\t PLEASE ENTER THE NUMBER OF PERSON DEPENDS ON YOU : ";
     cin>>info->Dnum;
     cout<<"\t\t PLEASE ENTER TOTAL COLLEGE/UNIVERSITY EDUCATION RECEIVER FROM YOUR FAMILY : ";
     cin>>info->cEdreceiver;
     if(info->cEdreceiver > info->familyNum)
     { 
        system("cls");
     	cout<<"\t\t EXCEEDING THE NUMBER OF FAMILY MEMBER.\n";
     	Sleep(1000);
     	caltax();
	 }
     cout<<"\t\t PLEASE ENTER YOUR EXTRA EXPENSE (MAX RM3500) : ";
     cin>>info->extraExpense;
     if(info->extraExpense <= 3500 )
     {
         info->taxableIncome = (info->gross_annualIncome) - ((info->Dnum*1000)+(info->cEdreceiver*1500)+(info->extraExpense));
        cout<<"\t\t YOUR TAXABLE INCOME IS : "<<setprecision(20)<<info->taxableIncome<<" RM "<<endl;
        
        
	    store=info;
        payment();
     }
     else if(info->extraExpense > 3500)
     {
     	info->taxableIncome = (info->gross_annualIncome) - ((info->Dnum*1000)+(info->cEdreceiver*1500));
        cout<<"\t\t YOUR TAXABLE INCOME IS : "<<setprecision(20)<<info->taxableIncome<<" RM "<<endl;
        
	    store=info;

        payment();
	 }
 }
}
void payment() //THE PAYMENT SECTION
{
    Information *info;
    char res;
    cout << "\033[2J\033[1;1H"; /*IN LINUX/WINDOWS THIS STATEMENT HELPS TO CLEAR SCREEN*/
    info = store;
    cout<<"\t\t\t ****************************************************************************************\n";
    cout<<"\t\t\t *******           YOUR IDENTIFICATION NO IS : "<<info->idno<<"             **********\n";
    cout<<"\t\t\t *******           YOUR NAME IS : "<<info->name<<"                          **********\n";
    cout<<"\t\t\t *******           YOUR MARITAL STATUS: "<<info->maritalStatus<<"              **********\n";
    if(info->maritalStatus == "MARRIED" || info->maritalStatus == "married"||info->maritalStatus == "m" || info->maritalStatus == "M")
    {
    cout<<"\t\t\t *******           YOUR CHILDREN: "<<info->childNum<<"                         **********\n";
	}
    cout<<"\t\t\t *******           YOUR TAXABLE INCOME IS : "<<setprecision(20)<<info->taxableIncome<<"          **********\n";
    cout<<"\t\t\t ****************************************************************************************\n";
    //Sleep(1000);
    if(info->taxableIncome <= 15000)
    {
        system("cls");
        cout<<"\t\t\t YOU HAVE NO NEED TO PAY TAX . ;) "<<endl;
        Sleep(3000);
        begining();
          
    }
    else if(info->taxableIncome > 15000 && info->taxableIncome<=25000)
    {
        info->taxRate = info->taxableIncome  * 0.025;
        cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
        cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
        cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 25000 && info->taxableIncome<= 35000)
    {
        info->taxRate = info->taxableIncome  * 0.035;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{

    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
     else if(info->taxableIncome > 35000 && info->taxableIncome<=45000)
    {
        info->taxRate = info->taxableIncome  * 0.045;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	   delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{

    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 45000 && info->taxableIncome<=55000)
    {
        info->taxRate = info->taxableIncome  * 0.055;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
    	
	    next=info;
	    delete next;  /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
		
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
     else if(info->taxableIncome > 55000 && info->taxableIncome<=65000)
    {
        info->taxRate = info->taxableIncome  * 0.065;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
    
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
     else if(info->taxableIncome > 65000 && info->taxableIncome<=75000)
    {
        info->taxRate = info->taxableIncome  * 0.075;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
    	
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
     else if(info->taxableIncome > 75000 && info->taxableIncome<=85000 )
    {
        info->taxRate = info->taxableIncome  * 0.085;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{

    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
      else if(info->taxableIncome > 85000 && info->taxableIncome<=90000 )
    {
        info->taxRate = info->taxableIncome  * 0.085;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
    
	   next=info;
	   delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT :";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 90000 && info->taxableIncome<=100000)
    {
        info->taxRate = info->taxableIncome  * 0.1;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 100000 && info->taxableIncome<=150000)
    {
        info->taxRate = info->taxableIncome  * 0.12;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	     delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
	system("cls");	
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
     else if(info->taxableIncome > 150000 && info->taxableIncome<=200000)
    {
        info->taxRate = info->taxableIncome  * 0.15;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	     delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
		
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 200000 && info->taxableIncome<=400000)
    {
        info->taxRate = info->taxableIncome  * 0.15;
    cout<<"\t\t YOU NEED TO PAY :"<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	   next=info;
	   delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
		
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }
    else if(info->taxableIncome > 400000)
    {
        info->taxRate = info->taxableIncome  * 0.35;
    cout<<"\t\t YOU NEED TO PAY :"<<setprecision(30)<<info->taxRate  <<endl;
    cout<<"\t\t DO YOU WANT TO DELETE THE CURRRENT RECIEPT AND START FROM THE BEGINING?(Y/N OR y/n):";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
	    next=info;
	    delete next; /*DESTROYING THE POINTER THAT HAS BEEN PASSED TO THE DELETE OPTION*/
    	deletereceipt();
	}
	else
	{
		
    cout<<"\t\t PLEASE ENTER THE AMOUNT AND MAKE PAYMENT : ";
    cin>>info->payment;
    while(info->payment != info->taxRate) /* While loop for ensuring complete payment*/
    {
        if(info->payment < info->taxRate)
        {
        info->taxRate = info->taxRate - info->payment;
        cout<<"\t\t YOU HAVE TO PAY MORE : "<<info->taxRate<<" RM."<<endl;
        cout<<"\t\t PlEASE PAY THE EXISTING AMOUNT :";
        cin>>info->payment;
        }
    }
    display();
    }
    }

    cout<<endl;
}
void display()
{
    char res;
	cout << "\033[2J\033[1;1H"; /*IN LINUX/WINDOWS THIS STATEMENT HELPS TO CLEAR SCREEN*/
    cout<<"\t\t********************************************************************\n";
    cout<<"\t\t|                    CONGRATULATION FOR PAYING TAX                 |\n";
    cout<<"\t\t********************************************************************\n";
    cout<<endl;
    cout<<"\t\t DO YOU WISH TO CONTINUE?(y/n OR Y/N):";
    cin>>res;
    Sleep(1000);
    if(res == 'y' || res == 'Y')
    {
    begining();
    }
    else
    {
    	exit();
	}
}
void exit()
{ 
 system("cls");
    cout<<"\t\t********************************************************************\n";
    cout<<"\t\t|         AS A LAW ABIDING CITIZEN ,ONE SHOULD PAY TAX              |\n";
    cout<<"\t\t********************************************************************\n";
}
void deletereceipt() //Function for deleting Information.
{
	system("cls");
    //Information *del; //fOR CHECKING
    //del = next;
	cout<<"\t\t INFORMATION DELETED SUCCESSFULLY.\n";
	//cout<<"\t\t Name: "<<del->name<<endl; //"TO CHECK WHETHER THE INFORMATION IS DELETED OR NOT."
	Sleep(3000);
	begining();
	
}
