//Complex.h
#pragma once
#include<string>
class Complex{
private:
int real, imaginary;
public:
Complex(int real=0,int imaginary=0);
int re();
int im();
void operator >> (std::string&) const;
void operator << (const std::string&);
};
//Complex.cpp
#include <complex.h>
Complex::Complex(int real, int imaginary){
this->real = real;
this->imaginary = imaginary;}
int Complex::re(){
return this->real;}
int Complex::im(){
return this->imaginary;}
void Complex::operator>>(std::string& s) const{
s.append(std::to_string(this->real));
if (this->imaginary > 0){
s.append("+");}
s.append(std::to_string(this->imaginary));
s.append("i");}
void Complex::operator<<(const std::string& s){
if (s[0] == '-'){

int re = s[1] - '0';

this->real = -1 * re;}

else
{
this->real = s[0] - '0'; //converting char to int;

}

int ipos = s.find("i");
int bpos = ipos - 1;
int bsignpos = ipos - 2;
if (s[bsignpos] == '-')
{
this->imaginary = -1 * (s[bpos] - '0');

}
else

{
this->imaginary = s[bpos] - '0';

}

}

//Main.cpp
#include <iostream>

#include <complex.h>

int main(){
Complex c;
std::cout << c.re() << c.re() << std::endl;
std::string s = "-1-1i";
c << s;
std::cout << c.re() << c.re()<<std::endl;
std::string s2 = "";
c >> s2;
std::cout << s2 << std::endl;
}