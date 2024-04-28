#include <gmpxx.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Uso: " << argv[0] << " <valor_flotante>" << endl;
		return 1;
	}


	mpf_class valor;
	valor = argv[1];
	cout << "Argumento 1:	" << valor <<endl;


    return 0;
}

