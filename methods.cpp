#include "Exampl3d.h"

 vector<double> Circle::GetFirstDerivative(const double& t) {
      double h = 3e-10;
      return { (cordX(t + h) - cordX(t)) / h,(cordY(t + h) - cordY(t)) / h,(cordZ(t + h) - cordZ(t)) / h };
}
vector<double> Circle::GetPoint(const double& t) {
  x = cordX(t);
  y = cordY(t);
  z = cordZ(t);
  return { x, y, z };
}
double Circle::GetRadius() {
  return Rad;
}
double Circle::cordX(const double& t) {
  return Rad * cos(t);
}
double Circle::cordY(const double& t) {
  return Rad * sin(t);
}
double Circle::cordZ(const double& t) {
  return .0 * t;
}

vector<double> Ellipse::GetFirstDerivative(const double &t) {
  double h = 3e-10;
  return {(cordX(t + h) - cordX(t)) / h, (cordY(t + h) - cordY(t)) / h,
            (cordZ(t + h) - cordZ(t)) / h};
}
vector<double> Ellipse::GetPoint(const double &t) {
  x = cordX(t);
  y = cordY(t);
  z = cordZ(t);
  return {x, y, z};
}
double Ellipse::cordX(const double &t) { return RadA * cos(t); }
double Ellipse::cordY(const double &t) { return RadB * sin(t); }
double Ellipse::cordZ(const double &t) { return .0 * t; }

vector<double> Helixe::GetFirstDerivative(const double &t) {
  double h = 3e-10;
  return {(cordX(t + h) - cordX(t)) / h, (cordY(t + h) - cordY(t)) / h,
            (cordZ(t + h) - cordZ(t)) / h};
}
vector<double> Helixe::GetPoint(const double &t) {
  x = cordX(t);
  y = cordY(t);
  z = cordZ(t);
  return {x, y, z};
}
double Helixe::cordX(const double &t) { return Rad * cos(t); }
double Helixe::cordY(const double &t) { return Rad * sin(t); }
double Helixe::cordZ(const double &t) { return t * Step; }

bool circlcomp(Circle *c1, Circle *c2) {
  return c1->GetRadius() < c2->GetRadius();
}

