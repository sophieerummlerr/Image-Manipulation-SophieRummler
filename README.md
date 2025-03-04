# Image-Manip

Create a fun image manipulator!

For this project, you will use C++ and Python to manipulate an image by flipping, mirroring, and inverting it.

You may work individually or with a partner of your choosing.

## Setup

Use this Guided Project template to create a new repository (see [GitHub-with-CLion](https://github.com/uvmcs2300s2025/GitHub-with-CLion) repo for directions).
**Your repository must be named with the convention: Image-Manip-netid**, where netid is your UVM NetID username.
* If you are collaborating, the format is Image-Manip-netid1-netid2. Have one partner create the repository and give the other partner access on GitHub: on the repository page, go to the Settings tab, choose Manage Access, and add the person with their GitHub username.

Remember to commit and push frequently.

## Image Manipulations

It is intended that you will run this program from command line. You can still clone it into CLion and edit the files in CLion, but we recommend you run the program in your CLI. 

Your program will start in C++ and prompt the user for an image filename. After validating it, it will ask the user for a manipulation. Once it has that information, it calls the Python file and gives the information as command line arguments.

The Python file uses the CV2 library to create the manipulated image. You will display the original image, the chosen manipulation next to it in a separate window, and then finally a kaleidoscope image (see `autumn.jpg` and `autumn_kaleidoscope.jpg` for an example of what this manipulation will look like).

To get the program working, this is what you need to do:
1. Read through `main.cpp`.
1. Below main, implement the three functions declared above main.
1. Read through `render.py`.
1. Complete all TODOs in `render.py`.
1. Run the program to manipulate autumn.jpg. To run the program, use the commands:
    * `mkdir build` to create a build folder
    * `cd build` to go into the build folder
    * `g++ -std=c++17 -o manipulator ../main.cpp` to compile
    * either `./manipulator` (Mac/Linux) or `manipulator` (Windows) to run.
        * If you get a Python import error: use pip in the command line to install the package: `pip3 install opencv-python`.
1. Find at least one other valid image file, put it in your project folder, add it to Git, and run it through the image manipulator.
    * Make sure your image is appropriate.

## Grading

If you are collaborating, both partners have to submit the project.

### Grading Rubric
- [ ] (6 pts) Implement the three functions in `main.cpp`.
- [ ] (12 pts) Complete all TODOs in `render.py`.
- [ ] (2 pt) Include a valid second image in your repository.
