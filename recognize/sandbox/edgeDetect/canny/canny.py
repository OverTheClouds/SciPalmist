#coding=utf-8  
import cv2  
import numpy as np    
  
img = cv2.imread("input.jpg", 0)  
for th2 in range(1,20,1):
    for th1 in range(1, th2, 1):
        gray = cv2.GaussianBlur(img,(9,9),0)  
        canny = cv2.Canny(gray, th1, th2)  
#        cv2.imwrite("gray_%d_%d.jpg"%(th1,th2),gray)
        cv2.imwrite("canny_%d_%d.jpg"%(th2,th1),canny)
