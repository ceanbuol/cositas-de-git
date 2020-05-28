#Invocando las librerias que usare
import numpy as np
import matplotlib.pyplot as plt

#Cargando los datos como un array
datos = np.loadtxt("datos.txt")

#Asignando nombres a las columnas del arreglo de datos
t = datos[:,0]
y = datos[:,1]

#Una linda gráfica
fig  = plt.figure()
plt.plot(t,y)

#Cosas bonitas para la gráfica linda
plt.xlabel('Tiempo [s]')
plt.ylabel('Altura [m]')
plt.title('M.R.U.A: Particula en Tiro Vertical')
plt.grid()

#Guardando la gráfica
plt.savefig("Hola.pdf")