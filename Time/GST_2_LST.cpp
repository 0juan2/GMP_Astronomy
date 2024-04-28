#include <iostream>
#include <gmpxx.h>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, const mpf_class& valorFlotante) {
    char* str = mpf_get_str(nullptr, nullptr, 10, 0, valorFlotante.get_mpf_t());
    os << str;
    free(str);
    return os;
}

// Función para procesar el valor flotante
void procesarFlotante(const char* str) {
    // Crear un objeto mpf_class para almacenar el valor flotante
    

    // Convertir la cadena a un valor flotante
    //if (!valorFlotante.set_str(str, 0)) { // El segundo parámetro 0 permite un formato flexible
        //cout << "Alerta: El valor proporcionado no es un número flotante válido." << endl;
      //  cout << "Por favor, ingrese un número flotante en el formato correcto." << endl;
        //return;
    //}
    mp_bitcnt_t precision = 64;
    mpf_class valorFlotante(str, precision);
    // Imprimir el valor flotante
    cout << "El valor flotante ingresado es: " << valorFlotante << endl;
}

int main(int argc, char* argv[]) {
    // Verificar si se proporcionó un argumento de línea de comandos
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <valor_flotante>" << endl;
        return 1;
    }

    // Obtener el valor flotante de los argumentos de la línea de comandos
    const char* valorFlotante = argv[1];
	mpf_class valor(valorFlotante);
	cout << "valor flotante: " << valor <<endl;
    // Procesar el valor flotante
    //procesarFlotante(valorFlotante);

    return 0;
}
