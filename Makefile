include /usr/local/etc/PcapPlusPlus.mk

# All Target
all:
	g++ $(PCAPPP_INCLUDES) -c -o main.o main.cpp
	g++ $(PCAPPP_LIBS_DIR) -static-libstdc++ -o Practice main.o $(PCAPPP_LIBS)

# Clean Target
clean:
	rm main.o
	rm Tutorial-HelloWorld

