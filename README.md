__RcppSimpleITK__ is an R-package using the C++ interface of **[SimpleITK](https://github.com/SimpleITK/SimpleITK)** (using Rcpp) to overcome the slow for loops in R. 

#### Install prerequisites ###

At the moment only Linux is supported, also OSX should work as well.

* **Linux:** Build SimpleITK (including R-wrapping) and install the SimpleITK R-package (as described [here](http://www.itk.org/Wiki/SimpleITK/GettingStarted#R_installation), CMake and R build environment.


##### Install *RcppSimpleITK* #####
Run the following command in R:
        
	require(devtools)
	install_github("zarquon42b/RcppSimpleITK", args="--configure-args=-DSimpleITK_DIR=path_to_your_SimpleITK_install_dir")
	

in my case the argument would be
	
	install_github("zarquon42b/RcppSimpleITK",args="--configure-args=-DSimpleITK_DIR=/home/schlager/GIT/DEV/SimpleITK-build/SimpleITK-build/")
	
