from bluetooth import *

client_socket=BluetoothSocket(RFCOMM)
client_socket.connect(("-", 1)) 

try:
    msg = client_socket.recv(1024)		# 수신
    print(f"recived message : {msg}") 
    
except KeyboardInterrupt:
    print("Finished")

client_socket.close() 
