#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <string.h>

int main(int argc, char* argv[])
{
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	/* Setting up socket */

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if(sockfd < 0)
	{
		perror("ERROR opening socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 4444;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	/* Bind */

	if(bind(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("ERROR on binding");
		exit(1);
	}

	clilen = sizeof(cli_addr);

	/* Listen */
	/*
	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	*/

	/* Accept */

	/*
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	if(newsockfd < 0)
	{
		perror("ERROR on accept");
		exit(1);
	}
	*/

	/* Start communicating */
	/*
	bzero(buffer,256);
	n = read(newsockfd, buffer, 255);

	if (n < 0)
	{
		perror("ERROR reading from socket");
		exit(1);
	}

	printf("Here is the message: %s\n",buffer);
	*/
	/* Write response */	
	/*
	n = write(newsockfd, "I got your message", 18);

	if (n < 0)
	{
		perror("ERROR writing to socket");
		exit(1);
	}
	*/

	while(1)
	{
		n = recvfrom(sockfd, buffer, strlen(buffer), 0, (struct sockaddr* ) &cli_addr, &clilen);
		printf("%s\n",buffer);
	}

	return 0;
}
