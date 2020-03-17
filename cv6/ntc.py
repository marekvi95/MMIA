# author: marek vitula
import matplotlib.pyplot as plt
import numpy as np
import numpy.polynomial.polynomial as poly
from numpy import genfromtxt
import csv

ntc_data = genfromtxt('ntc.csv', delimiter=',') # Load NTC data to arrays
t = ntc_data[:, 0] # temperature in degrees celsius
r = ntc_data[:, 1] # resistivity in kiloohms

vref = 3.3 # voltage reference
rf = 10000 # voltage divider rf value 10 kohm
r = r*10000 # convert kohm to ohms

vout = vref*(r/(r+rf)) # calculate voltage output on
ad = 1023/vref * vout
plt.plot(ad,t, '.')

p = np.polyfit(ad, t, 10)
ad2 = np.arange(0, 1024)
t2 = np.round(np.polyval(p, ad2), 1)

x_new = np.linspace(ad[0], ad[-1], num=len(ad)*10)
coefs = poly.polyfit(ad, t, 10)
ffit = poly.Polynomial(coefs)    # instead of np.poly1d
plt.plot(ad,t, '.')
plt.plot(x_new, ffit(x_new))

# plt.plot(ad,t, '.', ad2, t2, '-')
plt.xlabel('ADC value')
plt.ylabel('Temperature [°C]')
plt.title('NTCC-10K')
plt.xlim(0, 1023)
# plt.ylim(-30, 125)
plt.show()

t2_cliped = np.clip(t2, a_min = -50, a_max = 150) # limit min and max temperature
print(t2_cliped)
np.savetxt('data.out', t2_cliped*10, newline=',', fmt='%d') 