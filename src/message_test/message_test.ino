#include <message.h>
#define WM_SERIAL 0
struct ring_messages ring_messages;
void setup()
{
    InitMessage(&ring_messages);
    Serial.begin(9600);
}

struct message *message;
void loop()
{
    if (Serial.available())
    {
        SendMessage( &ring_messages, WM_SERIAL, Serial.read());
    }
    message = GetMessage(&ring_messages);
    if (message)
    {
        switch (message->id)
        {
        case WM_SERIAL:
            Serial.write("got a message");
            Serial.write(message->param);
            break;
        }
    }
}

