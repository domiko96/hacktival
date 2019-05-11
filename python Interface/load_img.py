#!/usr/bin/env python3

from PIL import Image

TARGET_HEIGHT = 118
SOURCE_IMAGE = "...<your path goes here> ..."

sample_img = Image.open(SOURCE_IMAGE)

orig_width, orig_height = sample_img.size
target_width = orig_width * TARGET_HEIGHT // orig_height

target_img = sample_img.resize((target_width, TARGET_HEIGHT), Image.BICUBIC, None)
print("Image Collumns: ", target_width)

target_img.save("target.jpg")
rgb_data = target_img.convert('RGB');

target_data = []
for col in range(0, target_width - 1):
	curr_col = [];
	for row in range(TARGET_HEIGHT - 1, -1, -1):
		r, g, b = target_img.getpixel((col, row))
		curr_col.append([str(r).zfill(3), str(g).zfill(3), str(b).zfill(3)])
	target_data.append(curr_col);

print(target_data)
