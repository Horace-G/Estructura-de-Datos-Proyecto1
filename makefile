tda:	main.o integer.o linkedlist.o object.o tdalist.o dllnode.o farraylist.o varraylist.o
	g++ main.o integer.o dllnode.o linkedlist.o object.o tdalist.o varraylist.o farraylist.o -o tda
main.o:	main.cpp tdalist.h linkedlist.h integer.h
	g++ -c main.cpp
integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp
dllnode.o:	dllnode.cpp dllnode.h
	g++ -c dllnode.cpp
tdalist.o:	tdalist.h tdalist.cpp object.h
	g++ -c tdalist.cpp
linkedlist.o:	linkedlist.cpp linkedlist.h tdalist.h object.h
	g++ -c linkedlist.cpp
object.o:	object.h object.cpp
	g++ -c object.cpp
varraylist.o:	varraylist.cpp varraylist.h object.h tdalist.h
	g++ -c varraylist.cpp
farraylist.o:	farraylist.cpp farraylist.h object.h tdalist.h
	g++ -c farraylist.cpp
clean:
	rm *.o tda
