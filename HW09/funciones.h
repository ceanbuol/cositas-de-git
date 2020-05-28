#include<iostream>
#include<math.h>

using namespace std;

double t_func(int v0){
    
    double g = 9.8; //Aceleración de la gravedad, [m/s^2]
    
    //Calculando el tiempo de vuelo, [s]
    double tiempo = (2*v0)/g;
    return tiempo;
}

double Y_func(double y, double t, double v0){
    
    double g = 9.8; //Aceleración de la gravedad, [m/s^2]
    
    //Calculando la altura, [m]
    double Y_nuevo = y + (v0*t) - ((1.0/2.0)*g*(pow(t,2))); 
    return Y_nuevo;
}

double V_func(double v0, double t){
    
    double g = 9.8; //Aceleración de la gravedad, [m/s^2]
    
    //Calculando la velocidad, [m/s]
    double V_nueva = v0 - (g*t);
    return V_nueva;
}
