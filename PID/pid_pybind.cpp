#include <pybind11/pybind11.h>
#include "p.h"
#include "i.h"
#include "d.h"
#include "pid.h"

namespace py = pybind11;

PYBIND11_MODULE(pidlib, m) {

    py::class_<P>(m, "P")
        .def(py::init<double>())
        .def("out", &P::out);

    py::class_<I>(m, "I")
        .def(py::init<double>())
        .def("reset", &I::reset)
        .def("out", &I::out);

    py::class_<D>(m, "D")
        .def(py::init<double>())
        .def("out", &D::out);

    py::class_<PID>(m, "PID")
        .def(py::init<double, double, double>())
        .def("reset", &PID::reset)
        .def("out", &PID::out);
}

