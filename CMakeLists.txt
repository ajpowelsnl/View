cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(KokkosView CXX)

set(CUDA_ROOT /home/projects/x86-64/cuda/12.0)
set(Kokkos_ROOT $HOME/view_for_documentation/kokkos_install_cuda)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Kokkos 4.1 REQUIRED)

add_executable(view view.cpp)

target_link_libraries(view PRIVATE Kokkos::kokkos)


