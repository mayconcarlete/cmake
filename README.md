# cmake
## https://www.udemy.com/course/cmake-tests-and-tooling-for-cc-projects/
RUN WINDOWS COMPILER
MSBuild.exe Nome_Projecto.sln

## step by step compilation:
### create the code(main.cpp) and a CMakeLists.txt file
### create a folder called build (mkdir build)
### cd build
### cmake ..
### cmake --build .
### ./Executable

### Podemos tambem fazer o build de uma parte especifica do codigo(como um build de uma library por exemplo, basta: cmake --build . --target NOME  ex: Library)

para fazer o build da library
cmake --build . --config Debug

sudo cmake --install . --config Debug

