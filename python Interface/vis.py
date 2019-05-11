import serial
import time
ser = serial.Serial('/dev/ttyACM0')  # open serial port
ser.baudrate = 115200
red = "0"
green = "255"
blue = "0"
red = red.zfill(3)
green = green.zfill(3)
blue = blue.zfill(3)


print(ser.name)         # check which port was really used
for value in range(118):
    print("LED-Nr:")
    print(value)
    stuff_in_string = "%s,%s,%s" % (red,green,blue)
    print(stuff_in_string)
    ser.write(stuff_in_string)      # write a string
    print("sent data")

    time.sleep(0.001)
    pass
ser.close()
