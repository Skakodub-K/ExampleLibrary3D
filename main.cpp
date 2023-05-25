#include"Exampl3d.h"

int main() {
   srand(time(NULL));
   vector<any> container;
   int n = 5 + rand() % 15;
   double t = 1.0 * M_PI / 4;
   for(int i = 0; i < n; i++) {

      double probability = 1.0*rand() / RAND_MAX;
      if(probability < 0.33) {
         Circle c(1 + rand() % 10);
         container.push_back(c);
      }
      else if((probability >= 0.33) && (probability < 0.66)) {
         Ellipse el((1 + rand() % 10), (1 + rand() % 10));
         container.push_back(el);
      }
      else {
         Helixe hel((1 + rand() % 10), (1 + 1.0*rand() / RAND_MAX));
         container.push_back(hel);
      }
   }
   vector<Circle*> circls;
   for(int i = 0; i < n; i++) {

      if(container[i].type() == typeid(Circle)) {
         circls.push_back(any_cast<Circle>(&container[i]));
         cout << "Point: ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Circle>(container[i]).GetPoint(t)[j] << "  ";
         cout << "Derivative:    ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Circle>(container[i]).GetFirstDerivative(t)[j] << " ";
      }
      else if(container[i].type() == typeid(Ellipse)) {
         cout << "Point: ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Ellipse>(container[i]).GetPoint(t)[j] << " ";
         cout << "Derivative:    ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Ellipse>(container[i]).GetFirstDerivative(t)[j] << "   ";
      }
      else if(container[i].type() == typeid(Helixe)) {
         cout << "Point: ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Helixe>(container[i]).GetPoint(t)[j] << "  ";
         cout << "Derivative:    ";
         for(int j = 0; j < 3; j++)
            cout << any_cast<Helixe>(container[i]).GetFirstDerivative(t)[j] << " ";
      }
      cout << endl;
   }
   double max_rad = 0;
   sort(circls.begin(), circls.end(), circlcomp);
   double sum = .0;
#pragma omp parallel shared(circls) reduction(+: sum) num_threads(2)
#pragma omp for
   for(int i = 0; i < circls.size(); i++)
      sum += circls[i]->GetRadius();
   cout << "Sum radius in second container: " << sum << endl;
}