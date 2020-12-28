#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/range/algorithm/count.hpp>

using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participantes();
/**
 * Función para transformar los datos string a int
 */
/*void transformar(vector<string> vectors, vector<int> vectori);*/

int main()
{
    /**
     * 
     * linea se usará para quitar los titulos del primer archivo
     * linea2 se usará para quitar los titulos del segundo archivo
     * barcode guardará el codigo de barras del primer archivo
     * name guardará el nombre comercial de cada producto
     * volume guardará el volumen del envase de cada producto
     * barcode2 guardará el codigo de barras del segundo archivo
     * quantity guardará la cantidad de cada reciclaje
     * created guardara la fecha que se hizo el reciclaje
     * 
     */ 
    string linea,linea2,anno, mes, dia,amount,year,value,separado, separado2;
    /**
     * 
     * vectorbarcode es un vector donde se guardarán los codigos de barra del primer archivo
     * vectorname es un vector donde se guardarán los nombres de los productos
     * vectorvolume es un vector donde se guardarán los volumenes de los productos
     * vectorbarcode2 es un vector donde se guardarán los codigos de barra del segundo archivo
     * vectorquantity es un vector donde se guardarán las cantidades del reciclaje
     * vectorcreated es un vector donde se guardaran las fechas de reciclaje
     * 
     */
    vector<string> vectoramount,vectoryear,vectorvalue,vectorseparado,vectoranno, vectormes, vectordia;
    /**
     * 
     * vectorquantityint Vector donde alojaremos las cantidades en formato doble
     * vectorcount es un vector que guardara las cantidades totales de reciclaje
     * 
     */
    vector<int> vectoramountint, vectorvalueint, vectoryearint, vectordateint, vectorsuma, vectorannoint;
    /**
     * 
     * contador es donde se guardara la suma de los valores en el vectorquantity
     * auxiliar es donde guarda el valor del vector de manera auxiliar para la sumatoria
     * 
     */
    int contador, auxiliar, suma, fecha;

    // Abre los csv

    ifstream dollars, smi;
    dollars.open("dollars1.csv");
    smi.open("smi1.csv");

    getline(dollars,linea); // Q U I T A T Í T U L O S
    getline(smi,linea2);

    while(dollars.good())
        {
        getline(dollars, anno, '-');
        vectoranno.push_back(anno);

        getline(dollars, mes, '-');
        vectormes.push_back(mes);
            
        getline(dollars, dia, ';');
        vectordia.push_back(dia);

        getline(dollars, amount, '\n');
        vectoramount.push_back(amount);
        }

    while(smi.good())
        {
        getline(smi, year, ';');
        vectoryear.push_back(year);

        getline(smi, value, '\n');
        vectorvalue.push_back(value);
        }

    // Transforma los amount y value en int para utilizarlos en los calculos

    for (int a = 0; a<vectoramount.size(); a++){
        string Aux = vectoramount[a].substr(1,vectoramount[a].length());
        int Valor = atoi(Aux.c_str());
        vectoramountint.push_back(Valor);}
    for (int b = 0; b<vectorvalue.size(); b++){
        string Aux2 = vectorvalue[b].substr(1,vectorvalue[b].length());
        int Valor2 = atoi(Aux2.c_str());
        vectorvalueint.push_back(Valor2);}
    for (int c = 0; c<vectoranno.size(); c++){
        string Aux3 = vectoranno[c].substr(1,vectorvalue[c].length());
        int Valor3 = atoi(Aux3.c_str());
        vectorannoint.push_back(Valor3);}
    
    fecha = 1990;

    for (int i=0;i<vectorannoint.size();i++){
        while (fecha < 2021){
            if (vectorannoint[i]==fecha){
                contador = contador + vectoramountint[i];
            }
            vectorsuma.push_back(contador);
            contador=0;
            fecha++;
        }
    }
    return 0;
}

void participantes() {
    std::cout << std::endl << "=== Tarea ===" << std::endl;
    std::cout << std::endl << "Shu-yi Wong" << std::endl; 
}