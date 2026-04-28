import socket
import matplotlib.pyplot as plt
from collections import deque

HOST = '127.0.0.1'
PORT = 8080

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((HOST, PORT))

data = deque(maxlen=30)

plt.ion()
fig, ax = plt.subplots()

while True:
    msg = sock.recv(1024).decode().strip()

    if msg:
        try:
            value = int(msg)
            data.append(value)

            ax.clear()
            ax.plot(list(data))
            ax.set_title("Distance (cm)")
            ax.set_xlabel("Time")
            ax.set_ylabel("Distance")

            plt.pause(0.1)
        except:
            pass

