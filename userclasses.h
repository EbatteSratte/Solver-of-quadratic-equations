#ifndef USERCLASSES_H
#define USERCLASSES_H

#include "QObject"
#include "math.h"

// ----------------------------------------

class quadE {
protected: double A, B, C;
};

// ----------------------------------------

class Type1 : public quadE {
public: Type1(double A, double B, double C) {
  this->A = A;
  this->B = B;
  this->C = C;
}
public:
    QString vsegVerno() { return  "Уравнение верно при любом х"; }
};

// ----------------------------------------

class Type2 : public quadE
{
public:
  Type2(double A, double B, double C) {
  this->A = A;
  this->B = B;
  this->C = C;
}

public:
  double ret0() { return 0; }
};

// ----------------------------------------

class Type3 : public quadE
{
public:
  Type3(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }

public:
  QString retErr() { return "Уравнение не имеет корней и является неверным"; }
};


class Type4 : public quadE
{
public:
  Type4(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }

public: bool Check()   { return -C/A >= 0;     }
public: double getX1() { return sqrt(-C / A);  }
public: double getX2() { return -sqrt(-C / A); }
};

// ----------------------------------------

class Type5 : public quadE
{
public:
  Type5(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }
public:
  double GetX() { return - C / B; }
};

// ----------------------------------------

class Type6 : public quadE
{
public:
  Type6(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }

public:
  double calcDisc() { return pow(B, 2) - 4 * A * C; }
public:
  QString getX1()
  {
    return
      QString::number((-B + sqrt(calcDisc())) / (2 * A));
  }

public:
  QString getX2()
  {
  return
     QString::number((-B - sqrt(calcDisc())) / (2 * A));
  }
};

// ----------------------------------------

class Type7 : public quadE
{
public:
  Type7(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }
public:
  double ret0() { return 0; }
};

// ----------------------------------------

class Type8 : public quadE
{
public:
  Type8(double A, double B, double C)
  {
    this->A = A;
    this->B = B;
    this->C = C;
  }

public: double getX1() { return 0; }
public: double getX2() { return -B / A; }
};

// ----------------------------------------

#endif // USERCLASSES_H
