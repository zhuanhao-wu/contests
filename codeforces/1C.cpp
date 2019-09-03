#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double x[3], y[3];
double A[2], B[2], C[2];

double sq(double x) {
  return  x * x;
}

int main() {
  for(int i = 0; i < 3; i++) {
    cin>>x[i]>>y[i];
  }
  for(int i = 0; i < 2; i++) {
    // A[i] * x[i]     + B[i] * y[i]     + C[i] = 0
    // A[i] * x[i + 1] + B[i] * y[i + 1] + C[i] = 0
    double det = x[i] * y[i + 1] - x[i + 1] * y[i];
    double detx = (-1) * y[i + 1] - (-1) * y[i];
    double dety = x[i] * (-1) - (-1) * x[i + 1];
    if(det == 0) {
      if(y[i] != 0) {
        A[i] = 1;
        B[i] = -x[i] / y[i];
      } else {
        A[i] = 1;
        B[i] = -x[i + 1] / y[i + 1];
      }
      C[i] = 0;
    } else {
      A[i] = detx / det;
      B[i] = dety / det;
      C[i] = 1;
    }
    double mx = (x[i] + x[i + 1]) / 2;
    double my = (y[i] + y[i + 1]) / 2;
    swap(A[i], B[i]);
    A[i] = - A[i];
    C[i] = - A[i] * mx  - B[i] * my;
  }
  // A[0] * x + B[0] * y + C[0] = 0
  // A[1] * x + B[1] * y + C[1] = 0
  // det would not be zero as that requires 4 points
  double det  = A[0] * B[1] - B[0] * A[1];
  double detx = - C[0] * B[1] + B[0] * C[1];
  double dety = - A[0] * C[1] + C[0] * A[1];
  double cx = detx / det;
  double cy = dety / det;
  double r2 = sq(cx - x[0]) + sq(cy - y[0]);
  double d2 = sq(x[0] - x[1]) + sq(y[0] - y[1]);
  double w2 = sq(x[2] - x[1]) + sq(y[2] - y[1]);
  double a1 = acos(1 - d2 / (2.0f * r2));
  double a2 = acos(1 - w2 / (2.0f * r2));
  double diff = 1e9;
  int q;
  for(q = 3; q <= 100; q++) {
    double quantum = 2 * acos(-1) / q;
    double s1 = a1 / quantum;
    double s2 = a2 / quantum;
    double diff = abs(s1 - round(s1)) + abs(s2 - round(s2));
    // cout<<"Diff: "<<diff<<" Area: ";
    double S = q * sin(quantum) * r2 / 2.0;
    // cout<<fixed<<setprecision(10) << S<<endl;
    if(diff < 5e-5) {
      break;
    }
  }
  cerr<<q<<endl;
  double quantum = 2 * acos(-1) / q;
  double S = q * sin(quantum) * r2 / 2.0;
  cout<<fixed<<setprecision(10) << S<<endl;
  return 0;
}
