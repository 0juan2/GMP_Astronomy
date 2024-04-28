#include <gmpxx.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {


	if (argc != 2) {
		cout << "Uso: " << argv[0] << " <Anio_ValorEntero>" << endl;
		return 1;
	}

	mpz_class ano;
	ano = argv[1];

	if(ano<1583){
		cout << "Las Fechas estan segun calendario gregoriano, coloque fechas posteriores a 1582" <<endl;
		return 1;
	}

	mpz_t v1;
	mpz_init_set_si(v1, 100);
	mpz_t v2;
	mpz_init_set_si(v2, 4);
	mpz_t v3;
	mpz_init_set_si(v3, 25);
	mpz_t v4;
	mpz_init_set_si(v4, 3);
	mpz_t v5;
	mpz_init_set_si(v5, 30);
	mpz_t v6;
	mpz_init_set_si(v6, 7);
	mpz_t v7;
	mpz_init_set_si(v7, 451);
	mpz_t v8;
	mpz_init_set_si(v8, 31);

	mpz_class a;
	mpz_class b;
	mpz_class c;
	mpz_class d;
	mpz_class e;
	mpz_class f;
	mpz_class g;
	mpz_class h;
	mpz_class i;
	mpz_class k;
	mpz_class l;
	mpz_class l1;
	mpz_class m;
	mpz_class m1;
	mpz_class n;
	mpz_class n1;
	mpz_class p;

	

	cout << "Ano:	" << ano <<endl;
	mpz_mod_ui(a.get_mpz_t(), ano.get_mpz_t(), 19);		//ano%19
	cout << "a:	" << a <<endl;
	mpz_div(b.get_mpz_t(), ano.get_mpz_t(), v1);		//ano/100
	cout << "b:	" << b <<endl;
	mpz_mod(c.get_mpz_t(), ano.get_mpz_t(), v1);		//ano%100
	cout << "c:	" << c <<endl;
	mpz_div(d.get_mpz_t(), b.get_mpz_t(), v2);		//b/4
	cout << "d:	" << d <<endl;
	mpz_mod(e.get_mpz_t(), b.get_mpz_t(), v2);		//b%4
	cout << "e:	" << e <<endl;
	mpz_add_ui(f.get_mpz_t(), b.get_mpz_t(), 8);		//(b)+8
	mpz_div(f.get_mpz_t(), f.get_mpz_t(), v3);		//(b+8)/25
	cout << "f:	" << f <<endl;
	mpz_add_ui(g.get_mpz_t(), b.get_mpz_t(), 1);		//(b)+1
	mpz_sub(g.get_mpz_t(), g.get_mpz_t(), f.get_mpz_t());	//(b+1)-f
	mpz_div(g.get_mpz_t(), g.get_mpz_t(), v4);		//b+1-f)/3
	cout << "g:	" << g <<endl;
	mpz_mul_ui(h.get_mpz_t(), a.get_mpz_t(), 19);		//(a)*19
	mpz_add(h.get_mpz_t(), h.get_mpz_t(), b.get_mpz_t());	//(19a)+b
	mpz_sub(h.get_mpz_t(), h.get_mpz_t(), d.get_mpz_t());	//(19a+b)-d
	mpz_sub(h.get_mpz_t(), h.get_mpz_t(), g.get_mpz_t());	//(19a+b-d)-g
	mpz_add_ui(h.get_mpz_t(), h.get_mpz_t(), 15);		//(19a+b-d-g)+15
	mpz_mod(h.get_mpz_t(), h.get_mpz_t(), v5);		//(19a+b-d-g+15)%30
	cout << "h:	" << h <<endl;
	mpz_div(i.get_mpz_t(), c.get_mpz_t(), v2);		//c/4
	cout << "i:	" << i <<endl;
	mpz_mod(k.get_mpz_t(), c.get_mpz_t(), v2);		//c%4
	cout << "k:	" << k <<endl;
	mpz_mul_ui(l.get_mpz_t(), e.get_mpz_t(), 2); 		//(e)*2
	mpz_add_ui(l.get_mpz_t(), l.get_mpz_t(), 32);		//(2e)+32
	mpz_mul_ui(l1.get_mpz_t(), i.get_mpz_t(), 2);		//2i
	mpz_add(l.get_mpz_t(), l1.get_mpz_t(), l.get_mpz_t());	//(32+2e)+2i
	mpz_sub(l.get_mpz_t(), l.get_mpz_t(), h.get_mpz_t());	//(32+2e+2i)-h
	mpz_sub(l.get_mpz_t(), l.get_mpz_t(), k.get_mpz_t());	//32+2e+2i-h-k
	mpz_mod(l.get_mpz_t(), l.get_mpz_t(), v6);		//32+2e+2i-h-k)/7
	cout << "l:	" << l <<endl;
	mpz_mul_ui(m.get_mpz_t(), e.get_mpz_t(), 11);		//(h)*11
	mpz_add(m.get_mpz_t(), m.get_mpz_t(), a.get_mpz_t());	//(11h)+a
	mpz_mul_ui(m1.get_mpz_t(), l.get_mpz_t(), 22);		//(l)*22
	mpz_add(m.get_mpz_t(), m.get_mpz_t(), m1.get_mpz_t());	//11h+a+22l
	mpz_div(m.get_mpz_t(), m.get_mpz_t(), v7);		//11h+a+22l)/451
	cout << "m:	" << m <<endl;
	mpz_add(n.get_mpz_t(), h.get_mpz_t(), l.get_mpz_t());	//(h)+l
	mpz_mul_ui(n1.get_mpz_t(), m.get_mpz_t(), 7);		//(m)*7
	mpz_sub(n.get_mpz_t(), n.get_mpz_t(), n1.get_mpz_t());	//(h+l)-7m
	mpz_add_ui(n.get_mpz_t(), n.get_mpz_t(), 114);		//(h+l-7m)+114
	mpz_mod(p.get_mpz_t(), n.get_mpz_t(), v8);		//(h+l-7m+114)%31
	mpz_div(n.get_mpz_t(), n.get_mpz_t(), v8);		//(h+l-7m+114)/31
	cout << "n:	" << n <<endl;
	cout << "p:	" << p <<endl<<endl;
	mpz_add_ui(p.get_mpz_t(), p.get_mpz_t(), 1);		//p+1
	cout << "Dia De Pascua: "<< p<<"/"<<n<<"/"<<ano<<endl;
	return 0;
}

