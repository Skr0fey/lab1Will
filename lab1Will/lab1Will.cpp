#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "=== Approximation de Pi/2 avec le produit de Wallis ===" << endl;

    int num, den;
    cout << "Entrez le numerateur du terme (pair): ";
    cin >> num;
    cout << "Entrez le denominateur du terme: ";
    cin >> den;

    // approximation
    double approximation = 1.0;

    // premier terme
    int n = 2;
    int d = 1;
    bool trouve = false;

    while (true) {
        approximation *= static_cast<double>(n) / d;

        if (n == num && d == den) {
            trouve = true;
            break;
        }

        // avancer au terme suivant
        if (d == n - 1) {
            d = n + 1;       // второй вариант с тем же числителем
        }
        else {
            n += 2;          // следующий числитель
            d = n - 1;       // начинаем с (n-1)
        }

        // protection : si le nombre saisi est dépassé, il n'y a pas d'échappatoire
        if (n > num) break;
    }

    if (trouve) {
        cout << "Approximation de Pi/2 = " << approximation << endl;
    }
    else {
        cout << "Erreur: le terme saisi n'appartient pas a la suite de Wallis." << endl;
    }

    //si j'ai fais comme ca?
    cout << "Programme termine." << endl;
    
    return EXIT_SUCCESS;
}
