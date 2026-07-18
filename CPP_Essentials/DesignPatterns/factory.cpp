#include <iostream>
#include <memory>
using namespace std;

class shape{
    public:
    virtual void draw() const =0;
    virtual ~shape() = default;
};

class circle:public shape{
    public:
    void draw() const override{
        cout<<"drawing a circle"<<endl;
    }
};

class triangle:public shape{
    public:
    void draw() const override{
        cout<<"drawing a triangle"<<endl;
    }
};

class square:public shape{
    public:
    void draw() const override{
        cout<<"drawing a square"<<endl;
    }
};

class shapefactory{
    public:
    static unique_ptr<shape> createshape(const string& type){
        if(type == "circle") return make_unique<circle>();
        if(type == "triangle") return make_unique<triangle>();
        if(type == "square") return make_unique<square>();

        return nullptr;
    }
};

int main(){
    unique_ptr<shape> sp1 = shapefactory::createshape("circle");
    unique_ptr<shape> sp2 = shapefactory::createshape("triangle");
    unique_ptr<shape> sp3 = shapefactory::createshape("square");

    if(sp1) sp1->draw();
    if(sp2) sp2->draw();
    if(sp3) sp3->draw();

    return 0;
}