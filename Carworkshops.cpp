using namespace std;
#include<iostream>
#include<fstream>
#include<string.h>//for strcmp and strcpy
#include<stdlib.h>//for exit function
#include<conio.h>
#include<stdio.h>//for rename and remove
int cnt=0;
class workshop
{
    public:
    char c_name[30],car_no[15],problem[100],date[20],car_model[20],car_company[20],car_type[10],del_status[15];
    char exp_deli_days[5],estimated_cost[7];
    void in();
    void modify();
    void display();
    void check(char []);
}obj[100];
void workshop::in()
{
    fflush(stdin);
   cout<<"\nCustomer Name-> ";
   gets(c_name);
   cout<<"\nCar Number-> ";
   gets(car_no);
   try
   {
       ifstream FILE;
       int i=0;
       FILE.open("garage.txt",ios::in|ios::binary);
       while(FILE.read((char *)&obj[i],sizeof(obj[i])))
       {
           if(strcmp(obj[i].car_no,car_no)==0)
            throw (car_no);
       }
   }
   catch(char [])
   {
       cout<<"CAR NUMBER ALREADY EXIST";
       exit(0);
   }
   cout<<"\nProblem in Car-> ";
   gets(problem);
   cout<<"\nCar received Date(dd/mm/yyyy)-> ";
   gets(date);
   cout<<"\nCar company-> ";
   gets(car_company);
   cout<<"\nCar Model-> ";
   gets(car_model);
   cout<<"\nCar Type-> ";
   gets(car_type);
   cout<<"\nDelivery Status-> ";
   gets(del_status);
   cout<<"\nExpected Delivery Days-> ";
   gets(exp_deli_days);
   try
   {
       if(strcmp(exp_deli_days,"0")==-1)
        throw (exp_deli_days);
   }
   catch(char [])
   {
       cout<<"\n\nYOU ARE NOT ALLOWED TO ENTER NEGATIVE VALUES";
       exit(0);
   }
   cout<<"\nEstimated Cost Of Service-> ";
   gets(estimated_cost);
   try
   {
       if(strcmp(estimated_cost,"0")==-1)
        throw (estimated_cost);
   }
   catch(char [])
   {
       cout<<"\n\nYOU ARE NOT ALLOWED TO ENTER NEGATIVE VALUES";
       exit(0);
   }
}
void workshop::modify()
{
   char c_name1[30],car_no1[20],problem1[100],date1[20],car_type1[10],car_company1[20],del_status1[15],car_model1[20];
    char exp_deli_days1[5],estimated_cost1[7];
   cout<<"Enter New Details\n";
   fflush(stdin);
   cout<<"\nCustomer Name(Enter '.' to retain old one)-> ";
   gets(c_name1);
   cout<<"\nCar Number(Enter ',' to retain old one)-> ";
   gets(car_no1);
   cout<<"\nProblem in Car(Enter '/' to retain old one)-> ";
   gets(problem1);
   cout<<"\nCar received Date(Enter '<' to retain old one)-> ";
   gets(date1);
   cout<<"\nCar company(Enter '>' to retain old one)-> ";
   gets(car_company1);
   cout<<"\nCar Type(Enter '?' to retain old one)-> ";
   gets(car_type1);
   cout<<"\nCar Model(Enter '3' to retain old one-> ";
   gets(car_model);
    cout<<"\nDelivery Status(Enter '+' to retain old one)-> ";
   gets(del_status1);
   cout<<"\nExpected Delivery Days(Enter '5' to retain old one)-> ";
   gets(exp_deli_days1);
   cout<<"\nEstimated Cost Of Service(Enter '6' to retain old one)-> ";
   gets(estimated_cost1);
    if(strcmp(c_name1,".")!=0)
        strcpy(c_name,c_name1);
   if(strcmp(car_no1,",")!=0)
        strcpy(car_no,car_no1);
   if(strcmp(problem1,"/")!=0)
        strcpy(problem,problem1);
    if(strcmp(date1,"<")!=0)
        strcpy(date,date1);
    if(strcmp(car_company1,">")!=0)
        strcpy(car_company,car_company1);
    if(strcmp(car_model1,"3")!=0)
        strcpy(car_model,car_model1);
    if(strcmp(car_type1,"?")!=0)
        strcpy(car_type,car_type1);
    if(strcmp(exp_deli_days1,"5")!=0)
        strcpy(exp_deli_days,exp_deli_days1);
    if(strcmp(estimated_cost1,"6")!=0)
        strcpy(estimated_cost,estimated_cost1);
    if(strcmp(del_status1,"+")!=0)
        strcpy(del_status,del_status1);
}
void workshop::display()
{
    cout<<"\nCustomer Name-> ";
   puts(c_name);
   cout<<"\nCar Number-> ";
   puts(car_no);
   cout<<"\nProblem in Car-> ";
   puts(problem);
   cout<<"\nCar received Date-> ";
   puts(date);
   cout<<"\nCar company-> ";
   puts(car_company);
   cout<<"\nCar Type-> ";
   puts(car_type);
   cout<<"\nDelivery Status-> ";
   puts(del_status);
   cout<<"\nDelivery Days-> ";
   puts(exp_deli_days);
   cout<<"\nCost Of Service-> ";
   puts(estimated_cost);
}
int main()
{
    int ch,n;
    y:cout<<"WELCOME TO CAR WORK SHOP\n";
    cout<<"************************\n\n";
    cout<<"\n[1] ADD NEW CUSTOMER DETAILS";
    cout<<"\n[2] EDIT DETAILS OF CUSTOMER";
    cout<<"\n[3] DELETE DETAILS OF CUSTOMER";
    cout<<"\n[4] VIEW DETAILS OF ALL CUSTOMER";
    cout<<"\n[5] SERACH FOR PARTICULAR CUSTOMER";
    cout<<"\n[6] MORE OPTIONS";
    cout<<"\n[7] EXIT";
    cout<<"\n\n\nEnter your choice:- ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            {
                cout<<"\nEnter the Following Details:-\n";
                ofstream FILE;
                int x=0;
                char ans='y';
                FILE.open("garage.txt",ios::app);
                while(ans=='y'||ans=='Y')
                {
                    obj[x].in();
                    FILE.write((char *)&obj[x],sizeof(obj[x]));
                    cout<<"\n\nWant to enter more records?(y/n):- ";
                    cin>>ans;
                    if(ans=='y'||ans=='Y')
                        x++;
                }
                FILE.close();
                cout<<"Details Of Customer added successfully in the file\n";
                break;
            }
        case 2:
            {
                fstream FILE;

                int pos,found=1,c=0;
                char na[20];
                fflush(stdin);
                cout<<"\nEnter Customer Name Whose Details You want to edit -> ";
                gets(na);
                FILE.open("garage.txt",ios::in|ios::out|ios::binary|ios::ate);
                FILE.seekp(0);
                while(FILE.read((char *)&obj[c],sizeof(obj[c]))&&found==1)
                {

                    if(strcmp(obj[c].c_name,na)==0)
                    {
                        obj[c].modify();
                        int pos=-1*sizeof(obj[c]);
                        FILE.seekp(pos,ios::cur);
                        FILE.write((char *)&obj[c],sizeof(obj[c]));
                        found=0;
                    }
                    else
                    c++;
                }
                FILE.close();
                if(found==1)
                    cout<<"Record Not Found!!\n";

                break;
            }
        case 3:
            {

                int flag=0,co=0;
                char mmm[20];
                cout<<"\n\n\n\tDELETE RECORD...";
                cout<<"\n\nEnter the name of customer You Want To Delete : ";
                fflush(stdin);
                gets(mmm);
                fstream fp;
                fp.open("garage.txt",ios::in|ios::out);
                fstream fp2;
                fp2.open("Temp.txt",ios::out);
                fp.seekg(0,ios::beg);
                while(fp.read((char*)&obj[co],sizeof(obj[co])))
                {
                    if(strcmp(obj[co].c_name,mmm)==0)
                    flag=1;
                    else
                    fp2.write((char*)&obj[co],sizeof(obj[co]));
                    co++;
                }

                fp2.close();
                fp.close();
                remove("garage.txt");
                rename("Temp.txt","garage.txt");
                if(flag==1)
                cout<<"\n\n\tRecord Deleted ..";
                else
                cout<<"\n\nRecord not found";
     		break;
            }
        case 4:
            {
                ifstream FILE,fo;
                FILE.open("garage.txt",ios::in|ios::binary);

                int x=0;
                cout<<"The Content Of the file is\n\n ";
                FILE.seekg(0);
                while(FILE.read((char *)&obj[x],sizeof(obj[x])))
                {

                    obj[x].display();
                    x++;
                }
                FILE.close();
                break;
            }
        case 5:
            {
                char nn[20],cc[10];
                int choi;

                ifstream FILE;

                cout<<"\n[1] Search by Name\n";
                cout<<"\n[2] Search by Car Number\n";
                cout<<"\nEnter your choice-> ";
                cin>>choi;


                if(choi==1)
                {
                     int x=0;
                     fflush(stdin);
                    cout<<"\nEnter Name of customer you want to search -> ";

                    gets(nn);
                     FILE.open("garage.txt",ios::in|ios::binary);
                FILE.seekg(0);
                int found=1;
                    while(FILE.read((char *)&obj[x],sizeof(obj[x]))&&found==1)
                    {
                        if(strcmp(obj[x].c_name,nn)==0)
                        {
                            obj[x].display();
                            found=0;
                        }
                        else
                        x++;

                    }
                    FILE.close();
                    if(found==1)
                        cout<<"Customer does not exist";

                }
                else
                {
                    if(choi==2)
                    {
                        int x=0;
                        fflush(stdin);
                        cout<<"Enter Car Number of Customer ";
                        gets(cc);
                        int found=0;
                        ifstream FILE;
                        FILE.open("garage.txt",ios::in|ios::binary);
                        while(FILE.read((char *)&obj[x],sizeof(obj[x]))&&found==0)
                        {
                            if(strcmp(obj[x].car_no,cc)==0)
                            {
                                obj[x].display();
                                found=1;
                                break;
                            }
                            else
                            {
                                x++;
                            }
                        }
                        if(found=='n')
                            cout<<"Customer does not exist";
                        FILE.close();
                    }
                }
                break;
            }
        x:case 6:
            {
                int choice;
                cout<<"\n[1] TOTAL NUMBER OF CARS DELIVERED OR NOT DELIVERED";
                cout<<"\n[2] TOTAL NUMBER OF CARS DELIVERED";
                cout<<"\n[3] TOTAL NUMBER OF CARS NOT DELIVERED";
                cout<<"\n[4] TOTAL NUMBER OF CARS RECIEVED ON PARTICULAR DATE";
                cout<<"\n[5] GO BACK";
                cout<<"\n[6] EXIT";
                cout<<"\n\nEnter your choice:- ";
                cin>>choice;
                switch(choice)
                {
                case 1:
                    {
                        int n=0,x=0;
                        ifstream FILE;
                        FILE.open("garage.txt",ios::in|ios::binary);
                        while(FILE.read((char *)&obj[x],sizeof(obj[x])))
                        {
                            n++;
                            x++;
                        }
                        cout<<"Total number of cars:- "<<n;
                        break;
                    }
                case 2:
                    {
                        int n=0,x=0;
                        ifstream FILE;
                        FILE.open("garage.txt",ios::in|ios::binary);
                        while(FILE.read((char *)&obj[x],sizeof(obj[x])))
                        {
                            if(strcmpi(obj[x].del_status,"Delivered")==0)
                                n++;
                            else
                                x++;
                        }
                        cout<<"Total Number of Cars Delivered:- "<<n;
                        break;
                    }
                case 3:
                    {
                         int n=0,x=0;
                        ifstream FILE;
                        FILE.open("garage.txt",ios::in|ios::binary);
                        while(FILE.read((char *)&obj[x],sizeof(obj[x])))
                        {
                            if(strcmpi(obj[x].del_status,"Not Delivered")==0)
                                n++;
                            else
                                x++;
                        }
                        cout<<"Total Number of Cars Not Delivered Yet:- "<<n;
                        break;
                    }
                case 4:
                    {
                         int n=0,x=0;
                         char dd[12];
                         fflush(stdin);
                         cout<<"Enter the date(dd/mm/yyyy):- ";
                         gets(dd);
                        ifstream FILE;
                        FILE.open("garage.txt",ios::in|ios::binary);
                        while(FILE.read((char *)&obj[x],sizeof(obj[x])))
                        {
                            if(strcmpi(obj[x].date,dd)==0)
                                n++;
                            else
                                x++;
                        }
                        cout<<"Total Number of Cars received on this date :- "<<n;
                        break;
                    }
                case 5:
                    {
                        goto y;
                    }
                case 6:
                    {
                        exit(0);
                    }
                default:
                    {
                        cout<<"You Entered wrong choice ";
                        goto x;
                    }
                }
                break;
            }
        case 7:
            {
                exit(0);
                break;
            }
        default:
            {
                cout<<"You entered wrong choice";
                goto y;
            }
    }
}
