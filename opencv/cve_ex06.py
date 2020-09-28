import cv2
import numpy as np

src = cv2.imread('./data/lena.jpg', cv2.IMREAD_GRAYSCALE)
dst = np.zeros(src.shape, dtype=src.dtype)

N = 8 # 8, 32, 64
height, width = src.shape
# height, width, _ = src.shape # 컬러 영상

h = height // 4
w = width // 4

for i in range(N):
    for j in range(N):
        y = i * h
        x = j * w
        roi = src[y:y+h, x:x+w]
        dst[y:y+h, x:x+w] = cv2.mean(roi)[0] # 그레이스케일 영상
        # dst[y:y+h, x:x+w] = cv2.mean(roi)[0:3] # 컬러 영상