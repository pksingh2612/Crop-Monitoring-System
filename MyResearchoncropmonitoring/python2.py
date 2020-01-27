import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style


style.use('fivethirtyeight')

fig1 = plt.figure()
fig2 = plt.figure()
fig3 = plt.figure()
fig4 = plt.figure()


ax1 = fig1.add_subplot(1,1,1)
ax2= fig2.add_subplot(1,1,1)
ax3=fig3.add_subplot(1,1,1)
ax4=fig4.add_subplot(1,1,1)

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
            a,b,c,d,e,f= line.split(',')
            xs.append(float(a))
            y1s.append(float(b))
            y2s.append(float(c))
            y3s.append(float(d))
            y4s.append(float(e))
            print(f)
    ax1.clear()
    ax2.clear()
    ax3.clear()
    ax4.clear()
    
    ax1.plot(xs, y1s,color='r')
    ax1.set_xlabel('Time(in min)')
    ax1.set_ylabel('Air Gas')
    ax1.set_title('Air Gas Sensor')

    ax2.plot(xs, y2s,color='m')
    ax2.set_xlabel('Time(in min)')
    ax2.set_ylabel('*C')
    ax2.set_title('Environment Temperature')
    
    ax3.plot(xs, y3s,color='c')
    ax3.set_xlabel('Time(in min)')
    ax3.set_ylabel('H')
    ax3.set_title('Environment Humidity')
    
    ax4.plot(xs, y4s,color='b')
    ax4.set_xlabel('Time(in min)')
    ax4.set_ylabel('moisture')
    ax4.set_title('Soil Moisture')
    
    
ani = animation.FuncAnimation(fig1, animate, interval=1000)
ani = animation.FuncAnimation(fig2, animate, interval=1000)
ani = animation.FuncAnimation(fig3, animate, interval=1000)
ani = animation.FuncAnimation(fig4, animate, interval=1000)

plt.show()
