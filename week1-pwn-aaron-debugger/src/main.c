#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define asm __asm__

static inline void aaronline(char *buf) {
    char c;
    size_t i = 0;
    while ((c = getchar()), c != '\n') {
        buf[i++] = c;
    }

    buf[i] = 0;
}

void getinput() {
    char *aaron_messages[] = {
        "i use arch btw",
        "why don't you use arch linux? i can help you install it!",
        "sloooooop",
        "reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
        "HI MICHELLLLLEEEEEEE",
        "Remember to change your name to Aaron later",
        "Why don't you like that?",
        "Really? Why's that?",
        "When was the last time this happened?",
        "I'm sorry, I don't understand your message! Do you want me to bring a real Aaron to answer it for you?",
        "yessssss",
        "yes",
        "no",
        "noooooooO",
        "maybe",
        "i absolutely disagree but ok",
        "wow",
        "nice job", 
        "frick I haven't started my assignment gtg do it brb",
        "I've skipped so many classes omg",
        "How is ur day going m8?",
        "i wish i could solve this challenge too... sadly my creators did not give me enough intelligence to do that (they dont have enough intelligence to solve it either)",
        "ich habe eine frage",
        "aaron",
        "aaaaaaaroonnnn",
        "You have ascended to Aaron-hood, congratulations",
        "You are now an Aaron, congratulations",
        "You should play red eclipse"
    };

    const size_t size = sizeof(aaron_messages)/sizeof(aaron_messages[0]);
    char cur_msg[200];

    printf("message number> ");
    aaronline(cur_msg);
    char *endp;
    register uint64_t i asm("rbp");
    int64_t randmsg_i = (int64_t)strtoll(cur_msg, &endp, 10);
    if (randmsg_i >= (int64_t)size) {
        printf("NOOOOOOOOOOOO!!!!! YOU CAN'T JUST GO OUTSIDE OF THE ARRAY!!!!! https://i.imgflip.com/3vl57m.png\n");
        return; // cant exit cuz then the bof wont work :((( well actually they could get around it if theyre smaART:wq
    }
    //printf("buf=%p, aaron_messages=%p, addr=%p\n", cur_msg, aaron_messages, &aaron_messages[(uint64_t)((int64_t)(-28))]);
    // printf("Canary: 0x%"PRIx64"\n", *((uint64_t *)i - 0x8));
    printf("index: %lu: message pointer: %p\n\n", (uint64_t)randmsg_i, aaron_messages[(uint64_t)randmsg_i]);
}

int main() {
    srand(time(NULL));
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    printf("We've fully implemented blockchain powered AI neural networks to give you the ability to chat with a fully realized automated Aaron!\n\nWELCOME TO THE AARON AI CHATBOT DEBUGGER. You can debug past messages the Aaron chatbot has sent here (where they are in memory).\n\nSimply enter the message id (sequential indexed at 0) and this program will output where the message was in memory.\n\nRemember to run checksec, and google ROP, one_gadget, stack canaries, and libc database (libc.blukat.me). A pretty easy \"hard\" challenge... shouldn't be too hard for an op pwner like you. Gl hf.\n\n");

    alarm(1200000);

    while (1) {
        getinput();
    }


    return 0;
}
