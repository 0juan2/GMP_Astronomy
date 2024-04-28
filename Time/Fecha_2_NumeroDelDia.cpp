#include <gmpxx.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {

	if (argc < 4) {
		cout << "Uso: " << argv[0] << " <Dia> <Mes> <Anio>" << endl;
		return 1;
	}


	mpz_class a, bi, dia, mes, anio;
	mpf_class b;
	b = "306";
	unsigned long int d = 306;
	dia = argv[1];
	mes = argv[2];
	anio = argv[3];
	bi=0;
	mpz_mod_ui(a.get_mpz_t(), anio.get_mpz_t(), 4);
	if(a==0){
		mpz_mod_ui(a.get_mpz_t(), anio.get_mpz_t(), 100);
		if(a!=0){
			bi=1;
			cout<< "Anio Bisiesto" <<endl;
		}
	}
	mpz_mod_ui(a.get_mpz_t(), anio.get_mpz_t(), 400);
	if(a==0){
		bi=1;
		cout<< "Anio Bisiesto" <<endl;
	}
	cout << "Fecha: " << dia << "/" << mes << "/" << anio <<endl;
	if(dia>28&&!bi&&mes==2){
		cout<< "Dia no puede ser mayor que 28 en anio no bisiesto"<<endl;
		return 1;
	}else if(dia>31){
		cout<< "Dia no puede ser mayor que 31"<<endl;
		return 1;
	}
	if(mes>12){
		cout<< "Mes no puede ser mayor que 12"<<endl;
		return 1;
	}
	if(mes<=2){
		a=mes-1;
		a*=(63-bi);
		a/=2;
		a+=dia;
		cout << "N-dias:	" << a <<endl;
	}else{
		mpf_class c = (mes+1);
		c*=b;
		c/=10;
		mpz_set_f(a.get_mpz_t(), c.get_mpf_t());
		a -= (63-bi);
		a += dia;
		cout << "N-dias: " << a << endl;
	}



    return 0;
}

