import numpy as np
import matplotlib.pyplot as plt


mensaje = "sample.dat"
myarray = np.fromfile(mensaje, dtype=float)

solucion = np.exp(1)-1
error = []
for i in range(0,len(myarray)):
    error.append(np.abs(solucion-myarray[i])/solucion)

x = np.linspace(len(myarray))
plt.figure()
plt.scatter(x,myarray)
plt.yscale('log')
plt.
