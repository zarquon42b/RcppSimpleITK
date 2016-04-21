#include "Rcpp.h"
//#include "test.h"
extern "C" {
  extern SEXP R_swig_Image_GetDimension ( SEXP self, SEXP s_swig_copy);
  SEXP Image_GetDimension(SEXP image) {
     try {
      SEXP out = R_swig_Image_GetDimension(image, Rcpp::wrap(true));
      return out;
       } catch (std::exception& e) {
       ::Rf_error( e.what());
       } catch (...) {
      ::Rf_error("unknown exception");
      }
  }
}
