#include<iostream>
#include<math.h>
#include"funciones.h"

using namespace std;


//Metodo Runge-Kutta 4.
double* RK4(double y0, double v0, double t, double dt){
    
    //Declaro variables que usare mas adelante
    double T_new;
    double Y_new;
    
    //Establezco el valor inicial de Y con el que comenzaré RK
    double Y = Y_func(y0, t, v0);
    
    //Declaro el vector que sera almacenará mis datos
    double* res = new double[2];
    
    //Declaro y calculo las constantes de RK4
    double k1 = V_func(Y, t)*dt;
    double k2 = V_func((Y+(k1/2)), (t+(dt/2)))*dt;
    double k3 = V_func((Y+(k2/2)), (t+(dt/2)))*dt;
    double k4 = V_func(Y + k3, t + dt)*dt;
    
    //Actualizo la altura y doy un paso de tiempo
    Y_new = Y + ((1.0/6.0)*(k1 + (2*k2) + (2*k3) + k4));
    T_new = t+dt;
    
    //Guardo los valores de altura y tiempo
    res[0] = T_new;
    res[1] = Y_new;
    
    return res;  
}

//Aqui resuelvo el ejercicio
int main(){
    
    //Condiciones iniciales
    double y0 = 8.5; //altura inicial, [m]
    double v0 = 20; //Velocidad inicial, [m/s]
        
    //Para RK4
    double dt = 0.1; // Tamaño de paso para el tiempo, [s]
    double t = t_func(v0); //Tiempo de vuelo, [s]
    double t0 = 0; //Momento inicial, [s]
    
    double y = Y_func(y0, t0, v0);
    double v = V_func(v0, t0);
    
    //Creo los vectores donde guardare las respuestas finales
    int c = (t/dt); //Numero de puntos que voy a guardar
    double C = (t/dt); //Igual que antes, pero para el tiempo
    double * tiempo = new double[c];
    double * altura = new double[c]; 
    
    int i = 0;
    double T = 0;
    
    while(i < c and T < C){
        
        //Resuelvo haciendo RK4
        double* res = RK4(y0, v0, T, dt);
        tiempo[i] = res[0];
        altura[i] = res[1];
        
        //Actualizo los valores de i y T para el ciclo
        T += 0.1;
        i++; 
    }
    
    int i2 = 0;
    
    while(i2 < c){
        
        //Resultados que van a datos.txt
        cout << tiempo[i2] << " " << altura[i2] << endl;
        
        //Actualizo i2 para seguir el ciclo
        i2++;
    }
    
    return 0;
}