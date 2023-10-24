#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Student
{
    public:
    int rno;
    string name;
    void get()
    {  
    cout<<"ENTER NAME ::";
    cin>>name;
    cin.ignore();
    cout<<"ENTER RNO :: ";
    cin>>rno;
    }
    void disp()
    {
        cout<<"NAME ::"<<name<<endl;
        cout<<"ROLL NO ::"<<rno<<endl;
    }
}s;
int main()
{   int ch;
     
    do
    {
    cout<<"1.WRITE\n2.READ\n3.SEARCH\n4.DELETED\n5.EXIT";
    cin>>ch;
    if(ch==1)
    {   ofstream w;
        w.open("FILE.txt",ios::app|ios::out);
        if(!w)
        {
        cout<<"FILE NOT OPEND ";
        }
         
        s.get();
        w.write((char*)&s,sizeof(s));
        cout<<"::: FILE WRITE SUCCUCCSFULLY :::"<<endl;
        w.close();
    }
    else if(ch==2)
    {       ifstream r;
            r.open("FILE.txt");
             
            if(!r)
            {
            cout<<"FILE NOT OPEND ";
            }
            r.seekg(0,ios::beg);
            while(!r.eof())
            {
                r.read((char*)&s,sizeof(s));
                if(r.eof()){
                    break;
                }
                else
                {  
                s.disp();
                }
            }
             
            r.close();
             
             
    }
    else if(ch==3)
    {       ifstream r1;
            r1.open("FILE.txt",ios::in);
            int ser;
            int f=0;
            if(!r1)
            {
            cout<<"FILE NOT OPEND "<<endl;
            }
             
            cout<<"ENTER THE DATA TO BE SEARCHED FROM FILE ::";
            cin>>ser;
            r1.seekg(0,ios::beg);
            while(!r1.eof())
            {
                r1.read((char*)&s,sizeof(s));
                if(r1.eof())
                break;
                else if(s.rno==ser)
                {  
                s.disp();
                cout<<"::: DATA IS PRESENT IN FILE ::: "<<endl;
                f++;
                }
            }
            if(f==0)
            cout<<":: NO DATA iS PRESENT IN IT ::"<<endl;
            r1.close();
    }
    else if(ch==4)
    {      
            ifstream r2;
            r2.open("FILE.txt",ios::in);
             
            ofstream w2;
            w2.open("temp.txt",ios::app|ios::out);
             
            int ser;
            int f=0;
             
            if(!r2&&!w2)
            {
            cout<<"FILE NOT OPEND "<<endl;
            }
             
             
            cout<<"ENTER THE DATA TO BE DELETED FROM FILE ::";
            cin>>ser;
            r2.seekg(0,ios::beg);
            while(!r2.eof())
            {
                r2.read((char*)&s,sizeof(s));
                 
                if(r2.eof())
                break;
                 
                else if(s.rno==ser)
                {  
                    s.disp();
                    cout<<"::: DATA DELETED FROM  FILE ::: "<<endl;
                    f++;
                }
                 
                else
                {
                    w2.write((char*)&s,sizeof(s));
                }
            }
            if(f==0)
            cout<<":: NO DATA  DELETED FROM IT ::"<<endl;
            else
            {
                remove("FILE.txt");
                rename("temp.txt","FILE.txt");
            }
            r2.close();
            w2.close();
    }
     
     
     
    }while(ch!=5);
}
