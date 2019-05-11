import serial
import time
from PIL import Image

ser = serial.Serial('/dev/ttyACM0')  # open serial port
ser.baudrate = 115200
red = "0"
green = "255"
blue = "0"
red = red.zfill(3)
green = green.zfill(3)
blue = blue.zfill(3)

def draw(r,g,b):
    ser.write(r)
    ser.write(",")
    time.sleep(0.006)
    ser.write(g)
    ser.write(",")
    time.sleep(0.006)
    ser.write(b)
    ser.write(",")
    time.sleep(0.006)



TARGET_HEIGHT = 118
SOURCE_IMAGE = "test2.jpeg"

sample_img = Image.open(SOURCE_IMAGE)

orig_width, orig_height = sample_img.size
target_width = orig_width * TARGET_HEIGHT // orig_height

target_img = sample_img.resize((target_width, TARGET_HEIGHT), Image.BICUBIC, None)
print("Image Collumns: ", target_width)

target_img.save("target.jpg")
rgb_data = target_img.convert('RGB');

#target_data = []
#for col in range(0, target_width - 1):
#    print("row")
#    print(col)
#    for row in range(TARGET_HEIGHT - 1, -1, -1):
#        r, g, b = target_img.getpixel((col, row))
#        draw(str(r).zfill(3),str(g).zfill(3),str(b).zfill(3))
#    time.sleep(0.25)
#    for row in range(TARGET_HEIGHT):
#        draw(str(0).zfill(3),str(0).zfill(3),str(0).zfill(3))
#        pass
#    time.sleep(1)


#curr_col.append([str(r).zfill(3), str(g).zfill(3), str(b).zfill(3)])
#target_data.append(curr_col);
#print(target_data)


print(ser.name)         # check which port was really used
for value in range(118):
    #print("LED-Nr:")
    #print(value)
    draw(red,green,blue)
    pass
print("sent data")

time.sleep(1)

red = "255"
green = "0"
blue = "0"
red = red.zfill(3)
green = green.zfill(3)
blue = blue.zfill(3)

for value in range(118):
    #print("LED-Nr:")
    #print(value)
    draw(red,green,blue)
    pass
print("sent data")

time.sleep(1)

ser.close()
