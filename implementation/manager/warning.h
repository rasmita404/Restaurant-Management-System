#ifndef WARNING
#define WARNING

#include <iostream>
#include <QString>

class Warning {
    QString cnic;

    int count;
public:
    Warning() {;}
    void set(QString c, int cnt) {
        cnic=c;
        count=cnt;
    }

    QString getcnic() {return cnic; }
    int getcount() {return count;}
};

#endif

