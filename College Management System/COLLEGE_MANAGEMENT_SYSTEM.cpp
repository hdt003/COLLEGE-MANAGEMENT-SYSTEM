#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include"student.h"
#include"faculty.h"
using namespace std;

int main()
{
    int i=1,x;
    system("CLS");
label:
	//home page
    cout<<"\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t       College Management System\n";
    cout<<"\t\t\t-----------------------------------------\n\n\n";
    cout<<"\t\t\tEnter <1> to go in STUDENTS SECTION."<<endl;
    cout<<"\t\t\tEnter <2> to go in FACULTY SECTION."<<endl;
    cout<<"\t\t\tEnter Your Choice:";
    cin>>x;
    switch(x)
    {
    case 1:
    {
        while(i)
	{
		//student section
        cout<<"\t\t\t---:STUDENTS SECTION:---\n";
        cout<<"\n\t\t\tEnter <1> to Add new student"
            <<"\n\t\t\tEnter <2> to Display all students"
            <<"\n\t\t\tEnter <3> to Remove student"
            <<"\n\t\t\tEnter <4> to Edit student"
            <<"\n\t\t\tEnter <5> to Search student"
            <<"\n\t\t\tEnter <0> to Exit\n";
        cout<<"\t\t\tenter <10> to go home.\n"<<endl;
        cout<<"\t\t\tEnter Your Choice:";
        cin>>i;
        if(i==10)
        {
            goto label;
        }
        switch(i)
        {
        case 1 :
            fflush(stdin);
            insert_new();
            break;
        case 2 :
            show();
            break;
        case 3 :
            delete_data();
            break;
        case 4 :
            edit_data();
            break;
        case 5 :
            search_and_show();
            break;

        case 0 :
            // write_file();
            break;
        default :
            cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
        }
    }
    }
    break;
    case 2:
    {
        while(i)
	{
		//faculty section
        cout<<"\t\t\t---:FACULTY SECTION:---\n";
        cout<<"\n\t\t\tEnter <1> to Add new professor"
            <<"\n\t\t\tEnter <2> to Display all professors"
            <<"\n\t\t\tEnter <3> to Remove professor"
            <<"\n\t\t\tEnter <4> to Edit professor"
            <<"\n\t\t\tEnter <5> to Search professor"
            <<"\n\t\t\tEnter <0> to Exit\n";

        cout<<"\t\t\tenter <10> to go home.\n"<<endl;
        cout<<"\t\t\tEnter Your Choice:";
        cin>>i;
        if(i==10)
        {
            goto label;
        }
        switch(i)
        {
        case 1:
            fflush(stdin);
            insert_new_2();
            break;
        case 2 :
            show_2();
            break;
        case 3 :
            delete_data_2();
            break;
        case 4 :
            edit_data_2();
            break;
        case 5 :
            search_and_show_2();
            break;
        case 0 :
            exit(0);
            break;
        default :
            cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
        }
    }
    break;
    }
}
    return 0;
}
