#include "RcppSimpleITK.h"



RcppExport  SEXP mytest(SEXP img, SEXP origin_) {
    std::vector<double> origin = as<std::vector<double> >(origin_);
    sitk::Image * image = convertSwigSimpleITKImage(img);
    image->SetOrigin(origin);
  return img;
}

