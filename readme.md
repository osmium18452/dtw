# DYNAMIC TIME WARPING

### EXPERIMENT OF MULTI-MEDIA

## INTRODUCT

This is the source code for homework 3: recognizing single word with 
Dynamic Time Warping. The code is modified from the code provided by 
Prof. Xie. I added tow functions in "recognition.h": CalculateDistance 
and Run_DTW. Some code in "recognition.cpp" is modified to realize some 
functions. 

The project is written with Clion so the structure of the project is 
automatically organized by the project. All source files are stored in 
"./" directory. Cmake files are stored in the "./cmake-build-debug" 
directory. Data files are stored in the directory you specified.

## RUN THE CODE

0. **[DOWMLOAD]** Clone the repository from my 
[github](https://github.com/osmium18452/dtw) or with the command 
`git clone git@github.com:osmium18452/dtw.git`.

1. **[COMPILE]** Below are methods compatible with Windows. 
    
    1. **Using Clion :** Please make sure your Cmake version is 3.15 or 
    newer. Compile the project with default settings is OK.
    
    2. **Using Command Line :** Change your directory to where the 
    `recognition.cpp` lies and using the command `g++ recognition.cpp -o 
    dtw.exe`.
    
    3. **Using Other IDE :** Change the settings according to your IDE
    requirement.

2. **[RUN THE CODE]** Below are methods compatible with Windows. You 
should pass the parameters through the command line. Use the format 
`dtw template_file_directory test_file_list_file result_file`. Out of 
some unknown reasons, please use the absolute path instead of the 
relative path (the latter may cause file_not_found error).
    
    1. **Using Clion :** Press `alt + shift + f10`, choose the 
    `configure` and add the three parameters in the box named 
