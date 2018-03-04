import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread('contour.jpg')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (51,51), 39);

corners = cv2.goodFeaturesToTrack(gray,6,0.01,10)
corners = np.int0(corners)
print(corners)
print(len(corners))

for i in corners:
    x,y = i.ravel()
    cv2.circle(img,(x,y),30,(255,255,255),-1)
cv2.imwrite("output.jpg",img)
