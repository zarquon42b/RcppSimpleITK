#' this a first test whether it is possible to call SimpleITK via Rcpp
#'
#' this a first test whether it is possible to call SimpleITK via Rcpp
#' @param image image of class
#' @return returns the image dimension
#' @examples
#' require(SimpleITK)
#' img <- Image(10,10,10,"sitkInt8")
#' print(GetImageDimension(img))
#' @useDynLib RcppSimpleITK
#' @importFrom Rcpp evalCpp
#' @importFrom SimpleITK Image
#' @export 
GetImageDimension <- function(image) {
    if (!inherits(image,"_p_itk__simple__Image"))
        stop("image must be a SimpleITK image")
    .Call("Image_GetDimension",image@ref)
}
