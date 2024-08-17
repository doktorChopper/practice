EXE = demo

all: $(EXE)

$(EXE): server.cpp ../src/tcp_server.cpp
	g++ server.cpp ../src/tcp_server.cpp -o $(EXE)

debug: server.cpp ../src/tcp_server.cpp
	g++ -g3 server.cpp ../src/tcp_server.cpp -o $(EXE)

clean:
	rm -r demo
