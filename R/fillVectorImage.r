#' this a first test whether it is possible to call SimpleITK via Rcpp
#'
#' this a first test whether it is possible to call SimpleITK via Rcpp. It simply shows how to change the origin of a sitk::Image using SimpleITK's C++ interface.
#' @param image image of class
#' @param vector of length
#' @return returns the image dimension
#' @examples
#' require(SimpleITK)
#' img <- Image(10,10,10,"sitkVectorFloat32")
#' indices <- as.matrix(expand.grid(1:10,1:10,1:10))
#' set.seed(42)
#' values <- matrix(rnorm(3000),1000,3)
#' img <- fillVectorImage(img,indices,values)
#' stopifnot(all.equal(img[1,1,1],values[1,]))
#' @useDynLib RcppSimpleITK
#' @importFrom Rcpp evalCpp
#' @import SimpleITK
#' @export 
fillVectorImage <- function(image,indices,values) {
    if (!inherits(image,"_p_itk__simple__Image"))
        stop("image must be a SimpleITK image")
    imdim <- image$GetDimension()
    
    indices <- as.matrix(indices-1L)
    indrange <- apply(indices,2,max)
    imgsize <- image$GetSize()
    if (sum(indrange+1 > imgsize))
        stop("indices out of range")
    
    ref <- .Call("fillVectorImage",image@ref,indices,values)
    image@ref <- ref
    return(image)
}

#' convert an object of class DisplacementGrid to deformation field
#'
#' convert an object of class DisplacementGrid to deformation field created by mesheR::displacementField2Grid
#' @param x object of class DisplacementGrid
#' @return a sitk::Image<sitkVectorFloat32>
#' @export
displacementGrid2Transform <- function(x) {
    if (!inherits(x,"DisplacementGrid"))
        stop("x must be of class DisplacementGrid")
    attribs <- attributes(x)
    img <- SimpleITK::Image(attribs$arraydim[1],attribs$arraydim[2],attribs$arraydim[3],"sitkVectorFloat32")
    inds <- attribs$indices
    img <- fillVectorImage(img,inds,x$DisplacementField)
    img$SetSpacing(attribs$spacing)
    img$SetOrigin(attribs$origin)
    return(img)
}
