#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;
// globals :
    string currentClass ;
// structs :
struct Date
{
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};

struct Student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};

struct Class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <Student> Data;
};
// vectors :
    vector < Class > Database;
// functions :
    string seprator (const string);
    void addClass(string);
    void removeClass (string);
    void AddStudnet (string , Date , unsigned long long int , float);
    void RemoveStudent(unsigned long long int);
    void showclass ();
    void start ();


int main()
{
    start();

    return 0;
}
string seprator(const string str)
{
        char seprated [40];
        size_t first , End ;
        first = str.find_first_of('<');
        End=str.find_first_of('>');
        End = End - first;
        size_t length = str.copy(seprated , End-1  , first+1);
        seprated[length]='\0';
        return seprated;
}
void start ()
{
   currentClass.clear();
   string command ;
   for (;;)
   {
     getline ( cin , command );
     if(command[0]=='e') // exit
     {
            exit(0);
     }
     else if(command[5]=='h') // help
     {
            cout << "Every command in this data base starts with the word basu !!!!"<< endl;
            cout <<  "commands in this data basu are :"<<endl;
            cout <<  "1    basu add class <Class name>       :"  <<'\n'<< " this command add a class to our data base"<<endl;
            cout <<  "2    basu remove class<Class name>        :"  <<'\n'<< "       this command delete a class from oyr dat base"<< endl;
            cout <<  "3    basu add student                                    :"  <<'\n'<< "      this coomand adds a student to our selected data base  " << endl;
            cout <<  "4    basu remove student  < ID                    :"  <<'\n'<< "      this command takes the ID and delete the student" << endl;
            cout <<  "5    basu select class <Class name>           :"  <<'\n'<< "      this command put a class on selected mode " << endl;
            cout <<  "6    basu select none                                    :"  <<'\n'<< "       this command clear a class from being selected "<<endl;
            cout <<  "7    basu search <ID>                                  :"  <<'\n'<< "        this command shows the information of a student by its id  "<<endl;
            cout <<  "8    basu search <Full Name                      :"  <<'\n'<< "        this command shows the information of a student by its fullname  "<<endl;
            cout <<  "9    basu show                                            :"  <<'\n'<< "          this command show the selected class information"<<endl;
            cout <<  "10  basu show <Class  Name>                  :"  <<'\n'<< "        this command shows the class information"<<endl;
            cout <<  "11  basu sort name                                    :"  <<'\n'<< "          this command will orgnize the students by their name in class(es)" << endl;
            cout <<  "12  basu sort id                                          :"  <<'\n'<< "           this command will orgnize the students by their IDs"<<endl;
            cout <<  "13  basu save                                               :"  <<'\n'<< "          this command will save the  information of classes in sprate files" << endl;
            cout <<  "14  exit                                                           :"  <<'\n'<< "         this command will end the programm"<<endl;
     }
     else if(command[5]==   's' && command[6]=='a')
     {

     }
     else if(command[5]==   's' && command[6]=='h')
     {

     }
     else if(command[5] == 'r' && command[12] == 'c'){ // remove class
        string name_remove_class = seprator(command);
        removeClass(name_remove_class);
        command.clear();
     }
     else if(command[5]==  'r' && command[6]=='e' && command[12]=='s') // remove student
     {
            string id = seprator(command);
            unsigned long long int ID = atoi(id.c_str());
            RemoveStudent(ID);
     }
     else if(command[5]==  's' && command[6]=='e' &&command[10]=='n')// select none
     {
            currentClass.clear();
     }
     else if(command[5]==  's' && command[6]=='e'  && command[10]=='c') // select class
     {
            currentClass = seprator(command);
     }
     else if(command[5] == 'a' && command[7] == 'd' && command[9] == 'c')//add class
     {
        string name = seprator(command);
        addClass(name);
        command.clear();
     }

   }
}

void addClass (string Str)
{
    const char* fileName = Str.c_str();
    ifstream input ;
    input.open(fileName , ios::in);
    if (!fileName)
    {
        cout << "file baz nashod";
    }
    Class newclass;
    string capacity;
    getline(input , newclass.ClassName);
    input >>capacity;
    newclass.Capacity=stoi(capacity);
    for(int i=0 ; i<=newclass.Capacity ; i++)
    {
        string birth ;
        Student newstudent;
        input >> newstudent.Firstname;
        input >> newstudent.Lastname;
        input >> birth;
        string  year , month , day;
        int year1 , month1 , day1;
        int j=0 , k=0;
        for (size_t i = 0 ; i<=3 ; i++)
        {
            year[i]=birth[i];
        }
        year1=atoi(year.c_str());
        for(size_t i=5 ; i<=6 ; i++)
        {
            month[j]=birth[i];
            j++;
        }
        month1=atoi(month.c_str());
        for (size_t i=8 ; i<=9 ; i++)
        {
	 	day[k]=birth[i];
	 	k++;
        }
        day1=atoi(day.c_str());

        newstudent.Birthday.Day=day1;
        newstudent.Birthday.Month=month1;
        newstudent.Birthday.Year=year1;
        input >> newstudent.Grade;
        input >> newstudent.ID;
        newclass.Data.push_back(newstudent);
    }
    Database.push_back(newclass);
    input.close();
    return;
}

void removeClass (string str)
{
    for(size_t i = 0 ; i<=Database.size() ; i++)
    {
        if(str == Database.at(i).ClassName)
        {
            Database.erase(Database.begin()+i);
        }
    }

}
void RemoveStudent(unsigned long long int id)
{
    for (size_t i = 0 ; i<= Database.size() ; i++)
{
           if (Database.at(i).ClassName == currentClass)
           {
               for(size_t j=0 ; j <=Database.at(i).Capacity ; j++ ){
                        if(Database.at(i).Data.at(j).ID == id)
                        {
                            Database.at(i).Data.erase(Database.at(i).Data.begin()+j);
                        }
               }
           }
    }
}
void showclass (){
    for(size_t i=0 ; i<= Database.size() ; i++){
        if(currentClass == Database.at(i).ClassName){
            for (size_t  j = 0 ; j <= Database.at(i).Capacity ; j++){
                cout << Database.at(i).Data.at(j).Firstname << " " ;
                cout << Database.at(i).Data.at(j).Lastname  << " ";
                cout << Database.at(i).Data.at(j).Birthday.Year << "/" << Database.at(i).Data.at(j).Birthday.Month << "/" << Database.at(i).Data.at(j).Birthday.Day << " ";
                cout << Database.at(i).Data.at(j).Grade << " ";
                cout << Database.at(i).Data.at(j).ID << " ";
            }
        }
    }
}
