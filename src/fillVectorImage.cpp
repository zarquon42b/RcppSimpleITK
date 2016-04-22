#include "RcppSimpleITK.h"

RcppExport  SEXP fillVectorImage(SEXP img, SEXP indices_, SEXP vectors_) {
  try {
    sitk::Image * image = convertSwigSimpleITKImage(img);
    *image = sitk::Cast(*image, sitk::sitkVectorFloat32);
    IntegerMatrix indices(indices_);
    NumericMatrix vectors(vectors_);
    if (indices.nrow() != vectors.nrow())
      ::Rf_error("indices and values must have the same amount of rows");

    if (vectors.ncol() != image->GetNumberOfComponentsPerPixel())
      ::Rf_error("vector length must correspond to image's number of components");
    for (int i = 0; i < indices.nrow();i++) {
      IntegerVector tmpind = indices(i,_);
      std::vector<uint32_t> tmpindi = as<std::vector<uint32_t> >(tmpind);
      NumericVector tmpvec = vectors(i,_);
      std::vector<float> tmpvecf = as<std::vector<float> >(tmpvec);
      image->SetPixelAsVectorFloat32(tmpindi,tmpvecf);
    }
      
    return img;
  } catch (std::exception& e) {
    ::Rf_error( e.what());
  } catch (...) {
    ::Rf_error("unknown exception");
  }
}
