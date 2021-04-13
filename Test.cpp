#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace ariel;
using namespace std;
ifstream units_file{"units.txt"};

TEST_CASE("++ & -- operators"){ // 17
    NumberWithUnits::read_units(units_file);
    NumberWithUnits num{2, "km"};
    //whole
    CHECK(num++ == NumberWithUnits{2, "km"});
    CHECK(num == NumberWithUnits{3, "km"});
    CHECK(++num == NumberWithUnits{4, "km"});
    CHECK(num == NumberWithUnits{4, "km"});
    CHECK(num-- == NumberWithUnits{4, "km"});
    CHECK(num == NumberWithUnits{3, "km"});
    CHECK(--num == NumberWithUnits{2, "km"});
    CHECK(num == NumberWithUnits{2, "km"});

    //infi
    NumberWithUnits w{-0.25, "km"};
    CHECK(w++ == NumberWithUnits{0.75, "km"});
    CHECK(w == NumberWithUnits{0.75, "km"});
    CHECK(++w == NumberWithUnits{1.75, "km"});
    CHECK(w == NumberWithUnits{1.75, "km"});
    CHECK(w-- == NumberWithUnits{0.75, "km"});
    CHECK(w == NumberWithUnits{0.75, "km"});
    CHECK(--w == NumberWithUnits{-0.25, "km"});
    CHECK(w == NumberWithUnits{-0.25, "km"});
}


TEST_CASE("+ & - & -= & += operators"){ //14 -> 31
    NumberWithUnits::read_units(units_file);
    NumberWithUnits x{2, "km"};
    NumberWithUnits y{2, "km"};
    //whole
    CHECK(x+y == NumberWithUnits{4, "km"});
    CHECK(x-y == NumberWithUnits{0, "km"});
    CHECK(x == NumberWithUnits{2, "km"});
    CHECK((x+=y) == NumberWithUnits{4, "km"});
    CHECK(x == NumberWithUnits{4, "km"});
    CHECK((x-=y) == NumberWithUnits{2, "km"});
    CHECK(x == NumberWithUnits{4, "km"});

    //infi
    NumberWithUnits w{0.25, "km"};
    NumberWithUnits z{0.75, "km"};
    CHECK(w+z == NumberWithUnits{1, "km"});
    CHECK(w-z == NumberWithUnits{-0.5, "km"});
    CHECK((w+=z) == NumberWithUnits{1, "km"});
    CHECK(x == NumberWithUnits{1, "km"});
    CHECK((w-=z) == NumberWithUnits{0.25, "km"});
    CHECK(w == NumberWithUnits{0.25, "km"});
}

TEST_CASE("< & > & <= & >= operators"){ // 14 -> 45
    NumberWithUnits::read_units(units_file);
    NumberWithUnits x{1, "km"};
    NumberWithUnits y{2, "km"};
    NumberWithUnits w{1, "km"};
    NumberWithUnits z{2, "km"};
    CHECK((x>y) == false);
    CHECK((y>x) == true);
    CHECK((x<y) == true);
    CHECK((y<x) == false);
    CHECK((x>=y) == false);
    CHECK((y>=x) == true);
    CHECK((w>=x) == true);
    CHECK((y<=x) == false);
    CHECK((x<=y) == true);
    CHECK((z<=y) == true);
    CHECK((x==y) == false);
    CHECK((x==w) == true);
    CHECK((x!=y) == true);
    CHECK((x!=w) == false);
}

TEST_CASE("* & *=  operators"){ // 17 -> 62
    NumberWithUnits::read_units(units_file);
    NumberWithUnits x{2, "km"};
    NumberWithUnits y{2, "km"};
    CHECK((x*2) == NumberWithUnits{4, "km"});
    CHECK((x*0.5) == NumberWithUnits{1, "km"});
    CHECK((x*-2) == NumberWithUnits{-4, "km"});
    CHECK((x*0) == NumberWithUnits{0, "km"}); 

    CHECK((2*x) == NumberWithUnits{4, "km"});
    CHECK((0.5*x) == NumberWithUnits{1, "km"});
    CHECK((-2*x) == NumberWithUnits{-4, "km"});
    CHECK((0*x) == NumberWithUnits{0, "km"}); 

    CHECK((x*=2) == NumberWithUnits{4, "km"});
    CHECK(x == NumberWithUnits{4, "km"});
    CHECK((x*=0.5) == NumberWithUnits{2, "km"});
    CHECK(x == NumberWithUnits{2, "km"});
    CHECK((x*=-2) == NumberWithUnits{-4, "km"});
    CHECK(x == NumberWithUnits{-4, "km"});
    CHECK((x*0) == NumberWithUnits{0, "km"}); 
    CHECK(x == NumberWithUnits{0, "km"});

}

TEST_CASE("add a+b , different type"){ // 8 -> 70
    NumberWithUnits::read_units(units_file);
    // dist
    NumberWithUnits a{1, "km"};
    NumberWithUnits b{100, "m"};
    NumberWithUnits c{10, "cm"};
    CHECK((a+b) == NumberWithUnits{1.1, "km"});
    CHECK((b+a) == NumberWithUnits{100.1, "m"});

    // kilo
    NumberWithUnits d{100, "kg"};
    NumberWithUnits e{100, "g"};
    NumberWithUnits f{1, "ton"};
    CHECK((d+f) == NumberWithUnits{1.1, "ton"});
    CHECK((d+e) == NumberWithUnits{100.1, "kg"});

    // hour
    NumberWithUnits g{1, "min"};
    NumberWithUnits h{30, "sec"};
    NumberWithUnits k{1, "hour"};
    CHECK((g+h) == NumberWithUnits{90, "sec"});
    CHECK((k+g) == NumberWithUnits{61, "min"});

    //$$
    NumberWithUnits w{3.33, "ILS"};
    NumberWithUnits z{1, "USD"};
    CHECK((w+z) == NumberWithUnits{6.66, "ILS"});
    CHECK((z+w) == NumberWithUnits{2, "USD"});
    
}

TEST_CASE("add a+b , different type , trhows"){ // 7 -> 77
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{2, "kg"};
    NumberWithUnits c{2, "min"};
    NumberWithUnits d{4, "ILS"};
    CHECK_THROWS(a+c); 
    CHECK_THROWS(a+b);
    CHECK_THROWS(a+c);
    CHECK_THROWS(b+c);
    CHECK_THROWS(b+d);
    CHECK_THROWS(c+d);
    CHECK_THROWS(d+c);
}