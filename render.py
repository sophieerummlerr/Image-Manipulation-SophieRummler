# TODO: you will need to install cv2
# Run "pip3 install opencv-python" in CLI
import cv2
import sys
import numpy as np
# Kaleidoscope requires numpy. Uncomment this line and install it if you need to.
#import numpy as np
if len(sys.argv) < 3:
    print("Usage: python render.py <filename> <manipulation>")
    sys.exit()
# Store command line arguments in variables
# TODO: change the next line to store the filename
filename = sys.argv[1]
manip = sys.argv[2]

# Open the image file
img = cv2.imread(filename)

# check it was loaded correctly
if img is None:
    print(f"Error: Could not open or find the image {filename}")
    sys.exit()

# Get the dimensions (in pixels) of the image
dimensions = img.shape
# Copy the original image into an image for manipulation
img_manip = cv2.resize(img, (dimensions[1], dimensions[0]))
# TODO: Store white in a list, where each of the three parts is on a scale of [0, 255]
white = [255, 255, 255]

for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        if manip == 'flip':
            img_manip[x, y] = img[dimensions[0]-1-x, y]
        elif manip == 'mirror':
            img_manip[x, y] = img[x, dimensions[1]-1-y]
        elif manip == 'invert':
            img_manip[x, y] = [white[i] - img[x, y][i] for i in range (3)]

# Displays the original image in the top left corner of the screen.
cv2.namedWindow('Original image')
cv2.moveWindow('Original image', 0, 0)
cv2.imshow('Original image', img)
# TODO: Display the manipulated image alongside the original image.
cv2.namedWindow('Manipulated image')
cv2.moveWindow('Manipulated image', dimensions[1],0)
cv2.imshow('Manipulated image', img_manip)


# TODO: Create a kaleidoscope image, display it, and save it to a file.
img_flip = cv2.flip(img, 0)
img_mirror = cv2.flip(img, 1)

top_row = np.concatenate((img, img_mirror), axis=1)
bottom_row = np.concatenate((img_flip, cv2.flip(img_mirror, 0)), axis=1)
kaleidoscope = np.concatenate((top_row, bottom_row), axis=0)

#save and kaleidoscope image
cv2.imwrite('kaleidoscope_image.jpg', kaleidoscope)
cv2.imshow('kaleidoscope Effect', kaleidoscope)

# Infinite loop to keep the windows open until the escape key is pressed.
while True:
    k = cv2.waitKey(1)
    if k == 27:
        cv2.destroyAllWindows()
        break
