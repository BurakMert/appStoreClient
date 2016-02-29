CC = g++ -std=c++11
CFLAGS = $(shell pkg-config dbus-1 --cflags)
LDFLAGS = -ldbus-1 -lcurl -lcrypto -lssl

all:
	$(CC) -o downloader main.cpp HTTPPerform.cpp cJSON.c $(LDFLAGS) $(CFLAGS)

clean:
	rm downloader