#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class observer{
    public:
    virtual void update(double temperature)=0;
};

class subject{
    public:
    virtual void addobserver(observer* obs)=0;
    virtual void removeobserver(observer *obs)=0;
    virtual void notifyobservers() = 0;
};

class weather:public subject{
    private:
    vector<observer*> observers;
    float temperature;
    
    public:
    void addobserver(observer* obs){
        observers.push_back(obs);
    }
    void removeobserver(observer *obs){
        observers.erase(remove(observers.begin(), observers.end(), obs),observers.end());
    }
    void updatetemp(double t){
        temperature = t;
        notifyobservers();
    }
    void notifyobservers(){
        for(auto obs:observers){
            obs->update(temperature);
        }
    }
};

class phonedisplay:public observer{
    public:
    void update(double temperature) override{
        cout<<"phonedisplay temp"<<temperature<<endl;
    }
};

class tvdisplay:public observer{
    public:
    void update(double temperature) override{
        cout<<"tvdisplay temp"<<temperature<<endl;
    }
};

int main() {
    weather wstation;
    phonedisplay ph;
    tvdisplay tv;
    wstation.addobserver(&ph);
    wstation.addobserver(&tv);
    
    wstation.updatetemp(22.5);
	
	return 0;

}


/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//subject interface -- add remove notify
//observer interface -- update and display weather 

class observer{
    public:
        virtual void update(double temperature) = 0;
};

class subject{
    public:
        virtual void addobserver( observer* obs) =0;
        virtual void removeobserver( observer* obs) =0;
        virtual void notifyobservers() =0;
};


//concrete subject  -- add observer, remove observers, notify observers

class weatherstation:public subject{
    private: 
        vector<observer*> observers;
        float temperature;
    public:

        void addobserver(observer* obs) override{
            observers.push_back(obs);
        }
        void removeobserver( observer* obs)override{
            observers.erase(remove(observers.begin(), observers.end(),obs), observers.end());
        }

        void settemperature(float temp){
            temperature = temp;
            notifyobservers();
        }
        void notifyobservers()override{
            for(auto & obs : observers){
                obs->update(temperature);
            }
        }
};

//concrete observer -- update and display tv display , phone display
class phonedisplay: public observer{
    public:
        void update(double temperature)override{
            cout<<"phone display temp: "<< temperature<<endl;
        }
};

class Tvdisplay: public observer{
    public:
        void update(double temperature)override{
            cout<<"TV display temp: "<< temperature<<endl;
        }
};

int main(){
    weatherstation station;

    phonedisplay phone;
    Tvdisplay tv;

    station.addobserver(&phone);
    station.addobserver(&tv);

    station.settemperature(25.5);
    station.settemperature(34.1);

    return 0;

}*/