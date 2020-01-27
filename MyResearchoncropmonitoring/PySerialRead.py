import serial
import time
import datetime

ser = serial.Serial(
    port='COM4',baudrate=9600)

print("connected to: " + ser.portstr)

while True:
    line = ser.readline().decode('ascii')
    #timestamp = str(time.time())
    timestamp = str(datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
    with open('output.txt', 'a') as pyfile:
        pyfile.write(line + ' ' + timestamp +'\n')

ser.close()
