import serial
import csv
from datetime import datetime

def readserial(comport, baudrate, output_file='serial_log.csv'):
    ser = serial.Serial(comport, baudrate, timeout=0.1)
    matrix = []

    print("Reading serial data... Press Ctrl+F2 or Ctrl+C to stop.")
    try:
        while True:
            data = ser.readline().decode(errors='ignore').strip()
            if data:
                timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                print(f"{timestamp}: {data}")
                matrix.append([timestamp, data])
    except KeyboardInterrupt:
        print("\nStopping and saving data...")
        ser.close()

        # Save to CSV
        with open(output_file, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['Timestamp', 'Data'])
            writer.writerows(matrix)
        print(f"Data saved to {output_file}")

if __name__ == '__main__':
    readserial('/dev/ttyACM0', 9600)
