This project uses both C++ and Python to manipulate images by flipping, mirroring, and inverting them. 
The program is designed to be run from the command line, although it can be cloned and edited in CLion. 
However, it's recommended to execute the program directly in the terminal for the best experience.

The C++ program prompts the user to input an image filename, validates it, and then asks for the type of manipulation they want to apply. 
After receiving this information, the program passes the data as command line arguments to a Python script.
The Python script uses CV2 library to apply the chosen manipulation, generating a manipulated version of the image.
The program then displays the original image, the manipulated image, and a kaleidoscope effect of hte image in separate windows.

To run the program, manipulate an image. Here are the steps to run the program:
- Create a build folder using mkdir build
- Navigate into the foler using cd build
- Compile the program with g++ -std=c++17 -o manipulator ../main.cpp
- Run the program with .manipulator (Mac/Linux) or manipulator (Windows)
	- If you encounter a Python import error, install the necessary Python package with: pip3 install opencv-python

