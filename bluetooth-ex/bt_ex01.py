#라즈베리파이에서 아두이노로 메시지 보내기
from bluetooth import *
from btsocket import BtSocket

LINE_END = "\r\n"

#Create the client socket
# client_socket=BluetoothSocket(RFCOMM)
client_socket=BtSocket(RFCOMM)
client_socket.connect(("00:18:91:D7:9F:C4", 1)) # 접속  

try:
    while True: 
        msg = input("Send : ") + LINE_END 
        client_socket.send(msg) 	# 전송

        # msg = client_socket.recv(1024)  #수신
        msg = client_socket.readline()
        print(f"recived message : {msg}")

except KeyboardInterrupt:
    print("Finished")

client_socket.close() 
