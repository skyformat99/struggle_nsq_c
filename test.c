
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "sub_client.h"

int msg_callback_m(struct NSQMessage *msg){

}

int main()
{
    int sock;
    sock =  connect_nsqd_with_lookupd("127.0.0.1", "4150");
    struct NSQMessage *msg;
    msg = (struct NSQMessage *)malloc(sizeof(struct NSQMessage));
    msg->topic = "test";
    msg->channel = "struggle";
    int (*msg_callback)(struct NSQMessage *msg) = msg_callback_m;
    subscribe(sock, msg,msg_callback);

}
