#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

//class for student
class student
{
public:
    long int id;
    char Name[80],branch[50],club[100];
    void input()
    {
          fflush(stdin);
        cout<<"\n Enter Name: ";
        gets(Name);
        cout<<"\n Enter ID: ";
        cin>>id;
        fflush(stdin);
        cout<<"\n Enter Branch: ";
        gets(branch);
        ///////
        cout<<"These are clubs in our college:\n";
        cout<<"||SPORTS CLUB||\n||PROGRAMMING CLUB||\n||CUBING CLUB||\n||BUSINESS CLUB||\n||RADIO CLUB||\n||MUSIC CLUB||\n||DANCE CLUB||\n||PHOTOGRAPHY CLUB||\n||MSTC CLUB||\n||DEVLOPER STUDENT CLUB||\n||PRESS CLUB||";
        cout<<"\n Enter club name that you want to join: ";
        gets(club);
    }
    void display()
    {
        system("CLS");
        cout<<"\t\tDisplay Records";
        cout<<"\n";
        cout<<"\n Name - "<<Name;
        cout<<"\n ID. - "<<id;
        cout<<"\n Branch - "<<branch;
        cout<<"\n club - "<<club;
        cout<<"\n";
        system("PAUSE");
        system("CLS");
    }
    /*bool operator == (student a)
    {
        if(id==a.id)
            return true;
        else
            return false;
    }*/
};

vector <student>v;
int search_id(long int id,int &i);


//to insert new data of student
void insert_new()
{
    char ch='y';
    int ta;
    while(ch=='y')
    {
        fflush(stdin);
        student x;
        x.input();
        if(search_id(x.id,ta)==0)
            v.push_back(x);
        else
            cout<<"\nTHE ID IS ALREADY EXIST!!!\nCANNOT ADD";
        fflush(stdin);
        cout<<"\n Press [y/n] to enter more: ";
        fflush(stdin);
        cin>>ch;
        fflush(stdin);
    }
}

//to search by id of student
int search_id(long int id,int &i)
{
    int ta=0;
    for(i=0; i<v.size(); i++)
        if(v[i].id==id)
        {
            ta=1;
            break;
        }
    return ta;
}
//to search by name of student
int search_Name(char Name[],vector<int> &vi)
{
    int i,ta=0;
    for(i=0; i<v.size(); i++)
        if(strcmp(v[i].Name,Name)==0)
        {
            ta=1;
            vi.push_back(i);
        }
    return ta;
}
//to search by branch of student
int search_branch(char branch[],vector<int> &vj)
{
    int i,ta=0;
    for(i=0; i<v.size(); i++)
        if(strcmp(v[i].branch,branch)==0)
        {
            ta=1;
            vj.push_back(i);
        }
    return ta;
}
//to search and show the id,Name and branch of student
void search_and_show()
{
    int ch,i,ta=0;
    char Name[80],branch[50];
    vector <int>vi;
    vector <int>vj;
    long int id;
poi:
    cout<<"\nPress 1 to search ID."
        <<"\nPress 2 to search Name."
        <<"\nPress 3 to search branch.";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\nEnter ID.: ";
        cin>>id;
        if(search_id(id,i)==1)
            v[i].display();
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    case 2:
        cout<<"\nEnter Name: ";
        fflush(stdin);
        gets(Name);
        if(search_Name(Name,vi)==1)
        {
            for(int j=0; j<vi.size(); j++)
                v[vi[j]].display();
        }
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    case 3:
        cout<<"\nEnter branch: ";
        fflush(stdin);
        gets(branch);
        if(search_branch(branch,vj)==1)
        {
            for(int j=0; j<vj.size(); j++)
                v[vj[j]].display();
        }
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    default:
        cout<<"\nWrong CHOICE!!!";
        goto poi;
    }
}
void show()
{
    int i;
    for(i=0; i<v.size(); i++)
        v[i].display();
}
//to delete data of student
void delete_data()
{
    int i,j;
    long int id;
    vector <student>::iterator p=v.begin();
    cout<<"\nEnter ID no.: ";
    cin>>id;
    if(search_id(id,i)==1)
    {
        student x=v[i];
        cout<<"\nThe following data is being deleted";
        x.display();
        p+=i;
        v.erase(p,p+1);
    }
}
//to edit student data
void edit_data()
{
    int i,j;
    long int id;
    vector <student>vi;
    cout<<"\nEnter ID no.: ";
    cin>>id;
    if(search_id(id,i)==1)
    {
        cout<<"\nEnter new data:";
        fflush(stdin);
        v[i].input();
    }
}