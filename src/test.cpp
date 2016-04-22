#include "Rcpp.h"
#include "SimpleITK.h"
// //#include "test.h"
// extern "C" {
//   extern SEXP R_swig_Image_GetDimension ( SEXP self, SEXP s_swig_copy);
//   SEXP Image_GetDimension(SEXP image) {
//      try {
//       SEXP out = R_swig_Image_GetDimension(image, Rcpp::wrap(true));
//       return out;
//        } catch (std::exception& e) {
//        ::Rf_error( e.what());
//        } catch (...) {
//       ::Rf_error("unknown exception");
//       }
//   }
// }
namespace sitk = itk::simple;
using namespace Rcpp;
extern "C" {
extern itk::simple::Image * convertSwigSimpleITKImage( SEXP obj );
  SEXP mytest(SEXP img, SEXP origin_) {
    std::vector<double> origin = as<std::vector<double> >(origin_);
    sitk::Image * image = convertSwigSimpleITKImage(img);
    image->SetOrigin(origin);
  return img;
}
}
