#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class User{
    public:
        int id;
        double score;
        char grade;

        User() = default;
        User(int i, double s, char g): id(i), score(s), grade(g){}

        void display(){
            cout << id<< " "<< score << " "<< grade << endl;
        }

};

void serialize(User& user, const string& filename){
    ofstream ofs(filename, ios::binary);
    if(!ofs) throw runtime_error("Failed to open for writing");
    ofs.write(reinterpret_cast<const char*>(&user.id), sizeof(user.id));
    ofs.write(reinterpret_cast<const char*>(&user.score), sizeof(user.score));
    ofs.write(reinterpret_cast<const char*>(&user.grade), sizeof(user.grade));

}

User deserialize (const string& filename){
    User user;
    ifstream ifs(filename, ios::binary);
    if(!ifs) throw runtime_error("Failed to open for reading");
    ifs.read(reinterpret_cast<char*>(&user.id), sizeof(user.id));
    ifs.read(reinterpret_cast<char*>(&user.score), sizeof(user.score));
    ifs.read(reinterpret_cast<char*>(&user.grade), sizeof(user.grade));
    return user;
}

int main(){

    User orininal(42, 98.6, 'A');
    serialize(orininal, "user.dat");
    User data = deserialize("user.dat");
    data.display();

    return 0;
}