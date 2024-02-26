#include <iostream>

#include <Kokkos_Core.hpp>



int main(int argc, char** argv) {

    // Initialize Kokkos
    Kokkos::initialize(argc,argv);

// Scope the Kokkos computation in `main`

{

   const int numRows = 500;
   const int numCols = 1000;

     // See tutorial Exercise 03
     // Allocate 1D, 2D Views on device
     
    // Create custom types
		typedef Kokkos::View<int*> ViewVectorType;
		typedef Kokkos::View<int**> ViewMatrixType;
    
    // Device Views using custom types
    ViewVectorType d_numRowsView ("gpu_numRowsView", numRows);
    ViewVectorType d_numColsView ("gpu_numColsView", numCols);
    ViewMatrixType d_matrixView ("gpu_matrixView", numRows, numCols);

		// Create host mirrors on device Views
		ViewVectorType::HostMirror h_numRowsView = Kokkos::create_mirror_view(d_numRowsView);
		ViewVectorType::HostMirror h_numColsView = Kokkos::create_mirror_view(d_numColsView);
    ViewMatrixType::HostMirror h_matrixView = Kokkos::create_mirror_view(d_matrixView);

    // Initialize h_numRows on host
    for (int i=0; i < numRows; ++i) {
			h_numRowsView(i) = i * 1;
    }

    // Initialize h_numCols on host
    for (int j=0; j < numCols; ++j) {
			h_numColsView(j) = j * 2;
    }


    // Initialize h_matrixView on host
    for (int i = 0; i < numRows; i++) {
			for(int j = 0; j < numCols; j++){
					h_matrixView(i,j) = i * numCols + (j + numRows);
          //std::cout << h_matrixView(i,j) << " " << std::endl;
          }
       }

   // Timer
   Kokkos::Timer timer;
 
	// deep_copy initialized host views to device
  Kokkos::deep_copy(d_numRowsView, h_numRowsView);
  Kokkos::deep_copy(d_numColsView, h_numColsView);
  Kokkos::deep_copy(d_matrixView, h_matrixView);

  double useconds = timer.seconds()/1000000;

  std::cout << " Deep copying data from CPU to GPU:  " << useconds << std::endl; 
   

    // Fence so you deallocation does not happen after finalize 
    Kokkos::fence();
}

    // Finalize Kokkos
    Kokkos::finalize();

    return 0;
}
