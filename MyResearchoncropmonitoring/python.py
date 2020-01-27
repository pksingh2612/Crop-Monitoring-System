import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

style.use('fivethirtyeight')

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)

def animate(i):
    graph_data = open('output1.txt','r').read()
    lines = graph_data.split('\n')
    xs = []
    y1s = []
    y2s = []
    y3s = []
    y4s = []
    for line in lines:
        if len(line) > 1:
            a,b,c,d,e = line.split(',')
            xs.append(float(a))
            y1s.append(float(b))
            y2s.append(float(c))
            y3s.append(float(d))
            y4s.append(float(e))
    ax1.clear()
    ax1.plot(xs, y1s,label='First line')
    ax1.plot(xs, y2s,label='Second line')
    ax1.plot(xs, y3s,label='Thrid line')
    ax1.plot(xs, y4s,label='Fourth line')
    
ani = animation.FuncAnimation(fig, animate, interval=1000)
#plt.show()