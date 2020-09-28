import cv2

cap = cv2.VideoCapture(0)
# cap = cv2.VideoCapture('http://192.30.1.18:4747/mjpegfeed') # droid cam
# frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)),
#               int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
print('frame_size = ', frame_size)

while True:
    retval, frame = cap.read() # 프레임 캡처
    if not retval: break
    cv2.imshow('frame', frame)
    key = cv2.waitKey(40) # 25ms 대기, 초당 frame? 40 : FPS(Frame pre Second)
    if key == 27: break # ESC 키

if cap.isOpened():
    cap.release()

cv2.destroyAllWindows()