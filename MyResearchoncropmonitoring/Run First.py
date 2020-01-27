import serial
import time
import datetime

ser = serial.Serial(port='COM4',baudrate=9600)

print("connected to: " + ser.portstr)

while True:
    line = ser.readline().decode('ascii')
    #timestamp = str(time.time())
    timestamp1 = str(datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
    timestamp = str(datetime.datetime.fromtimestamp(time.time()).strftime('%M'))
    with open('output1.txt', 'a') as pyfile:
        y=timestamp+","+line
        pyfile.write(y +'\n')

ser.close()


