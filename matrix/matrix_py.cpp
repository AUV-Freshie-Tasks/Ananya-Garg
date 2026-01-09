#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include "matrix.h"

namespace py = pybind11;

PYBIND11_MODULE(matrix_py, m) {
    m.doc() = "Python bindings for Matrix class";

    py::class_<Matrix<double>>(m, "Matrix")
        .def(py::init<int, int>(),
             py::arg("rows") = 0,
             py::arg("cols") = 0)

        .def("__getitem__", [](const Matrix<double>& M,
                               std::pair<int,int> idx) {
            return M(idx.first, idx.second);
        })

        .def("__setitem__", [](Matrix<double>& M,
                               std::pair<int,int> idx,
                               double value) {
            M(idx.first, idx.second) = value;
        })

        .def("rows", [](const Matrix<double>& M) { return M.rows; })
        .def("cols", [](const Matrix<double>& M) { return M.cols; })
        .def("transpose", &Matrix<double>::transpose)

        .def(py::self + py::self)
        .def(py::self * py::self);
}

