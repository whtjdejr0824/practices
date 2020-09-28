import cv2
# import numpy as np
img = cv2.imread('./data/lena.jpg', cv2.IMREAD_GRAYSCALE)
img[120, 200] = 0 # 화소값(밝기, 그레이스케일) 변경
print(img[100:110, 200:210]) # ROI 접근

# for y in range(100, 400):
#     x in range(200, 300):
#         img[y, x] = 0

# img[100:400, 200:300] = 0 # ROI 접근
img[0:100, 0:200] = img[200:400, 200:400] #a=b라고 할때, b의 영역을 a에 복사하여 붙여넣는다.

cv2.imshow('img', img)
cv2.waitKey()
cv2.destroyAllWindows()