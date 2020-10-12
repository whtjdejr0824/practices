import threading
from time import sleep

def sum(low, high):
    total = 0
    for i in range(low, high):
        total += i
    print("Subthread", total)

t = threading.Thread(target=sum, args=(1, 1000000))
t.start()

print("Main Thread")