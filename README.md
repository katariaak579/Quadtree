# Quadtree
Spatial Indexing and Image Compression using Quadtree
# Quad Trees



# How to use our program?
[Watch youtube video to view a demo](https://youtu.be/eAPH4_CFyYU)<br>
Or follow the below instructions<br>
To download our program, please copy and paste this line to your terminal:
```
git clone https://github.com/aggarwal-aditya/Quad-Trees-Image-Compression-CS201-Project.git
```
Then type
```
cd CS201-Project
```
### First you will need to decide if you want to simulate 2D Point Quad Tree or Image Compression Quad Tree:
To simulate image compression, type ``` cd img_proc ``` in your terminal. To simulate 2D Points quad tree, type ``` cd 2DPoints ``` in your terminal.

---

### Further Steps to run Image Compression
It is expected that your system has OpenCV library installed (it has been  used for reading and writing images as we cant do this directly in C/C++). If not steps for the same are given below.

***Steps to install OpenCV***

Build and install OpenCV in your machine if you already haven't. Here are guides to do the same:
* [For Ubuntu](http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/) 
* [For Windows](https://cv-tricks.com/how-to/installation-of-opencv-4-1-0-in-windows-10-from-source/)
* [For MacOS](https://docs.opencv.org/master/d0/db2/tutorial_macos_install.html)

***Recommendation***: Installing OpenCV on windows is a tediuos task and not advised. For easier and quicker installation use Ubuntu(Best Choice) or MacOS(Second Best Choice). If you are on a windows machine, and dont have a Linux distribution installed in your system, you may use a virtual machine.

***Linux***<br>
After installing OpenCV, type ```make``` in your terminal. This will produce an output file ***test***. To run this file type ```./test``` in your terminal. If makefile gives error follow the steps mentioned for Windows.

***Windows***<br>
After installing OpenCV,type the below command in your terminal:
```
g++ main.cpp image.cpp image.hpp -o test -std=c++11 `pkg-config --cflags --libs opencv`
```
This will generate an output file ***test.exe***. To run this file type ```./test```  or ```./test.exe``` in your terminal.
### Further Common Steps for any OS
After this the programme will ask you the path of image which is to compressed. After you enter the required path, it will ask you if you want to proceed with default setting for image variance(a measure for image compression) or want to change it. After providing the required inputs the programme will display the original and compressed file. The compressed file will also be saved with a name ***modified.jpeg*** in the directory where code is present. 

---

### Further Steps to run 2D Point Quad Tree
***Linux***<br>
Type ```make``` in your terminal. This will produce an output file ***test***. To run this file type ```./test``` in your terminal. If makefile gives error follow the steps mentioned for Windows.

***Windows***<br>
Type the below command in your terminal:
```
g++ main.cpp tree.h Node.h coordinates.h -o test -std=c++11
```
This will generate an output file ***test.exe***. To run this file type ```./test``` or ```./test.exe``` in your terminal.
### Further Common Steps for any OS
After this programme starts and is pretty self explanatory. It gives option to insert point, find point adress and find point data. Please be aware that the current implementation does not support addition of same point multiple times with differnt data_value. Please dont try to do so.

---


**Group Members**
| Name            | Entry Number |
| --------------- | ------------ |
| Aditya Aggarwal | 2020CSB1066  |
| Anubhav Kataria | 2020CSB1073  |
| Prakhar Saxena | 2020CSB1111  |
