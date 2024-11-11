#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

int main() {
    int serial_port = open("/dev/serial0", O_RDWR);  // Open the serial port
    if (serial_port == -1) {
        perror("Unable to open serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);

    if (tcgetattr(serial_port, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    // Set baud rate
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    // Set 8N1 (8 data bits, no parity, 1 stop bit)
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;

    // Set input mode (non-canonical, no echo, no signal chars)
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ISIG;

    // Set output mode (no processing)
    tty.c_oflag &= ~OPOST;

    // Set control modes
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 5;

    // Apply the settings
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return 1;
    }

    printf("Serial connection established. Reading data...\n");

    while (1) {
        char received_char;
        int n = read(serial_port, &received_char, 1);  // Read 1 byte from serial port
        if (n > 0) {
            printf("Received: %c\n", received_char);  // Print the received character
        }
    }

    close(serial_port);  // Close the serial port
    return 0;
}
