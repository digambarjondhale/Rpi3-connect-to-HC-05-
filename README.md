# Rpi3-connect-to-HC-05
send data from an Android app to a Raspberry Pi board using an HC-05 Bluetooth module
*****************************************************************IMP NOTE ****************************************************************
note:- Ensure that your Raspberry Pi's serial port is enabled. You can enable UART in the raspi-config tool:
commend :- sudo raspi-config
          1)Go to Interfacing Options 
          IMP note :- 1) disable the login shell over serial 
                      2) enable the serial hardware.
*************************************************************************************************************************************
1)rpi_hc05_blut_reciveddata_print_only.c: This is a C file, and you can compile it directly using the following command:
 cmd:- gcc rpi_hc05_blut_reciveddata_print_only.c -o rpi_hc05_blut_reciveddata


2)rpi_hc05_blut_reciveddata_python.py: This is a Python file, and you can run it using the following command:
 cmd:- python3 rpi_hc05_blut_reciveddata_python.py

The Python file may require additional libraries to be installed, such as pyserial for serial communication. You can install it with:
 1) cmd :- pip3 install pyserial
  If needed, you can also set up a virtual environment to manage dependencies:
   cmd :-python3 -m venv env
   cmd:- source env/bin/activate
  cmd:- pip install pyserial
