cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(KokkosView CXX)

#TODO:
# Set Kokkos_ROOT (path to kokkos installation point
# Set the ROOT / PATH to the desired backend SDK

set(Kokkos_ROOT /g/g20/powell56/view_for_documentation/kokkos_install_hip)
#set(CUDA_ROOT /home/projects/x86-64/cuda/12.0)
set(ROCM_PATH /opt/rocm-5.7.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Kokkos 4.1 REQUIRED)

add_executable(view view.cpp)

target_link_libraries(view PRIVATE Kokkos::kokkos)


