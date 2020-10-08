from bluetooth import *
from btsocket import BtSocket

LINE_END = "\r\n"

#Create the client socket
# client_socket=BluetoothSocket(RFCOMM)
client_socket=BtSocket(RFCOMM)
client_socket.connect(("00:18:91:D7:9F:C4", 1)) 

try:
    while True:
        msg = input(S)
    msg = client_socket.recv(1024)		# 수신
    print(f"recived message : {msg}") 
    
except KeyboardInterrupt:
    print("Finished")

client_socket.close() 