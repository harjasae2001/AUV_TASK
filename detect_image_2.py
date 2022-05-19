import cv2
import numpy as np


image = cv2.imread("/home/harjasae2001/Desktop/WhatsApp Image 2022-02-08 at 19.03.39.jpeg")                
# Convert BGR to HSV
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# define orange color range
light_orange = np.array([5,50,50],np.uint8)

dark_orange = np.array([15,255,255],np.uint8)



# Threshold the HSV image to get only blue colors
mask = cv2.inRange(hsv, light_orange, dark_orange)

# Bitwise-AND mask and original image
output = cv2.bitwise_and(image,image, mask = mask)
    
cv2.imshow("Color Detected", np.hstack((image,output)))
cv2.waitKey(0)
cv2.destroyAllWindows()