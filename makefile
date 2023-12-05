CC = g++
LIBS = -lm 
SRC = cpps
OBJ = obj
INC = include
BIN = bin
TST = testes

OBJS = $(OBJ)/acervo.o  $(OBJ)/aluguel.o $(OBJ)/gerenciarAluguel.o $(OBJ)/livro.o $(OBJ)/sistema.o $(OBJ)/adm.o $(OBJ)/aluno.o $(OBJ)/gerenciarUsuario.o $(OBJ)/perfilUsuario.o

HDRS = $(INC)/acervo.hpp  $(INC)/aluguel.hpp $(INC)/gerenciarAluguel.hpp $(INC)/livro.hpp $(INC)/sistema.hpp $(INC)/adm.hpp $(INC)/aluno.hpp $(INC)/gerenciarUsuario.hpp $(INC)/perfilUsuario.hpp

EFLAGS = -g -Wall -I$(INC)

CFLAGS = -g -Wall -c -I$(INC)

run: $(BIN)/sistema
	$(BIN)/sistema

build: $(BIN)/sistema $(BIN)/livroteste $(BIN)/acervoteste $(BIN)/perfilUsuarioteste $(BIN)/gerenciarUsuarioteste $(BIN)/aluguelteste $(BIN)/gerenciarAluguelteste

test: $(BIN)/livroteste $(BIN)/acervoteste $(BIN)/perfilUsuarioteste $(BIN)/gerenciarUsuarioteste $(BIN)/aluguelteste $(BIN)/gerenciarAluguelteste
	$(BIN)/livroteste 
	$(BIN)/acervoteste 
	$(BIN)/perfilUsuarioteste 
	$(BIN)/gerenciarUsuarioteste 
	$(BIN)/aluguelteste 
	$(BIN)/gerenciarAluguelteste

$(BIN)/aluguelteste: $(OBJ)/aluguel.o $(TST)/aluguelteste.cpp
	$(CC) -o $(BIN)/aluguelteste $(EFLAGS) $(OBJ)/aluguel.o $(TST)/aluguelteste.cpp

$(BIN)/gerenciarAluguelteste: $(OBJ)/livro.o $(OBJ)/acervo.o $(OBJ)/gerenciarUsuario.o $(OBJ)/perfilUsuario.o $(OBJ)/adm.o $(OBJ)/aluno.o $(OBJ)/aluguel.o $(OBJ)/gerenciarAluguel.o $(TST)/gerenciarAluguelteste.cpp
	$(CC) -o $(BIN)/gerenciarAluguelteste $(EFLAGS) $(OBJ)/livro.o $(OBJ)/acervo.o $(OBJ)/aluno.o $(OBJ)/adm.o $(OBJ)/perfilUsuario.o $(OBJ)/gerenciarUsuario.o $(OBJ)/aluguel.o $(OBJ)/gerenciarAluguel.o $(TST)/gerenciarAluguelteste.cpp


$(BIN)/gerenciarUsuarioteste: $(OBJ)/gerenciarUsuario.o $(OBJ)/perfilUsuario.o $(OBJ)/adm.o $(OBJ)/aluno.o $(TST)/gerenciarUsuarioteste.cpp
	$(CC) -o $(BIN)/gerenciarUsuarioteste $(EFLAGS) $(OBJ)/aluno.o $(OBJ)/adm.o $(OBJ)/perfilUsuario.o $(OBJ)/gerenciarUsuario.o $(TST)/gerenciarUsuarioteste.cpp

$(BIN)/perfilUsuarioteste: $(OBJ)/aluno.o $(OBJ)/adm.o $(OBJ)/perfilUsuario.o $(TST)/perfilUsuarioteste.cpp
	$(CC) -o $(BIN)/perfilUsuarioteste $(EFLAGS) $(OBJ)/aluno.o $(OBJ)/adm.o $(OBJ)/perfilUsuario.o $(TST)/perfilUsuarioteste.cpp

$(BIN)/acervoteste: $(OBJ)/acervo.o $(OBJ)/livro.o $(TST)/acervoteste.cpp
	$(CC) -o $(BIN)/acervoteste $(EFLAGS) $(OBJ)/acervo.o $(OBJ)/livro.o $(TST)/acervoteste.cpp

$(BIN)/livroteste: $(OBJ)/livro.o $(TST)/livroteste.cpp
	$(CC) -o $(BIN)/livroteste $(EFLAGS) $(OBJ)/livro.o $(TST)/livroteste.cpp

$(BIN)/sistema: $(OBJS) $(SRC)/main.cpp
	$(CC) -o $(BIN)/sistema $(EFLAGS) $(OBJS) $(SRC)/main.cpp

$(OBJ)/acervo.o: $(SRC)/acervo.cpp $(INC)/acervo.hpp
	$(CC) -o $(OBJ)/acervo.o $(CFLAGS) $(SRC)/acervo.cpp

$(OBJ)/adm.o: $(SRC)/adm.cpp $(INC)/adm.hpp 
	$(CC) -o $(OBJ)/adm.o $(CFLAGS) $(SRC)/adm.cpp

$(OBJ)/aluguel.o: $(SRC)/aluguel.cpp $(INC)/aluguel.hpp 
	$(CC) -o $(OBJ)/aluguel.o $(CFLAGS) $(SRC)/aluguel.cpp

$(OBJ)/aluno.o: $(SRC)/aluno.cpp $(INC)/aluno.hpp $(INC)/sistema.hpp
	$(CC) -o $(OBJ)/aluno.o $(CFLAGS) $(SRC)/aluno.cpp

$(OBJ)/gerenciarAluguel.o: $(SRC)/gerenciarAluguel.cpp $(INC)/gerenciarAluguel.hpp 
	$(CC) -o $(OBJ)/gerenciarAluguel.o $(CFLAGS) $(SRC)/gerenciarAluguel.cpp

$(OBJ)/gerenciarUsuario.o: $(SRC)/gerenciarUsuario.cpp $(INC)/gerenciarUsuario.hpp 
	$(CC) -o $(OBJ)/gerenciarUsuario.o $(CFLAGS) $(SRC)/gerenciarUsuario.cpp

$(OBJ)/livro.o: $(SRC)/livro.cpp $(INC)/livro.hpp 
	$(CC) -o $(OBJ)/livro.o $(CFLAGS) $(SRC)/livro.cpp

$(OBJ)/perfilUsuario.o: $(SRC)/perfilUsuario.cpp $(INC)/perfilUsuario.hpp $(INC)/aluno.hpp
	$(CC) -o $(OBJ)/perfilUsuario.o $(CFLAGS) $(SRC)/perfilUsuario.cpp

$(OBJ)/sistema.o: $(SRC)/sistema.cpp $(HDRS)
	$(CC) -o $(OBJ)/sistema.o $(CFLAGS) $(SRC)/sistema.cpp

clean:
	rm -f $(OBJS) $(BIN)/*

$(shell mkdir -p $(BIN))
$(shell mkdir -p $(OBJ))
