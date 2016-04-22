#include "RcppSimpleITK.h"



RcppExport  SEXP mytest(SEXP img, SEXP origin_) {
  try {
    std::vector<double> origin = as<std::vector<double> >(origin_);
    sitk::Image * image = convertSwigSimpleITKImage(img);
    image->SetOrigin(origin);
    return img;
  } catch (std::exception& e) {
    ::Rf_error( e.what());
  } catch (...) {
    ::Rf_error("unknown exception");
  }
}


