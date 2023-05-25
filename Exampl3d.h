#ifndef Exampl3d_H
#define Exampl3d_H
#define M_PI 3.141592653589
#include <algorithm>
#include <any>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Point3d {
public:
  double x;
  double y;
  double z;
  virtual void GetPoint() {}
  virtual void GetFirstDerivative() {}
};
class Circle : public Point3d {
public:
  Circle(double radius) : Rad(radius) {}

  virtual vector<double> GetFirstDerivative(const double &t);
  virtual vector<double> GetPoint(const double &t);
  virtual double GetRadius();

private:
  virtual double cordX(const double &t);
  virtual double cordY(const double &t);
  virtual double cordZ(const double &t);

  double Rad;
};
class Ellipse : public Point3d {
public:
  Ellipse(double radius_A, double radius_B) : RadA(radius_A), RadB(radius_B) {}
  virtual vector<double> GetFirstDerivative(const double &t);
  virtual vector<double> GetPoint(const double &t);

private:
  virtual double cordX(const double &t);
  virtual double cordY(const double &t);
  virtual double cordZ(const double &t);

  double RadA;
  double RadB;
};
class Helixe : public Point3d {
public:
  Helixe(double radius, double step) : Rad(radius), Step(step) {}

  virtual vector<double> GetFirstDerivative(const double &t);
  virtual vector<double> GetPoint(const double &t);
private:
  virtual double cordX(const double &t);
  virtual double cordY(const double &t);
  virtual double cordZ(const double &t);
  double Step;
  double Rad;
};
bool circlcomp(Circle *c1, Circle *c2);
#endif // Exampl3d_H