LIBRARIES = -L/home/burakmert/Projects/MMIS/NFS_ROOTS/4/lib
DBUS_INCLUDE = -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
GNU_INCLUDE = -I/usr/include/x86_64-linux-gnu
ROOTFS_INCLUDE = -I/home/burakmert/Projects/MMIS/NFS_ROOTS/4/usr/include
INCLUDE_DIRS =  $(GNU_INCLUDE) $(ROOTFS_INCLUDE) $(DBUS_INCLUDE)
LDFLAGS += -ldbus-1 -lcurl -lcrypto -lssl -lpthread 

all:
	$(CXX) -std=c++11 -o downloader main.cpp HTTPPerform.cpp cJSON.c $(INCLUDE_DIRS) $(LIBRARIES) $(LDFLAGS)

clean:
	rm -f downloader