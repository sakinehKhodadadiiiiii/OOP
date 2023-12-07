#include <iostream>

using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee : AbstractEmployee{
    private:
        string Company;
        int Age;
    protected:
        string Name;
    public:
    void setName(string name){// setter
        Name = name;
    }
    string getName(){// getter
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age >= 18){// set validation rule
            Age = age;
        }
    }
    int getAge(){
        return Age;
    }
    void introduceYourself(){// object function
        cout << "My name is " << Name << " and I am working at " << Company << " and I am " << Age << " years old." << endl;
    }
    Employee(string name, string company, int age){// object constructor
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion(){
        if(Age > 40){
            cout << Name << " got promoted" << endl;
        }else{
            cout << Name << " sorry no promotion" << endl;
        }
    }
    virtual void Work(){
        cout << Name << " checking emails, task backlog, performing tasks..." << endl;
    }
};

class Developer: public Employee{
    public:
    string FavProgLanguage;
    Developer(string name, string company, int age, string favProgLanguage)
        :Employee(name, company, age)
    {
        FavProgLanguage = favProgLanguage;
    }
    void fixBug(){
        cout << getName() << " fixed bugs using " << FavProgLanguage << endl;
    }
    void Work(){
        cout << Name << " is writing " << FavProgLanguage << " code, debugging...." << endl;
    }
};

class Teacher: public Employee{
    public:
    string Subject;
    void prepareLesson(){
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string name, string company, int age, string subject)
    : Employee(name,company,age)
    {
        Subject = subject;
    }
    void Work(){
        cout << Name << " is teaching " << Subject << " lesson" << endl;
    }
};

int main()
{
    Employee employee1("John", "Amazon", 35);
    employee1.introduceYourself();

    Employee employee2("James", "Apple", 45);
    employee2.introduceYourself();

    employee1.setAge(36);
    cout << employee1.getAge() << endl;

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Developer devloper1("Sakineh", "Nasa", 35,"C++");
    devloper1.fixBug();
    devloper1.AskForPromotion();

    Teacher teacher1("Jassica", "High School", 45, "Math");
    teacher1.prepareLesson();
    teacher1.AskForPromotion();

    //teacher1.Work();
    //devloper1.Work();

    Employee *e1 = &devloper1;
    Employee *e2 = &teacher1;

    e1->Work();
    e2->Work();

    return 0;
}
