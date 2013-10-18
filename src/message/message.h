#ifndef message_h
#define message_h
#define MESSAGE_SIZE 128
struct message
{
    unsigned char id;
    unsigned char param;
};

struct ring_messages
{
    struct message	message[MESSAGE_SIZE];
    volatile unsigned char head;
    volatile unsigned char tail;
};

void InitMessage(struct ring_messages *ring_messages);
void SendMessage(struct ring_messages *ring_messages, char id, char param);
struct message *GetMessage(struct ring_messages *ring_messages);

#endif