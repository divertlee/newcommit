.PHONY:all
all:server client

server:shm_server.cc
	g++ -o $@ $^ -std=c++11

client:shm_client.cc
	g++ -o $@ $^ -std=c++11
.PHONY:clean

clean:
	rm -rf server client
