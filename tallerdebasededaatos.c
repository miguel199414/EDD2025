#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int documento;
    char destino[30];
    char tipo_pasaje[20];// "ida" o "ida y regreso"
    Nodo* izq;
    Nodo* der;
};

//crear un nuevo nodo
Nodo* crearNodo(int documento, chaar destino[], char tipo_pasaje[]) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->documento = documento;
    strcpy(nuevo->destino, destino);
    strcpy(nuevo->tipo_pasaje, tipo_pasaje);
    nuevo->izq = nuevo->der = NULL;
    return nuevo;

}

// Insertar pasajero en ABB
Nodo* insertaABB(Nodo* raiz, int documento, char destino[], char tipo_pasaje[]) {
    if (raiz == NULL) {
        return crearNodo(documento, destino, tipo_pasaje);

    }
    if (documento < raiz->documento)
    raiz->izq = insertaABB(raiz->izq, documento, destino, tipo_pasaje);
    else if (documento > raiz->documento)

    raiz->der = insertaABB(raiz->der, documento, destino, tipo_pasaje);
    else
    cout << "El documento ya existe, no se puede regitrar nueva mente." <<endl;
    return raiz;
}

// Recorrido Inorden
void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        cout << "Dicumento: " << raiz-> documento
             << ", Destino: " << raiz-> destino
             << ", Tipo: " << raiz-> tipo_pasaje << endl;
        inorden(raiz->der);

    }
}

//Recorrrido preorden
void preorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << "Documento: " << raiz-> documento
             << ", Destino: " << raiz-> destino
             << ", Tipo: " << raiz-> tipo_pasaje << endl;
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

// Recorrido Posorden
void posorden(Nodo* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izq);
        posorden(raiz->der);
        cout << "Documento: " << raiz-> documento
             << ", Destino: " << raiz-> destino
             << ", Tipo: " << raiz-> tipo_pasaje << endl;

    }
}

// Buscar pasajero por el documento
void buscarPorDocumento(Nodo* raiz, int doc) {
    if (raiz == NULL) {
        cout << "Pasajero no encontrado. " << endl;
        return;
    }
    if (doc == raiz->documento) {
        cout << "\n Pasajero entontrado: \n";
        cout << "Documento: " << raiz-> documento
             << ", Destino: " << raiz-> destino
             << ", Tipo: " << raiz-> tipo_pasajero << endl;

    }
    else if (doc < raiz->documento)
    buscarPorDocumento(raiz->izq, doc);
    else
    buscarPorDocumento(raiz->der, doc);

}

// contar total de pasajeros
int contarPasajeros(Nodo* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarPasajeros(raiz->izq) + contarPasajeros(raiz->der);

}
// eliminar pasajeros por documento
Nodo* eliminarNodo(Noodo* raiz, int doc) {
    if (raiz == NULL) return raiz;
    
    // Buscar el nodo
    if (doc < raiz->documento)
       raiz->izq = eliminarNodo(raiz->izq, doc);
    else if (doc > raiz->documento)
       raiz->der = eliminarNodo(raiz->der, doc);
    else {
        //caso 1: No tiene hijos
        else if (raiz->izq == NULL || raiz->der == NULL) {
            free(raiz);
            return NULL;
        }
        // caso 2: Tienen solo un hijo
        else if (raiz->izq == NULL || raiz->der NULL){
            free(raiz);
            return temp;
        }
        // caso 3: Tienen dos hijos
        else {
            Nodo* sucesor = raiz->der;
            while (sucesor->izq != NULL)
            {
                sucesor = sucesor->izq,
            }
            raiz->documento = sucesor->documento;
            strcpy(raiz->destino, sucesor->destino);
            strcpy(raiz->tipo_pasajero, sucesor->tipo_pasajero);
            raiz->der = eliminarNodo(raiz->der, suecesor->documento);
        }
    }
    return raiz;
}
// Funcion principal
int main() {
    Nodo* arbol = NULL;
    int opcion, documento;
    char destino[30], tipo_pasaje[20];

    do {
        cout << "\n------ MENU PRINCIPAL -----\n";
        cout << "1. Registrar pasajero\n";
        cout << "2. Mostrar Inorden\n";
        cout << "3. Mostrar Preorden\n";
        cout << "4. Mostrar Posorden\n";
        cout << "5. Buscar pasajero por documento\n";
        cout << "6. Contar total de pasajeros\n";
        cout << "7. Eliminar pasajeros por el documento\n";
        cout << "8. salir\n";
        cin >>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "Documento: ";
            cin >> documento;
            cin.ignore();
            cout << "Destino (Tumaco, Guapi, Bahia, Timbiqui): ";
            cin.getline(destino, 30);
            cout << "Tipo de pasaje (Ida y  Regreso): ";
            cin.getline(tipo_pasaje, 20);
            arbol = insertaABB(arbol, documento, destino, tipo_pasaje);
            break;

        case 2: 
            cout << "\n Listado Inorden: \n";
            inorden(arbol);
            break;

        case 3:
            cout << "\n Listado Preorden: \n";
            preorden(arbol);
            break;

        case 4:
            cout << "\n Listado Posorden: \n";
            posorden(arbol);
            break;

        case 5:
            cout << "\n Documento a buscar: ";
            cin >> documento;
            buscarPorDocumento(arbol, documento);

        case 6:
            cout << "Total de pasajeros registrados: " << contarPasajeros(arbol) << endl;
            break;

        case 7:
            cout << "Documento del pasajero a eliminar: ";
            cin >> documento;
            arbol = eliminarNodo(arbol, documento);
            cout << "Pasajero eliminado (si existia). \n";
            break;
            
        case 8:
            cout << "Saliendo del sistema.....\n";
            break;

        
        default:
           cout <<"Opcion no valida. \n";
            break;
        }
    } while (opcion != 8);
    
    return 0;
}
