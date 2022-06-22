#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//class for faculty
class faculty
{
public:
    long int id;
    char Name[80],subject[50];
    void input()
    {
        fflush(stdin);
        cout<<"\n Enter Name: ";
        gets(Name);
        fflush(stdin);
        cout<<"\n Enter Phone no.: ";
        cin>>id;
        fflush(stdin);
        cout<<"\n Enter subject: ";
        gets(subject);

    }
    void display()
    {
        system("CLS");
        cout<<"\t\tDisplay Records";
        cout<<"\n";
        cout<<"\n Name - "<<Name;
        cout<<"\n Phone no. - "<<id;
        cout<<"\n subject - "<<subject;

        cout<<"\n";
        system("PAUSE");
        system("CLS");
    }
    bool operator == (faculty a2)
    {
        if(id==a2.id)
            return true;
        else
            return false;
    }
};

vector <faculty>v2;

int search_id_2(long int id,int &i);


//to insert new data of faculty
void insert_new_2()
{
    char cha='y';
    int ta;
    while(cha=='y')
    {
        faculty x;
        x.input();

        if(search_id_2(x.id,ta)==0)
        {
            v2.push_back(x);}
        else
        {
            cout<<"\nTHE Phone No. IS ALREADY EXIST!!!\nCANNOT ADD";}
        cout<<"\n Press [y/n] to enter more: "<<endl;
        cin>>cha;
    }
}

//to serch by ID of faculty
int search_id_2(long int id,int &i)
{
    int ta=0;
    for(i=0; i<v2.size(); i++)
        if(v2[i].id==id)
        {
            ta=1;
            break;
        }
    return ta;
}

//search by name of faculty
int search_Name_2(char Name[],vector<int> &vi)
{
    int i,ta=0;
    for(i=0; i<v2.size(); i++)
        if(strcmp(v2[i].Name,Name)==0)
        {
            ta=1;
            vi.push_back(i);
        }
    return ta;
}

//to search by subject of faculty
int search_subject_2(char subject[],vector<int> &vj)
{
    int i,ta=0;
    for(i=0; i<v2.size(); i++)
        if(strcmp(v2[i].subject,subject)==0)
        {
            ta=1;
            vj.push_back(i);
        }
    return ta;
}
//to search and show_2 the id,Name and subject of faculty
void search_and_show_2()
{
    int ch,i,ta=0;
    char Name[80],subject[50];
    vector <int>vi;
    vector <int>vj;
    long int id;
poi:
    cout<<"\nPress 1 to search Phone No.."
        <<"\nPress 2 to search Name."
        <<"\nPress 3 to search subject.";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\nEnter Phone No.: ";
        cin>>id;
        if(search_id_2(id,i)==1)
            v2[i].display();
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    case 2:
        cout<<"\nEnter Name: ";
        fflush(stdin);
        gets(Name);
        if(search_Name_2(Name,vi)==1)
        {
            for(int j=0; j<vi.size(); j++)
                v2[vi[j]].display();
        }
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    case 3:
        cout<<"\nEnter subject: ";
        fflush(stdin);
        gets(subject);
        if(search_subject_2(subject,vj)==1)
        {
            for(int j=0; j<vj.size(); j++)
                v2[vj[j]].display();
        }
        else
            cout<<"\nRecord NOT FOUND!!!";
        break;
    default:
        cout<<"\nWrong CHOICE!!!";
        goto poi;
    }
}

void show_2()
{
    int i;
    for(i=0; i<v2.size(); i++)
        v2[i].display();
}

//to delete data of faculty member
void delete_data_2()
{
    int i,j;
    long int id;
    vector <faculty>::iterator p=v2.begin();
    cout<<"\nEnter Phone No. ";
    cin>>id;
    if(search_id_2(id,i)==1)
    {
        faculty x=v2[i];
        cout<<"\nThe following data is being deleted";
        x.display();
        p+=i;
        v2.erase(p,p+1);
    }
}

//to edit data of faculty
void edit_data_2()
{
    int i,j;
    long int id;
    vector <faculty>vi;
    cout<<"\nEnter Phone No.: ";
    cin>>id;
    if(search_id_2(id,i)==1)
    {
        cout<<"\nEnter new data:";
        fflush(stdin);
        v2[i].input();
    }
}