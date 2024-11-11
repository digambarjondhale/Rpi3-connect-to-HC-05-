import serial
import time

# Configure the serial connection to the HC-05
serial_port = '/dev/serial0'  # For Pi 3 and later, '/dev/serial0' points to the GPIO serial pins
baud_rate = 9600  # Match this with the HC-05's baud rate

# Initialize the serial connection
bluetooth_serial = serial.Serial(serial_port, baud_rate, timeout=1)

print("Connected to HC-05")

try:
    while True:
        # Check if there is incoming data from the HC-05
        if bluetooth_serial.in_waiting > 0:
            # Read the incoming data (bytes)
            received_data = bluetooth_serial.readline()

            # Print the raw bytes
            print("Received data (raw bytes):", received_data)

            # Convert the bytes to a hex string for better readability
            hex_data = ' '.join(f'{byte:02x}' for byte in received_data)
            print("Hexadecimal format:", hex_data)

            # Optionally, if you want to process data as integers:
            int_data = list(received_data)
            print("Data as integers:", int_data)

        # Optional: Sending data back to the HC-05
        # bluetooth_serial.write(b"Hello from Raspberry Pi!\n")

        time.sleep(0.1)  # Small delay for stability

except KeyboardInterrupt:
    print("Disconnected")
    bluetooth_serial.close()
