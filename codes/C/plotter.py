import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sensor_data.csv')

plt.scatter(data['Time'], data['Temperature'], color='blue', label='Sensor Data')

plt.xlabel('Time (Hours)')
plt.ylabel('Temperature (c)')
plt.title('Real-time Sensor Feed')
plt.legend()
plt.show()