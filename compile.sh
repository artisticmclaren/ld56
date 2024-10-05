echo "Compiling for Linux..."
g++ -std=c++17 -o ld56 src/*.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
echo "Compiling for Windows..."
i686-w64-mingw32-g++ -std=c++17 -o ld56.exe src/main.cpp -I/raylib-win/include -L/raylib-win/lib -lraylib -lopengl32 -lgdi32 -lwinmm
