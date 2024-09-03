# Define el compilador
CXX=g++

# Define las banderas de compilación
CXXFLAGS=-Wall -g

# Define el nombre del ejecutable
TARGET=main

# Define todos los objetos
OBJS=main.o MergeSort.o QuickSort.o SelectionSort.o

# Regla predeterminada para construir el programa
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Reglas para construir los objetos
main.o: main.cpp Ordenamiento.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MergeSort.o: MergeSort.cpp Ordenamiento.h
	$(CXX) $(CXXFLAGS) -c MergeSort.cpp

QuickSort.o: QuickSort.cpp Ordenamiento.h
	$(CXX) $(CXXFLAGS) -c QuickSort.cpp

SelectionSort.o: SelectionSort.cpp Ordenamiento.h
	$(CXX) $(CXXFLAGS) -c SelectionSort.cpp

# Regla para limpiar archivos temporales y ejecutable
clean:
	rm -f $(TARGET) $(OBJS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)
