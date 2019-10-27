#include "libraries.h"
#define SIZE2 2
double calculateTax(double ,double ,double );
extern void display();
int Business_Tax_Cal()
{
    double V;
    double REvenue;
    double Salary;
    std::string name;
	std::cout<<"\t\t\t|****************************************************************************|\n";
    std::cout<<"\t\t\t|                               E-TAX PAYMENT                                |\n";
    std::cout<<"\t\t\t|****************************************************************************|\n";
	std::cout<<std::endl<<std::endl;
	std::cin.ignore();
	std::cout<<"\t\t\t|ENTER BUSINESS NAME :";
	std::getline(std::cin,name);
    std::cout<<"\t\t\t|ENTER ESTIMATE PROPERTY VALUE :";
    std::cin>>V;
    std::cout<<"\t\t\t|ENTER ESTIMATE YEARLY REVENUE :";
    std::cin>>REvenue;
    std::cout<<"\t\t\t|ENTER TOTAL SALARY OF ALL EMPLOYEE :";
    std::cin>>Salary;
    calculateTax(V,REvenue,Salary);


}

double calculateTax(double VV, double REVENUE,double ESalary )
{
    double employeeDetails;
    double tax,total_tax;
    double payment;

    std::cout<<"\t\t\t|ENTER TOTAL EMPLOYEE :";
    std::cin>>employeeDetails;

    tax=(REVENUE - ESalary);

    tax=tax/ employeeDetails;
    total_tax=(VV*0.15)+(tax*0.10*employeeDetails);
    std::cout<<"\t\t\t|TOTAL TAX IS:"<<setprecision(20)<<total_tax<<endl;
    std::cout<<"\t\t\t|MAKE YOUR PAYMENT:";
    std::cin>>payment;
    Sleep(1500);
    display();

}
