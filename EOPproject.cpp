#include "libraries.h"
#include "individual.h"
#include "business.h"
#include "non-residant.h"
void begining(void);
using namespace std;
int main()
{
    int a;
    begining();
    return 0;

}
void begining(void)
{
    int select;
    system("cls");
    cout<<"\t\t\t|****************************************************************************|\n";
    cout<<"\t\t\t|                               E-TAX PAYMENT                                |\n";
    cout<<"\t\t\t|****************************************************************************|\n";
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t|****** SELECT ONE FILING STATUS :----- *************************************|\n";
    cout<<"\t\t\t|***** 1.INDIVIDUAL                  \n";
    cout<<"\t\t\t|***** 2.BUSINESS                    \n";
    cout<<"\t\t\t|***** 3.NON-RESIDANT                \n";
    cout<<"\t\t\t|***** 4.EXIT                \n";
    cout<<"\t\t\t| CHOOSE ONE FROM THREE :";
    cin>>select;
    switch(select)
    {
        case   1: individual();
                  break;
       case   2:  system("cls");
                  Business_Tax_Cal();
                  break;
        case   3: system("cls");
                  Indivitual_NON_RESIDANT_Cal();
                  break;
        case   4:
                  system("pause");
                  break;
        default: cout<<"\t\t\t| INVALID INPUT .PLEASE TRY AGAIN!    \n";
                 //Sleep(2000);
                 begining();
                 break;

    }
}
