Visual Studio 17 2022

1 - add git to your environment path  C:\Program Files\Git\bin
2 - same for cmake(you can set direct through installer) - C:\Program Files\CMake\bin
3 - add msbuild - C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin
4 - cmake -S . -B build/ -G "Visual Studio 17 2022"

5 - go to build folder
6 - MSBuild SDL_TEST.sln


Tutorial to build SDL
cmake -G "Visual Studio 17 2022" -A Win32 -S \path_to_source\ -B "build32"
cmake -G "Visual Studio 17 2022" -A x64 -S \path_to_source\ -B "build64"
cmake --build build32 --config Release
cmake --build build64 --config Release

OU

MSBuild.exe .\build\<NAME_PROJECT>.sln

libs\sdl\build64\SDL2Config.cmake