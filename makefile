CC = g++
LIBS = -lm 
SRC = cpps
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/acervo.o  $(OBJ)$(OBJ)/aluguel.o $(OBJ)/gerenciarAluguel.o $(OBJ)/livro.o $(OBJ)/sistema.o $(OBJ)/adm.o $(OBJ)/aluno.o $(OBJ)/gerenciarUsuario.o $(OBJ)/perfil_usuario.o

HDRS = $(INC)/acervo.hpp  $(INC)/aluguel.hpp $(INC)/gerenciarAluguel.hpp $(INC)/livro.hpp $(INC)/sistema.hpp $(INC)/adm.hpp $(INC)/aluno.hpp $(INC)/gerenciarUsuario.hpp $(INC)/perfil_usuario.hpp
CFLAGS = -g -Wall -c -I$(INC)

all: $(BIN)/sistema

$(BIN)/sistema: $(OBJS)
	$(CC) -o $(BIN)/sistema $(CFLAGS) $(OBJS)

$(OBJ)/acervo.o: $(SRC)/acervo.cpp $(INC)/acervo.hpp
	$(CC) -o $(OBJ)/acervo.o $(CFLAGS) $(SRC)/acervo.cpp

$(OBJ)/adm.o: $(SRC)/adm.cpp $(INC)/adm.hpp 
	$(CC) -o $(OBJ)/adm.o $(CFLAGS) $(SRC)/adm.cpp

$(OBJ)/aluguel.o: $(SRC)/aluguel.cpp $(INC)/aluguel.hpp $(INC)/aluguel.hpp
	$(CC) -o $(OBJ)/aluguel.o $(CFLAGS) $(SRC)/aluguel.cpp

$(OBJ)/aluno.o: $(SRC)/aluno.cpp $(INC)/aluno.hpp $(INC)/sistema.hpp
	$(CC) -o $(OBJ)/aluno.o $(CFLAGS) $(SRC)/aluno.cpp

$(OBJ)/gerenciarAluguel.o: $(SRC)/gerenciarAluguel.cpp $(INC)/gerenciarAluguel.hpp 
	$(CC) -o $(OBJ)/gerenciarAluguel.o $(CFLAGS) $(SRC)/gerenciarAluguel.cpp

$(OBJ)/gerenciarUsuario.o: $(SRC)/gerenciarUsuario.cpp $(INC)/gerenciarUsuario.hpp 
	$(CC) -o $(OBJ)/gerenciarUsuario.o $(CFLAGS) $(SRC)/gerenciarUsuario.cpp

$(OBJ)/livro.o: $(SRC)/livro.cpp $(INC)/livro.hpp 
	$(CC) -o $(OBJ)/livro.o $(CFLAGS) $(SRC)/livro.cpp

$(OBJ)/perfil_usuario.o: $(SRC)/perfil_usuario.cpp $(INC)/perfil_usuario.hpp $(INC)/aluno.hpp
	$(CC) -o $(OBJ)/perfil_usuario.o $(CFLAGS) $(SRC)/perfil_usuario.cpp

$(OBJ)/sistema.o: $(SRC)/sistema.cpp $(INC)/perfil_usuario.hpp $(INC)/aluno.hpp
	$(CC) -o $(OBJ)/sistema.o $(CFLAGS) $(SRC)/sistema.cpp

clean:
	rm -f $(OBJS) $(BIN)/sistema

