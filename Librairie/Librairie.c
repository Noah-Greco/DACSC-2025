#define Librairie.h
#define TAILLE_MAX_DATA 10000
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "librairie.h"

int ServerSocket(int port) 
{
    int sckt_serveur;
 //Fait un appel à socket() pour créer la socket
  sckt_serveur = socket(AF_INET , SOCK_STREAM , 0); //0 veut dire que l'os prendra le protocol adapté lui mm 
  if(sckt_serveur < 0 )//Erreur de socket se teste par < 0 et pas == 
  {
    perror("Erreur de socket()");
    exit(1);
  }
   printf("socket creee = %d\n",sckt_serveur);

 //construit l’adresse réseau de la socket par appel à getaddrinfo()
 struct addrinfo hints;
 struct addrinfo *results;
 memset(&hints,0,sizeof(struct addrinfo));
 hints.ai_family = AF_INET; //IPV4
 hints.ai_socktype = SOCK_STREAM;//TCP
 hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV; // pour une connexion passive
 if (getaddrinfo(NULL,port,&hints,&results) != 0)//null veut dire nimp quelle ip
 {
    close(sckt_serveur);
    exit(1);
 } 
 //fait appel à bind() pour lier la socket à l’adresse réseau
 if (bind(sckt_serveur,results->ai_addr,results->ai_addrlen) < 0)
 {
    perror("Erreur de bind()");
    exit(1);
 }
 freeaddrinfo(results);
 printf("bind() reussi !\n");
 pause();

 //fait appel à listen() pour démarrer la machine à états TCP
 if(listen(sckt_serveur,500)== -1)
 {
     perror("Erreur de listen()");
     exit(1);
 }
  printf("listen reussis");
}
int Accept(int sckt_serveur,char *ipClient)
{ 
    int sckt_Service
 //Fait appel à accept()
 if(sckt_Service=accept(sckt_serveur,NULL,NULL) == -1)
 {
     perror("Erreur de accepte");
     exit(1);
 }
 //Recupérer l'ip du client qui vient de se connecter dans ipClient si c'est non NULL, si c'est NULL pointer vers une zone mémoire capable de recevoir une chaine de cara de la taille de l'ip
 struct sockaddr_in adrClient;
 socklen_t adrClientLen = sizeof(struct sockaddr_in); // nécessaire
 getpeername(sckt_Service,(struct sockaddr*)&adrClient,&adrClientLen);
 getnameinfo((struct sockaddr*)&adrClient,adrClientLen,
 host,NI_MAXHOST,
 port,NI_MAXSERV,
 NI_NUMERICSERV | NI_NUMERICHOST);
 printf("Client connecte --> Adresse IP: %s -- Port: %s\n",host,port);
 pause();

}
int ClientSocket(char* ipServeur,int portServeur)
{
 //Fait appel à socket() pour créer la socket
 //construit l’adresse réseau de la socket (avec l’IP et le port du serveur) par appel à la fonction getaddrinfo()
 //fait appel à connect() pour se connecter sur le serveur
}
int Send(int sSocket,char* data,int taille)
{
 //Envoie de donnée comme dans exemple du cours
}
int Receive(int sSocket,char* data);
{
 //Reception de donnée comme dans les exemple du cours 
}
