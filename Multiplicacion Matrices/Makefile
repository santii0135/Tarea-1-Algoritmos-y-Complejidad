# Define el compilador
CXX=g++

# Define las banderas de compilación
CXXFLAGS=-Wall -g

# Define el nombre del ejecutable
TARGET=main

# Define todos los objetos
OBJS=main.o Iterativo_cubico_optimizado.o Iterativo_cubico_tradicional.o

# Regla predeterminada para construir el programa
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Reglas para construir los objetos
main.o: main.cpp Matrices.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MergeSort.o: Iterativo_cubico_optimizado.cpp Matrices.h
	$(CXX) $(CXXFLAGS) -c Iterativo_cubico_optimizado.cpp

QuickSort.o: Iterativo_cubico_tradicional.cpp Matrices.h
	$(CXX) $(CXXFLAGS) -c Iterativo_cubico_tradicional.cpp

#SelectionSort.o: SelectionSort.cpp Matrices.h
#	$(CXX) $(CXXFLAGS) -c SelectionSort.cpp

# Regla para limpiar archivos temporales y ejecutable
clean:
	rm -f $(TARGET) $(OBJS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)
