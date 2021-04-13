
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class NumberWithUnits{

    private:
        double number;
        string type;

    public:
        NumberWithUnits(double sum, string unit){
            this->number = sum;
            this->type = unit;
        }
        ~NumberWithUnits(){}
        static void read_units(ifstream& units_file);
        friend int compare(const NumberWithUnits& x, const NumberWithUnits& y);

        // in & out
        friend ostream& operator<<(ostream& out, const NumberWithUnits& num);
        friend istream& operator>>(istream& in, NumberWithUnits& num);
        //artm
        friend NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y);
        friend NumberWithUnits operator+(const NumberWithUnits& num, double x);
        friend NumberWithUnits operator+=(NumberWithUnits& x, const NumberWithUnits& y);
        friend NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y);
        friend NumberWithUnits operator-(const NumberWithUnits& num);
        friend NumberWithUnits operator-=(NumberWithUnits& x, const NumberWithUnits& y);

        // ++ & --
        friend NumberWithUnits operator++(NumberWithUnits& num);
        friend NumberWithUnits operator++(NumberWithUnits& num, int);
        friend NumberWithUnits operator--(NumberWithUnits& num);
        friend NumberWithUnits operator--(NumberWithUnits& num, int);

        // *
        friend NumberWithUnits operator*(NumberWithUnits& num, double x);
        friend NumberWithUnits operator*(double x, NumberWithUnits& num);
        friend NumberWithUnits operator*=(NumberWithUnits& num, double x);
        friend NumberWithUnits operator*=(double x, NumberWithUnits& num);

        // bool
        friend bool operator>(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator<(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator==(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y);
    };
}