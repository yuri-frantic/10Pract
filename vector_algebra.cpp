#include <pybind11/pybind11.h>
#include <cmath>
#include <vector>

namespace py = pybind11;

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double len = length();
        if (len == 0) throw std::runtime_error("Cannot normalize a zero-length vector");
        return Vector3D(x / len, y / len, z / len);
    }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
};

PYBIND11_MODULE(vector_algebra, m) {
    py::class_<Vector3D>(m, "Vector3D")
        .def(py::init<double, double, double>())
        .def("length", &Vector3D::length)
        .def("normalize", &Vector3D::normalize)
        .def("__add__", &Vector3D::operator+)
        .def("__sub__", &Vector3D::operator-)
        .def("dot", &Vector3D::dot)
        .def("__repr__", [](const Vector3D &v) {
            return "<Vector3D (" + std::to_string(v.x) + ", " +
                   std::to_string(v.y) + ", " + std::to_string(v.z) + ")>";
        });
}

