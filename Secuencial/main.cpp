#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participantes();

int main()
{
    /**
     * 
     * linea es un string para quitar la primera linea del archivo dollars
     * linea2 es un string para quitar la primera linea del archivo smi
     * anno es un string que guarda los valores del año
     * mes es un string que guarda los valores del mes
     * dia es un string que guarda los valores del dia
     * amount es un string tring que guarda el valor del dolar ese dia
     * year es un string que guarda el año del smi
     * value es un string que guarda el valor del smi
     * 
     */ 
    string linea,linea2,anno,mes,dia,amount,year,value;
    /**
     * 
     * vectoramount es el vector que guarda el valor del dolar
     * vectoryear guarda los años del smi
     * vectorvalue guarda el monto del smi
     * vectoranno guarda los años del dolar
     * vectormes guarda los meses del dolar
     * vectordia guarda los dias del dolar
     * 
     */
    vector<string> vectoramount,vectoryear,vectorvalue,vectoranno, vectormes, vectordia;
    /**
     * 
     * vectoramountint guarda los valores del dolar en formato float
     * vectorvalueint guarda los valores del smi en formato float
     * vectorsuma guarda el promedio del dolar por año
     * vectorvalores guarda el valor del smi en dolar de ese año
     * fechas es un vector que guarda los años analizados
     * 
     */
    vector<float> vectoramountint, vectorvalueint, vectorsuma, vectorvalores, fechas;
    /**
     * 
     * contador es una variable para contar la cantidad de veces que se repite un año
     * auxiliar guarda el valor actual del dolar ese dia
     * suma guarda la sumatoria de los dolares ese año
     * promedio guarda el promedio del dolar ese año
     * dolar guarda el valor del smi en dolar
     * x guarda el valor de la variable independiente
     * y guarda el valor de la variable dependiente
     * sumx es la suma de todas las variables independientes
     * sumy es la suma de todas las variables dependientes
     * sum_sqx es la suma de las variables indep al cuadrado
     * sumxy es la suma del producto de las variables
     * a es el punto donde la varuable x es 0
     * b es la pendiente
     * 
     */
    float contador, auxiliar, suma, promedio, dolar, x,y,sumx,sum_sqx,sumy,sumxy,a,b;

    // Abre los csv

    fechas = {1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020};

    ifstream dollars, smi;
    dollars.open("dollars.csv");
    smi.open("smi.csv");

    getline(dollars,linea); // Q U I T A T Í T U L O S
    getline(smi,linea2);

    // Guarda los datos en diferentes vectores

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
        float Valor = atoi(Aux.c_str());
        vectoramountint.push_back(Valor);
        }

    for (int b = 0; b<vectorvalue.size(); b++){
        string Aux2 = vectorvalue[b].substr(1,vectorvalue[b].length());
        float Valor2 = atoi(Aux2.c_str());
        vectorvalueint.push_back(Valor2);}
    
    // Saca el promedio del dolar anualmente

    for (int i=0;i<vectoranno.size();i++){
        if (vectoranno[i]==vectoranno[i+1]){
            auxiliar = vectoramountint[i];
            suma = suma + auxiliar;
            contador++;
            }
        else{
            contador++;
            suma = suma + vectoramountint[i];
            promedio = (suma/contador);
            vectorsuma.push_back(promedio);
            suma = 0;
            contador = 0;
        }
    }

    // Convierte el smi en valor en dolares

    for (int j=0; j<vectorvalueint.size(); j++){
        dolar = vectoramountint[j+5] / vectorsuma[j+1];
        vectorvalores.push_back(dolar);
    }

    // Iniciacion de variables a utilizar para el calculo de la regresion lineal

    sumx =0;
    sum_sqx =0;
    sumy=0;
    sumxy=0;

    for(int i=0;i<fechas.size();i++){
        x = fechas[i];
        y = vectorvalores[i];
        sumx = sumx + x;
        sum_sqx = sum_sqx + (x*x);
        sumy= sumy + y;
        sumxy = sumxy + (x*y);
        }

    b = (sumxy-(sumx*sumy)/fechas.size())/(sum_sqx-(sumx*sumx)/fechas.size());
    a = (sumy/fechas.size())-(b*sumx/fechas.size());
    printf("\ny = %f + %fx\n",a,b);
    participantes();

    return 0;
}

void participantes() {
    std::cout << std::endl << "=== Tarea ===" << std::endl;
    std::cout << std::endl << "Shu-yi Wong" << std::endl; 
}