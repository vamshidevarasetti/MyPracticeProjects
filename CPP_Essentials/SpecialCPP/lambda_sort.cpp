#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

int main(){

    vector<Employee> Emplist;
    //Employee E1 = {"vamshi", 20, 3000};
    //Emplist.push_back (E1);
    Emplist = {
        {"Alice", 30, 70000},
        {"Bob", 25, 50000},
        {"Charlie", 35, 80000}
    };

    sort(Emplist.begin(), Emplist.end(), [](const Employee& a, Employee& b){return a.salary > b.salary;});

    for(const auto & val: Emplist){
        cout<<val.name << " "<<val.age<<" "<<val.salary<<endl;
    }
    cout<<endl;

    Emplist.erase(remove_if(Emplist.begin(), Emplist.end(), [](const Employee& e){ return e.age> 30;}), Emplist.end());

    cout <<"after erasing few elements"<<endl;

    for(const auto & val: Emplist){
        cout<<val.name << " "<<val.age<<" "<<val.salary<<endl;
    }
}
