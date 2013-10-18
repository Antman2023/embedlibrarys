/*
	A message system for embed system
	Author	pathletboy
	Date	2013-10-18
*/

#include "message.h"

void InitMessage(struct ring_messages *ring_messages)
{
    ring_messages->head = ring_messages->tail = 0;
}

void SendMessage(struct ring_messages *ring_messages, char id, char param)
{
    unsigned char i = (ring_messages->head + 1) % MESSAGE_SIZE;
    if (i != ring_messages->tail)
    {
        ring_messages->message[ring_messages->head].id = id;
        ring_messages->message[ring_messages->head].param = param;
        ring_messages->head = i;
    }
}

char GetMessage(struct ring_messages *ring_messages, struct message *message)
{
    if (ring_messages->head == ring_messages->tail)
    {
        return 0;
    }
    else
    {
        *message = ring_messages->message[ring_messages->tail];
        ring_messages->tail = (ring_messages->tail + 1) % MESSAGE_SIZE;
        return 1;
    }
}