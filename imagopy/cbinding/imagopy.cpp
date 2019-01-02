#include <pybind11/pybind11.h>
#include "imago_c.h"

namespace py = pybind11;

using namespace pybind11::literals;

std::tuple<int, int> imagoRecognizeMolecule() {
    int warnings = 0;
    return std::make_tuple(imagoRecognize(&warnings), warnings);

};

PYBIND11_PLUGIN(imagopy) {
    py::module m("imagopy", "This is a python wrapper for the EPAM Imago OCR tool."
                            "Please, visit http://lifescience.opensource.epam.com/imago/ for details of Imago OCR.");

    m.def("imagoGetVersion",
          &imagoGetVersion,
          "Get the version of Imago");

    m.def("imagoGetLastError",
          &imagoGetLastError,
          "Get the last error message. This can be called if some other function returned zero value.");

    m.def("imagoAllocSessionId",
          &imagoAllocSessionId,
          "Allocate an instance. All instances are independent, that is, they have separate images, "
          "configurations settings, resulting molfiles, and error messages. Using Imago library without "
          "allocation an instance will cause an error.");

    m.def("imagoSetSessionId",
          &imagoSetSessionId,
          "Set the ID of the instance you are working with from current thread.");

    m.def("imagoReleaseSessionId",
          &imagoReleaseSessionId,
          "Release a previously allocated instance.");

    m.def("imagoSetConfig",
          &imagoSetConfig,
          "Set one of predefined configuration sets. The given name should be selected from "
          "imagoGetConfigsList() results. Empty string as parameter means config auto-detection.");

    m.def("imagoGetConfigsList",
          &imagoGetConfigsList,
          "Get the list of available predefined configuration sets separated by comma.");

    m.def("imagoSetFilter",
          &imagoSetFilter,
          "Choose the filter to process image before call imagoFilterImage() name can be "
          "\"prefilter_binarized\", \"prefilter_basic\", or something else. For the exact "
          "information see the filters_list.cpp file. By default, filter from current config will be used.");

    m.def("imagoLoadImageFromBuffer",
          &imagoLoadImageFromBuffer,
          "Image loading functions.");

    m.def("imagoLoadImageFromFile",
          &imagoLoadImageFromFile,
          "Image loading functions.");

    m.def("imagoSaveImageToFile",
          &imagoSaveImageToFile,
          "PNG image saving function.");

    m.def("imagoLoadGreyscaleRawImage",
          &imagoLoadGreyscaleRawImage,
          "Load raw grayscale image - byte array of length width*height.");

    m.def("imagoSetLogging",
          &imagoSetLogging,
          "Enable or disable global log printing. Modes are: 0 - disabled, "
          "1 - enable log to file, 2 - enable log to virtual fs.\nWARNING: affects all threads/IDS");

    m.def("imagoSetSessionSpecificData",
          &imagoSetSessionSpecificData,
          "Attach some arbitrary data to the current Imago instance.");

    m.def("imagoRecognize",
          &imagoRecognizeMolecule,
          "Main recognition routine. Image must be loaded & filtered previously. "
          "Returns a tuple of execution flag and count of recognition warnings in "
          "warningsCountDataOut value (if specified)");

    m.def("imagoSaveMolToFile",
          &imagoSaveMolToFile,
          "Molfile (.mol) output functions.");

    m.def("imagoFilterImage",
          &imagoFilterImage,
          "Process image filtering.");

    m.def("imagoGetInkPercentage",
          &imagoGetInkPercentage,
          "Returns filtered image ink percentage (0.0 .. 1.0)");

    m.def("imagoGetPrefilteredImageSize",
          &imagoGetPrefilteredImageSize,
          "Returns filtered image dimensions");

    m.def("imagoGetLogCount",
          &imagoGetLogCount,
          "Returns count of files contained in log vfs.");

    m.def("imagoClearLog",
          &imagoClearLog,
          "Clears all current vfs log content");

//    m.def("imagoSaveMolToBuffer",
//          &imagoSaveMolToBuffer,
//          "Molfile (.mol) output functions.");

//    m.def("imagoGetPrefilteredImage",
//          &imagoGetPrefilteredImage,
//          "Returns filtered image data");

//    m.def("imagoGetLogRecord",
//          &imagoGetLogRecord,
//          "Returns it's file name, length and content");

    return m.ptr();
}