File = 'heatmap_data.txt'
DataW = 512
DataH = 512
SmoothWindowSize = 10

import matplotlib.pyplot as plt
import numpy as np

f = open(File, 'r')

data = [[0 for i in range(DataW)] for j in range(DataH)]
color = [[0 for i in range(DataW)] for j in range(DataH)]

for line in f:
	point = line.split()
	if len(point) == 4:
		data[int(point[1])][int(point[0])] += 1
	else:
		exit(1)

for i in range(DataH):
	for j in range(DataW):
		for k in range(i-SmoothWindowSize, i+SmoothWindowSize):
			if k >= 0 and k < DataH:
				for l in range(j-SmoothWindowSize, j+SmoothWindowSize):
					if l >= 0 and l < DataW:
						color[i][j] += data[k][l]


plt.pcolor(np.array(color))
plt.axis('tight')
plt.show()

