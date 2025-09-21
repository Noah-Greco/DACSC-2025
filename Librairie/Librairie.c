#define TCP_H
#define TAILLE_MAX_DATA 10000
#include <sys/types.h>
#include <sys/socket.h>

int ServerSocket(int port) 
{
    int sckt_serveur;
 //Fait un appel à socket() pour créer la socket
  sckt_serveur = socket(AF_INET , SOCK_STREAM , 0); //0 veut dire que l'os prendra le protocol adapté lui mm 
  if(sckt == 0 )
  {
    perror("Erreur de socket()");
    exit(1);
  }
   printf("socket creee = %d\n",sckt_serveur);

 //construit l’adresse réseau de la socket par appel à getaddrinfo()
 struct addrinfo hints;
 struct addrinfo *results;
 memset(&hints,0,sizeof(struct addrinfo));
 hints.ai_family = AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV; // pour une connexion passive
 if (getaddrinfo(NULL,"50000",&hints,&results) != 0)//null veut dire nimp quelle ip
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
int Accept(int sEcoute,char *ipClient)
{
 //Fait appel à accept()
 //Recupérer l'ip du client qui vient de se connecter dans ipClient si c'est non NULL, si c'est NULL pointer vers une zone mémoire capable de recevoir une chaine de cara de la taille de l'ip
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
