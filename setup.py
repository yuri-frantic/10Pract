from setuptools import setup, Extension
import pybind11

# Определение пути к заголовочным файлам Pybind11
pybind11_include = pybind11.get_include()

# Определение расширения
ext_modules = [
    Extension(
        'vector_algebra',
        ['vector_algebra.cpp'],
        include_dirs=[pybind11_include],
        language='c++'
    ),
]

# Настройка сборки
setup(
    name='vector_algebra',
    version='0.1',
    ext_modules=ext_modules,
    zip_safe=False,
)
