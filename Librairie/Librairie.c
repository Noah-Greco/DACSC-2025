#define TCP_H
#define TAILLE_MAX_DATA 10000
int ServerSocket(int port) 
{
 //Fait un appel à socket() pour créer la socket
 //construit l’adresse réseau de la socket par appel à getaddrinfo()
 //fait appel à bind() pour lier la socket à l’adresse réseau
 //fait appel à listen() pour démarrer la machine à états TCP
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
