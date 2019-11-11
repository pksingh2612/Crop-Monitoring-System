import serial
import time
import datetime
import csv
import os
import pandas as pd
from plotly.subplots import make_subplots
import plotly.graph_objects as go

def run():
    mycmd=os.popen('python -m serial.tools.list_ports').read()
    a=mycmd.split(" ")
    
    with open('output1.csv','w') as csvFile:
        csvData = ['Timestamp','Air Gas','Humidity(%)','Temperature( *C )','Temperature( *F )','Soil Moisture','Rain']
        writer = csv.DictWriter(csvFile,fieldnames=csvData)
        writer.writeheader()
        writer.writerow({'Timestamp':'0','Air Gas':0,'Humidity(%)':0.0,'Temperature( *C )':0.0,'Temperature( *F )':0.0,'Soil Moisture':0,'Rain':0})
    csvFile.close()
    
    ser = serial.Serial(port=a[0],baudrate=9600)
    print("connected to: " + ser.portstr)
 
    i=200
    while True:
        line = ser.readline().decode('ascii')
        print(line)
        if len(line)>25:
            a,b,c,d,e,f,g=line.split(",")
            timestamp1 = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S')

            with open('output1.csv','a') as csvFile:
                csvData = ['Timestamp','Air Gas','Humidity(%)','Temperature( *C )','Temperature( *F )','Soil Moisture','Rain']
                writer = csv.DictWriter(csvFile,fieldnames=csvData)
                writer.writerow({'Timestamp':timestamp1,'Air Gas':int(a),'Humidity(%)':float(b),'Temperature( *C )':float(c),'Temperature( *F )':float(d),'Soil Moisture':int(e),'Rain':int(f)})
            csvFile.close()

            i-=1
            if i<=0:
                break
            
    ser.close()    
def fun():
    fig = make_subplots(rows=3, cols=2,specs=[[{}, {}],[{},{}],[{},{}]],#[{"colspan": 2}, None]],
    subplot_titles=("Air Gas","Humidity(%)", "Temperature( *C )",'Temperature( *F )','Soil Moisture','Rain'))

    data = pd.read_csv("output1.csv")
    
    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Air Gas'],mode='lines+markers',opacity=0.7),row=1, col=1)
    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Humidity(%)'],mode='lines+markers',opacity=0.7),row=1, col=2)
    
    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Temperature( *C )'],mode='lines+markers',opacity=0.7),row=2, col=1)
    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Temperature( *F )'],mode='lines+markers',opacity=0.7),row=2, col=2)

    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Soil Moisture'],mode='lines+markers',opacity=0.7),row=3, col=1)
    fig.add_trace(go.Scatter(x=data['Timestamp'], y=data['Rain'],mode='lines+markers',opacity=0.7),row=3, col=2)

    fig.update_layout(showlegend=False, title_text="Crop Monitoring System")
    fig.show()

run()
fun()


