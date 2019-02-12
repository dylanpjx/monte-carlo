#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/*
* Monte Carlo calculation of pi via dart throws on a circle in a square,
* with r = l/2, where r is radius of circle, and l is length of side of square.
* r = 1 for this use case.
*/

double calculate_pi(const int throws) {
  // seed for rand()
  srand(time(0));
  int onTarget = 0;
  for(int i = 0; i <= throws; ++i) {
    // creating doubles using type cast
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;
    double dist = sqrt(x*x + y*y);
    if (dist < 1) {
      ++onTarget;
    }
  }
  double pi = 4 * (onTarget/static_cast<double>(throws));
  cout << pi;
  return pi;
}

int main() {
  calculate_pi(5000000);
}
