import time
import sys
from PIL import Image

#-----------------Settings-------------
SOURCE_IMAGE = "dieMitDerCouch.bmp"
TARGET_HEIGHT = 118
#--------------------------------------


sample_img = Image.open(SOURCE_IMAGE)
orig_width, orig_height = sample_img.size
target_width = orig_width * TARGET_HEIGHT // orig_height
target_img = sample_img.resize((target_width, TARGET_HEIGHT), Image.NEAREST, None)

#Debugging
#print("Image Columns: ", target_width)

target_img.save("target.jpg")
rgb_data = target_img.convert('RGB');

#Debugging - how may colums
werte=0

sys.stdout.write("#include <Arduino.h> \nconst PROGMEM uint8_t image0[] = {")

for col in range(0, target_width - 1):
    for row in range(TARGET_HEIGHT - 1, -1, -1):
        r, g, b = target_img.getpixel((col, row))
        sys.stdout.write(str(r)+','+str(g)+','+str(b)+',')
        werte = werte+3
    #sys.stdout.write("\n") 

sys.stdout.write("}")

#Debugging
#print("")
#print(werte)
