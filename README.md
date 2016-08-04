__RcppSimpleITK__ is an R-package using the C++ interface of **[SimpleITK](https://github.com/SimpleITK/SimpleITK)** (using Rcpp) to overcome the slow for loops in R. 

#### Install prerequisites ###

At the moment only Linux is supported, also OSX should work as well.

* **Linux:** Build SimpleITK (including R-wrapping) and install the SimpleITK R-package (as described [here](http://www.itk.org/Wiki/SimpleITK/GettingStarted#R_installation), CMake and R build environment.

If you build SimpleITK as root with `CMAKE_INSTALL_PREFIX=/usr/local`, you can build the package globally and skip passing the args below.


#### Install *RcppSimpleITK* ####

##### via devtools from within R

Run the following command in R:
        
	require(devtools)
	install_github("zarquon42b/RcppSimpleITK", args="--configure-args=-DSimpleITK_DIR=path_to_your_SimpleITK_install_dir")
	

On my machine, the argument would be
	
	install_github("zarquon42b/RcppSimpleITK",args="--configure-args=-DSimpleITK_DIR=/home/schlager/GIT/DEV/SimpleITK-build/SimpleITK-build/")
	
##### via command line #####
Get the source, either by cloning this repo or downloading the tarball and then issueing in a terminal

	R CMD INSTALL --configure-args="-DSimpleITK_DIR=path_to_your_SimpleITK_install_dir" RcppSimpleITK[*.tar.gz]

	
