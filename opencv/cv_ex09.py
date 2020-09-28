import cv2

cap = cv2.VideoCapture(0) # 0번 카메라

frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)),
              int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
print('frame_size = ', frame_size)

fourcc = cv2.VideoWriter_fourcc(*'DIVX')
# fourcc = cv2.VideoWriter_fourcc(*'XVID')

out1 = cv2.VideoWriter('./data/record0.mp4', fourcc, 20.0, frame_size)
# out2 = cv2.VideoWriter('./data/record1.mp4', fourcc, 20.0, frame_size,isColor=False)