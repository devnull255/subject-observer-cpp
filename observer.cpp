#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

class Subject;

class Observer {
public:
    virtual void notify(Subject *s) = 0;
    virtual ~Observer() {};
};

class Subject {
    std::vector<Observer*> observers;
protected:
    void notify_observers() {
        std::vector<Observer*>::iterator iter;
        for (iter = observers.begin(); iter != observers.end(); ++iter)
           (*iter)->notify(this);
    }

public:
    virtual ~Subject() {};
    void register_observer(Observer *o) {
       observers.push_back(o);
    }
};

class Alarm : public Subject {
public:
    Alarm() {
       std::cout << "alarm created" << "\n";
    }

    void triggered() {
       std::cout << "The alarm has been triggered" << "\n";
       notify_observers();
    }

    int const get_alarm_id() { return 100; }
};
 
class Horn : public Observer {
public:
    virtual void notify(Subject* s) {
        Alarm *a;
        a = dynamic_cast<Alarm*>(s);
        std::cout << a->get_alarm_id() << "\n";
    }
};


int main() {
    Alarm a = Alarm();
    Horn h  = Horn();
    Horn h2 = Horn();
    Horn h3 = Horn();

    a.register_observer(&h);
    a.register_observer(&h2);
    a.register_observer(&h2);
    a.triggered();
    return 0;
}

