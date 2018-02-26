#!/usr/bin/env python

import cv2

imgName = "contour.jpg";
kernel_size = (9, 9);
sigma = 30;

img = cv2.imread(imgName);
img = cv2.GaussianBlur(img, kernel_size, sigma);
new_imgName = "New_" + str(kernel_size[0]) + "_" + str(sigma) + "_" + imgName;
cv2.imwrite(new_imgName, img);
