#!/bin/bash

echo ejecutando main.cpp

g++ main.cpp && ./a.out > datos.txt

python grafica.py

echo Listo! ^_^ 
