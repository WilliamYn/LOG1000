all: main.o client.o panier.o produit.o rayon.o
	g++ -o main main.o client.o panier.o produit.o rayon.o

main.o: main.cpp
	g++ -c main.cpp

client.o: client.cpp
	g++ -c client.cpp

panier.o: panier.cpp
	g++ -c panier.cpp

produit.o: produit.cpp
	g++ -c produit.cpp

rayon.o: rayon.cpp
	g++ -c rayon.cpp

clean:
	rm -rf *o main
