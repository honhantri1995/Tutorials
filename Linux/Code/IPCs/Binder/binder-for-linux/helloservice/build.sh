clear

echo "Building server and client"
rm -f server
rm -f client
g++ -std=c++11 -o IHelloService.o -c -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 IHelloService.cpp -lbinder -lpthread


g++ -std=c++11 -o BpHelloService.o -c -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 BpHelloService.cpp -lbinder -lpthread

g++ -std=c++11 -o BnHelloService.o -c -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 BnHelloService.cpp -lbinder -lpthread

g++ -std=c++11 -o HelloService.o -c -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 HelloService.cpp -lbinder -lpthread


g++ -std=c++11 -o server -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 server.cpp IHelloService.o BnHelloService.o BpHelloService.o HelloService.o -lbinder -lpthread

g++ -std=c++11 -o client -I. -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 client.cpp IHelloService.o  BpHelloService.o  -lbinder -lpthread

echo "Done"

rm -f *.o
