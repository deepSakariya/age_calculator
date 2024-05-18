#include<iostream>
#include<time.h>
using namespace std;

//make function to calculate age
void AgeCalculate(char g , int current_date , int current_month , int current_year , int birth_date , int birth_month , int birth_year)
{
    int month[] =  { 31, 28, 31, 30, 31, 30,
					31, 31, 30, 31, 30, 31 }; //days in month

    if(birth_date > current_date){
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    } 
    if(birth_month > current_month){
        current_year = current_year - 1;
        current_month = current_month + 12;
    }  
    int calculated_date = current_date - birth_date;
    int calculated_month = current_month - birth_month;
    int calculated_year = current_year - birth_year;

    cout<<"Your Age   Year : "<<calculated_year<<" Month : "<<calculated_month<<" Day : "<<calculated_date<<endl;
    
    //for fun
    if(g == 'm' && (18 < calculated_year && calculated_year < 28)){
        cout<<"You are se*y boy :)";
    }
    if(g == 'f' && (18 < calculated_year && calculated_year < 28)){
        cout<<"You are se*y girl :)";
    }

}
int main(){
    cout<<"\n\tWelcome to age calculator\n";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //finding current date with month and year
    int current_date = tm.tm_mday;
    int current_month = tm.tm_mon + 1; //start from 0
    int current_year = tm.tm_year + 1900;

    int birth_date , birth_month , birth_year;
    char g; //for gender
    cout<<"Enter your gender m for male and f for female\t";
    cin>>g;
    cout<<"Enter your birth date\t";
    cin>>birth_date;
    cout<<"Enter your birth month\t";
    cin>>birth_month;
    cout<<"Enter your birth year\t";
    cin>>birth_year;

    //calling function
    AgeCalculate(g , current_date , current_month , current_year , birth_date , birth_month , birth_year);
    cout<<"\n";

}


