#pragma once

#include <stdlib.h>
#include <unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "ack.h"
#include "packet.h"
#define MAX_BUFFER_NUMBER 256 //sequence/frame number start from 0, 1 frame 9 bytes

typedef struct {
	uint32_t LFS;
	uint32_t LAR;
	uint32_t max_size;
	uint32_t current_size;
} senderWindow;

senderWindow makeWindow(uint32_t maxSize);
void putPacketToBuffer(int sockfd);
void sendPacket(uint32_t seqnum, int sockfd, struct sockaddr_in server_addr, char data);