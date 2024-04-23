SDL Build and installation:

first download SDL source code
create a libs folder in the current user folder, example:
C:\Users\maycon\libs
Extract the sdl zip file to 
C:\Users\maycon\libs\SDL
and run the following command inside the folder:
cmake -S . -B build
inside the build folder run:
cmake --build . --config Debug
and then open the terminal in Administrator mode, navigate to the build folder again and then run:
cmake --install . --config Debug
OR if you wanna change the path, just use the --prefix
cmake --install . --prefix C:\Users\maycon\libs
Apos esses passos o SDL deve ser instalado na pasta:
C:\Program Files (x86)\SDL2
faca o CMakeLists.txt do projeto crie o main.cpp
e prossiga com o build normalmente