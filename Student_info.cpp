#include<iostream>
using namespace std;

class student
{
    public:
    int regNo;
    string name;
    string parentage;
    int semester;
    int rollNo;
    int attendance;
    int marks[5];  
    float percentage;

    public:
    void getDetails()
    {
        cout<<"Enter Regristration No."<<endl;
        cin>>regNo;
        cout<<"Enter Student's Name"<<endl;
        cin>>name;
        cout<<"Enter Parent's Name"<<endl;
        cin>>parentage;
        cout<<"Enter Semester"<<endl;
        cin>>semester;
        cout<<"Enter Student's Roll No."<<endl;
        cin>>rollNo;
        cout<<"Enter Student's attendance"<<endl;
        cin>>attendance;
        for (int i = 0; i < 5; i++)
        {
            cout<<"Enter "<<(i+1)<<" subject's marks"<<endl;
            cin>>marks[i];
        }
    }

    void showDetails()
    {
        cout<<"The registration number is: "<<regNo<<endl;
        cout<<"The student's name is: "<<name<<endl;
        cout<<"The parent's name is: "<<parentage<<endl;
        cout<<"The semester is: "<<semester<<endl;
        cout<<"The student's roll no. is: "<<rollNo<<endl;
        cout<<"The student's attendance is: "<<attendance<<endl;
        cout<<"Marks obtained by the student are: "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout<<"The marks obtained are"<<endl<<marks[i]<<endl;
        }
    }

    void AttRollName()
    {
        cout<<"Name: "<<name<<", Roll no.: "<<rollNo<<", attendance: "<<attendance<<endl;
    }

    void shortage()
    {
        if (attendance < 75)
        {
            cout<<"Roll No. "<<rollNo<<" Name: "<<name<<" ("<<attendance<<"%)"<<endl;
        }
    }

    void calcPercentage()
    {
        int sum = 0;
            for(int i = 0 ; i < 5 ; i++)
            {
                sum += marks[i];
            }   
            percentage = (sum / 500.0) * 100.0;
            cout<<"Name: "<<name<<", Roll no.: "<<rollNo<<", percentage: "<<percentage<<endl;
        
    }

    void show90()
    {
        if (attendance > 90 && percentage > 90)     
        {
            cout<<"Roll No.: "<<rollNo<<" Name: "<<name<<endl;
        }
    }
};

int main()
{
    student sort;
    student stdarr[10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"Enter details of "<<i+1<<" student: "<<endl;
        stdarr[i].getDetails();  
        cout<<endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout<<"The details of "<<i+1<<" student are: "<<endl;
        stdarr[i].showDetails();
        cout<<endl;
    }
    
    cout<<"The shortage cases are: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        stdarr[i].shortage();
        cout<<endl;
    }
    
    cout<<"The students who scored 90% and have attendance above 90% are:"<<endl;
    for (int i = 0; i < 10; i++)
    {
        stdarr[i].show90();
        cout<<endl;
    }
    
    cout<<"The attendance of all students is: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        stdarr[i].AttRollName();
        cout<<endl; 
    }
    
    cout<<"The percentage of all students is: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        stdarr[i].calcPercentage();
        cout<<endl;
    }
    
    cout<<"The top 5 students are: "<<endl;
    for (int i = 0 ; i < 8 ; i++)
    {
        for (int j = i+1 ; j < 9 ; j++)
        {
            if (stdarr[i].percentage < stdarr[j].percentage)
            {
                sort = stdarr[i];
                stdarr[i] = stdarr[j];
                stdarr[j] = sort;
            }
        }     
     }
    for (int i = 0; i < 5; i++) 
    {
        if (stdarr[i].percentage <= 100.0)
        {
             cout<<stdarr[i].name<<", "<<stdarr[i].rollNo<<", "<<stdarr[i].percentage<<endl;
        }
    }
return 0;
}
