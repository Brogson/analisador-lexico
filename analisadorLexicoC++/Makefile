CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -MMD -MP

TARGET = analisador
INPUT = teste.txt

SRCS = AnalisadorLexico.cpp \
       ErroLexico.cpp \
       MaquinaMoore.cpp \
       main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@./$(TARGET) $(INPUT)

valgrind: $(TARGET)
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(TARGET) $(INPUT)

full:
	@$(CXX) $(CXXFLAGS) *.cpp -o $(TARGET)
	@./$(TARGET) $(INPUT)
	@rm -f $(TARGET) *.o *.d

valgrind-full:
	@$(CXX) $(CXXFLAGS) *.cpp -o $(TARGET)
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(TARGET) $(INPUT)
	@rm -f $(TARGET) *.o *.d

clean:
	@rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)

.PHONY: all run valgrind full valgrind-full clean