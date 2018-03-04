import cv2
import numpy as np

img = cv2.imread("input_1.jpg", 0)
x = 1 
cv2.imwrite("canny.jpg", cv2.Canny(img, x, 3*x))
