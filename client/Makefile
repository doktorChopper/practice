EXE = demo

all: $(EXE)

$(EXE): client.cpp ../src/tcp_client.cpp
	g++ client.cpp ../src/tcp_client.cpp -o $(EXE)

debug: client.cpp ../src/tcp_client.cpp
	g++ -g3 client.cpp ../src/tcp_client.cpp -o $(EXE)

clean:
	rm -r demo
