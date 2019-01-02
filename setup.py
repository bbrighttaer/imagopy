import os
import sys
from distutils import sysconfig
from distutils.core import setup, Extension

cpp_args = ['-std=c++11']
sources = ['imagopy/core/' + str(file) for file in os.listdir('imagopy/core') if file.endswith('.cpp')] + \
          ['imagopy/cbinding/' + str(file) for file in os.listdir('imagopy/cbinding') if file.endswith('.cpp')]

ext_modules = [
    Extension(
        'imagopy',
        sources,
        include_dirs=['/usr/include/pybind11/include', 'imagopy/core', 'imagopy/cbinding', '/usr/include/boost',
                      '/usr/include', '/usr/include/opencv2'],
        language='c++',
        extra_compile_args=cpp_args,
        library_dirs=['/usr/lib', '/usr/lib/x86_64-linux-gnu', '/usr/local/lib', '/usr/include/boost/lib',
                      '/usr/include', '/usr/share', '/usr/include/opencv', '/usr/bin'],
        libraries=["opencv_features2d", "opencv_highgui", "opencv_core", "indigo",
                   "indigo-renderer", "boost_system", "boost_log", "boost_thread", "pthread"],
    )
]

setup(
    name='imagopy',
    version='0.0.1',
    author='bbrighttaer',
    author_email='brighteragyemang@gmail.com',
    description='Python wrapper for Imago OCR',
    ext_modules=ext_modules
)
