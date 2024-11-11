TARGET = dashboard

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Arquivos fonte e objetos
SOURCES = main.cpp model.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão
all: $(TARGET)
	rm -f main
# Como gerar o executável a partir dos objetos
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
$(SOURCES):
	$(CXX) $(CXXFLAGS) -c $@
run:
	./$(TARGET)
# Limpeza
clean:
	rm -f $(OBJECTS) $(TARGET)