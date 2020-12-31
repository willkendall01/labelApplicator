import serial
# Establish the connection on a specific port
ser = serial.Serial('COM3', 9600)

while True:
    direct = input("what to do? ")
    # Convert the decimal number to ASCII then send it to the Arduino
    ser.write(bytes(direct, 'ascii'))
    print(ser.readline())  # Read the newest output from the Arduino
