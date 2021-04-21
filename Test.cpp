/**
 * AUTHORS: <Amit Tzumi>
 * 
 * Date: 2021-04
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

NumberWithUnits a(5,"km");
NumberWithUnits b(3,"km");
NumberWithUnits c(8,"km");
NumberWithUnits d(400,"m");
NumberWithUnits e(20000,"cm");
NumberWithUnits f(1,"hour");
NumberWithUnits plusbinary(8,"km");
NumberWithUnits minusunary(-3,"km");
NumberWithUnits minusequal(-14,"km");
NumberWithUnits minusbinary(-25,"km");
NumberWithUnits plusunary(3,"km");
NumberWithUnits plusone(12,"km");
NumberWithUnits minusone(11,"km");
NumberWithUnits plusbinarysamecat1(8.4,"km");
NumberWithUnits plusbinarysamecat2(8400,"m");
NumberWithUnits plusbinarysamecat3(820000,"cm");
NumberWithUnits plusbinarysamecat4(8.2,"km");
NumberWithUnits plusbinarysamecat5(600,"m");


TEST_CASE("Checking text file"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
}

TEST_CASE("Checking operators with the same unit"){
    CHECK(a+b == plusbinary);
    CHECK((a+=b) == c);
    CHECK((+a) == c);
    CHECK((-b) == minusunary);
    CHECK((b-=a) == minusequal);
    CHECK((b-a) == minusbinary);
    CHECK(a>b);
    CHECK(a>=b);
    CHECK(b<a);
    CHECK(b<=a);
    CHECK(a!=b);
    CHECK((b+=a) == minusunary);
    CHECK(+b == plusunary);
    CHECK(b+c == a);
    CHECK(++a == plusone);
    CHECK(--a == minusone);
}

TEST_CASE("Checking operators with different units but in the same category"){
    CHECK((c+d) == plusbinarysamecat1);
    CHECK((d+c) == plusbinarysamecat2);
    CHECK((e+c) == plusbinarysamecat3);
    CHECK((c+e) == plusbinarysamecat4);
    CHECK((d+e) == plusbinarysamecat5);
}

TEST_CASE("Checking input and output operators"){
    istringstream sample_input{"3 [ton]"};
    sample_input >> a;
    cout << a << endl;   // Prints "3[ton]"
    cout << (a += NumberWithUnits{700, "kg"}) << endl;  // prints "3.7[ton]"
    cout << a << endl;   // Prints "1700[kg]". Note that a has changed.
}

TEST_CASE("Checking operators with different units without connection"){
    CHECK_THROWS(c+f);
    CHECK_THROWS(d+f);
    CHECK_THROWS(e+f);
}

