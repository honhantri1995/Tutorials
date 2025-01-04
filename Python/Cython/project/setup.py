from setuptools import find_packages, setup
from setuptools.extension import Extension

from Cython.Build import cythonize
from Cython.Distutils import build_ext

setup(
    name="myapp",
    version='0.100',
    ext_modules = cythonize(
        [
            Extension("app.some_package.some_classes", 
                ["app/some_package/some_classes.py"]),
        ],
        build_dir="build_cythonize",
        compiler_directives={
            'language_level' : "3",
            'always_allow_keywords': True,
        }
    ),
    cmdclass=dict(
        build_ext=build_ext
    ),
)