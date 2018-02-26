import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt
img = cv.imread('gray.jpg')
kernel = np.ones((5,5),np.float32)/25
dst = cv.filter2D(img,-1,kernel)
dst = cv.filter2D(dst,-1,kernel)
dst = cv.filter2D(dst,-1,kernel)
dst = cv.filter2D(dst,-1,kernel)
dst = cv.filter2D(dst,-1,kernel)
cv.imwrite("output_5.jpg", dst)
