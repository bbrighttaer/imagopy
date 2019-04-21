# ImagoPy
This is a python wrapper for [Imago OCR](https://github.com/ggasoftware/imago).
Its purpose is to facilitate the utilization of the Imago OCR APIs in
Python-based cheminformatic projects. A typical use case would be combining this wrapper
with [RDKit](https://rdkit.org) as demonstrated in [this tutorial](/example/imagopy.ipynb).

Requirements
------------
- Python 3.x
- C++ 11
- PyBind11 >=2.2.4
- Boost v1.49
- Indigo v1.1.12-2
- OpenCV v3.2.0
- pThread


Building & Installation
-----------------------
To build the shared binding:
1. `python setup.py clean`
2. `python setup.py build_ext`
3. `python setup.py install`

Usage
-----
Once the binding is installed, you import it like any other python
module.
```python
import imagopy as ocr # for accessing the Imago OCR APIs
sess_id = ocr.imagoAllocSessionId() # creates a session.
# perform some operations
ocr.imagoReleaseSessionId(sess_id) # closes the session
```
Please refer to Imago OCR [site](http://lifescience.opensource.epam.com/imago/c.html)
for information about the APIs.
