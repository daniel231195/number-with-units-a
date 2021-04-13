#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel {

    void NumberWithUnits::read_units(ifstream& units_file){
    }


    ostream& operator<<(ostream& out, const NumberWithUnits& num){
        out << "the number is : " << num.number << " ,the type is : " << num.type << "]";
        return out;
    }
    istream& operator>>(istream& in, NumberWithUnits& num){
        in >> num.number  >> num.type;
        return in;
    }


    NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y) { 
        return NumberWithUnits(x.number, x.type);
    }
    NumberWithUnits operator+(const NumberWithUnits& num, double x) {
        return NumberWithUnits(num.number+x, num.type);
    }
    NumberWithUnits operator+=(NumberWithUnits& x, const NumberWithUnits& y) {
        return x;
    }
    NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y) {
        return NumberWithUnits(x.number, x.type);
    }
    NumberWithUnits operator-(const NumberWithUnits& num) {
        return NumberWithUnits(-num.number, num.type);
    }
    NumberWithUnits operator-=(NumberWithUnits& x, const NumberWithUnits& y) {
       return NumberWithUnits(x.number, y.type);
    }


    NumberWithUnits operator++(NumberWithUnits& num) {
        return NumberWithUnits(++num.number, num.type);
    }
    NumberWithUnits operator++(NumberWithUnits& num, int) {
        return NumberWithUnits(num.number++, num.type);
    }
    NumberWithUnits operator--(NumberWithUnits& num) {
        return NumberWithUnits(--num.number, num.type);
    }
    NumberWithUnits operator--(NumberWithUnits& num, int) {
        return NumberWithUnits(num.number--, num.type);
    }


    NumberWithUnits operator*(NumberWithUnits& num, double x) {
        return NumberWithUnits(num.number*x, num.type);
    }
    NumberWithUnits operator*(double x, NumberWithUnits& num) {
        return NumberWithUnits(num.number*x, num.type);
    }
    NumberWithUnits operator*=(NumberWithUnits& num, double x) {
        return NumberWithUnits(num.number*=x, num.type);
    }
    NumberWithUnits operator*=(double x, NumberWithUnits& num) {
        return NumberWithUnits(x*=num.number, num.type);
    }

    bool operator>(const NumberWithUnits& x, const NumberWithUnits& y){
       return true;
    }
    bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y){
        return true;
    }
    bool operator<(const NumberWithUnits& x, const NumberWithUnits& y){
        return true;
    }
    bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y){
        return true;
    }
    bool operator==(const NumberWithUnits& x, const NumberWithUnits& y){
        return true;
    }
    bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y){
        return true;
    }
}