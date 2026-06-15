CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -MMD -MP

TARGET = analisador

SRCS = AnalisadorLexico.cpp \
       ErroLexico.cpp \
       MaquinaMoore.cpp \
       Main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Lógica para extrair os argumentos que vêm após os comandos make e convertê-los
ifeq (run,$(firstword $(MAKECMDGOALS)))
  INPUT_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(INPUT_ARGS):;@:)
endif
ifeq (valgrind,$(firstword $(MAKECMDGOALS)))
  INPUT_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(INPUT_ARGS):;@:)
endif
ifeq (full,$(firstword $(MAKECMDGOALS)))
  INPUT_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(INPUT_ARGS):;@:)
endif
ifeq (valgrind-full,$(firstword $(MAKECMDGOALS)))
  INPUT_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(INPUT_ARGS):;@:)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@if [ -z "$(INPUT_ARGS)" ]; then echo "Erro: Arquivo não especificado. Uso: make run <arquivo>"; exit 1; fi
	@./$(TARGET) $(INPUT_ARGS)

valgrind: $(TARGET)
	@if [ -z "$(INPUT_ARGS)" ]; then echo "Erro: Arquivo não especificado. Uso: make valgrind <arquivo>"; exit 1; fi
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) $(INPUT_ARGS)

full:
	@if [ -z "$(INPUT_ARGS)" ]; then echo "Erro: Arquivo não especificado. Uso: make full <arquivo>"; exit 1; fi
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@./$(TARGET) $(INPUT_ARGS)
	@rm -f $(TARGET) *.o *.d

valgrind-full:
	@if [ -z "$(INPUT_ARGS)" ]; then echo "Erro: Arquivo não especificado. Uso: make valgrind-full <arquivo>"; exit 1; fi
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) $(INPUT_ARGS)
	@rm -f $(TARGET) *.o *.d

clean:
	@rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)

.PHONY: all run valgrind full valgrind-full clean