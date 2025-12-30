#include<iostream>

using namespace std;


//stratergy interface

class paymentstrategy{
    public:
    virtual void pay(double amount) =0;
    virtual ~paymentstrategy()= default;
};

//concrete statergy
class credicardpayment :public paymentstrategy
{
    public:
    void pay(double amount) override{
        cout<<"creditcard payment " << amount<< endl;
    }
};
class upipayment :public paymentstrategy
{
    public:
    void pay(double amount) override{
        cout<<"UPI payment " << amount<< endl;
    }
};

//context class

class paymentcontext{
    private:
        paymentstrategy* strategy;
    public:
        void setstrategy(paymentstrategy* s){
            strategy = s;
        }

        void processpayment(double amount){
            if(strategy){
                strategy->pay(amount);
            }
            else
                cout <<"no payment strategy selected"<<endl;
        }

};


//main code

int main()
{
    paymentcontext context;

    credicardpayment cc;
    upipayment upi;

    context.setstrategy(&cc);
    context.processpayment(100);

    context.setstrategy(&upi);
    context.processpayment(500);

    return 0;

}