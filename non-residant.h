#include "libraries.h"
#define SIZE 50
int calculation(void);
extern void display();
int Indivitual_NON_RESIDANT_Cal(void)
{


    int IDD;
    int IDDNO[SIZE]={181100,181101,181102};
    std::string name;
	std::cout<<"\t\t\t|**************************|\n";
    std::cout<<"\t\t\t|                               E-TAX PAYMENT                                |\n";
    std::cout<<"\t\t\t|**************************|\n";
	std::cout<<std::endl<<std::endl;
	IDDD:
	std::cout<<"\t\t\t|ENTER YOUR IDENTIFICATION IS :";
	std::cin>>IDD;
	bool i;
	for(int x=0;x<3;x++){

        if(IDD==IDDNO[x]){
            i=true;
        }

	}
    if(!i){
            std::cout<<"\t\t\t|                  INVALID!!!"<<std::endl;
            goto IDDD;
        }
    std::cin.ignore();
	std::cout<<"\t\t\t|ENTER YOUR FULL NAME :";
	std::getline(std::cin,name);


    calculation();


}
int calculation()
{
    char status;
    char answer;
    double salary;
    double taxedInc;
    double afterTax;
    double pay;

    const double tax1 = 2000.00;
    const double tax2 = 3000.00;
    const double tax3 = 5000.00;
    const double tax4 = 7500.00;

    std::cout<<"\t\t\t|PLEASE ENTER YOUR MARITAL ATATUS: [M]arried or [S]ingle :" ;
	std::cin>>status;

	if  (status == 'm' || status =='M')
    {
            std::cout << "\t\t\t|BO BOTH SPOUSES EARN MONEY? PLEASE ENTER [Y]es or [N]o: ";
            std::cin >> answer;
              if (answer == 'y' || 'Y')
                {
                    std::cout << "\t\t\t|PLEASE ENTER YOUR COMBINED GROSS ANNUAL INCOME: ";
                    std::cin >> salary;
                }

              else if (answer == 'n' || 'N')
              {
                  std::cout << "\t\t\t|PLEASE ENTER YOUR GROSS ANNUAL INCOME : ";
                  std::cin>>salary;
              }

    }
    else
    {
        std::cout << "\t\t\t|PLEASE ENTER YOUR GROSS ANNUAL INCOME : ";
        std::cin >>salary;

    }

    std::cout<<std::endl<<std::endl<<std::endl;
			if (salary <= 30000.00)
		    {
		        std::cout << "\t\t\t|YOUR TAX RATE IS 0%, YOU HAVE NO DEDUCTION " << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME IS:  " << salary << std::endl;
		    }
		    else if (salary>=30000.01 && salary<=50000.00)
		    {
		        taxedInc = (salary - 30000.00) * .15 ;
				   //calculates tax amount
		        afterTax = salary -taxedInc;

		        std::cout << "\t\t\t|YOUR INCOME BEFORE TAX IS:  " <<setprecision(20)<< salary  << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME AFTER DEDUCTION IS:  " <<setprecision(20)<< afterTax  << std::endl;
		        std::cout << "\t\t\t|YOUR DEDUCTION AMOUNT IS " << setprecision(20)<<taxedInc <<  std::endl;
                std::cout<<"\t\t\t|PAY YOUR TAX: ";
                std::cin>>pay;
                Sleep(1500);
                display();
		    }
		    else if (salary>=50000.01 && salary<=100000.01)
		    {
		        taxedInc = ((salary - 50000.00) * .15) + tax1;      //calculates tax
		        afterTax = (salary - taxedInc);

		        std::cout << "\t\t\t|YOUR INCOME BEFORE TAX IS:  " <<setprecision(20)<< salary  << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME AFTER DEDUCTION IS:  " << setprecision(20)<<afterTax  << std::endl;
		        std::cout << "\t\t\t|YOUR DEDUCTION AMOUNT IS " <<setprecision(20)<< taxedInc <<  std::endl;
		        std::cout<<"\t\t\t|PAY YOUR TAX: ";
                std::cin>>pay;
                Sleep(1500);
                display();
		    }
		    else if (salary>=100000.01 && salary<=200000.00)
		    {
		        taxedInc = ((salary - 100000.00) * .15) + tax1 + tax2; //calculates tax
		        afterTax = (salary - taxedInc);

		        std::cout << "\t\t\t|YOUR INCOME BEFORE TAX IS:  " << setprecision(20)<<salary  << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME AFTER DEDUCTION IS:  " << setprecision(20)<<afterTax  << std::endl;
		        std::cout << "\t\t\t|YOUR DEDUCTION AMOUNT IS " << setprecision(20)<<taxedInc <<  std::endl;
		        std::cout<<"\t\t\t|PAY YOUR TAX: ";
                std::cin>>pay;
                Sleep(1500);
                display();
		    }
		    else if (salary>=200000.01 && salary<=250000.00)
		    {
		        taxedInc =((salary - 200000.00) * .15) + tax1 + tax2 + tax3;        //finds tax amount
		        afterTax = (salary -taxedInc);

		        std::cout << "\t\t\t|YOUR INCOME BEFORE TAX IS:  " <<setprecision(20)<< salary  << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME AFTER DEDUCTION IS:  " <<setprecision(20)<< afterTax  << std::endl;
		        std::cout << "\t\t\t|YOUR DEDUCTION AMOUNT IS " << setprecision(20)<<taxedInc <<  std::endl;
		        std::cout<<"\t\t\t|PAY YOUR TAX: ";
                std::cin>>pay;
                Sleep(1500);
                display();
		    }
		    else if (salary>250000.00)
		    {
		        taxedInc = ((salary - 250000.00) * .15) + tax1 + tax2 + tax3 + tax4;        //finds tax amount
		        afterTax = (salary - taxedInc);

		        std::cout << "\t\t\t|YOUR INCOME BEFORE TAX IS:  " << setprecision(20)<<salary  << std::endl;
		        std::cout << "\t\t\t|YOUR INCOME AFTER DEDUCTION IS:  " <<setprecision(20)<< afterTax  << std::endl;
		        std::cout << "\t\t\t|YOUR DEDUCTION AMOUNT IS " << setprecision(20)<<taxedInc <<  std::endl;
		        std::cout<<"\t\t\t|PAY YOUR TAX: ";
                std::cin>>pay;
                Sleep(1500);
                display();
		    }
}
