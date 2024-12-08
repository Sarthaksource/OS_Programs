#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

//Full = how much fill buffer is?
//Empty = how much empty buffer is?

int mutex = 1, full = 0, empty = BUFFER_SIZE, x = 0;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int wait(int s) {
    return (s > 0) ? --s : s;
}

int signal(int s) {
    return (s < BUFFER_SIZE) ? ++s : s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    buffer[in] = x;
    printf("\nProducer produces the item %d", x);
    in = (in + 1) % BUFFER_SIZE;
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    int item = buffer[out];
    printf("\nConsumer consumes item %d", item);
    out = (out + 1) % BUFFER_SIZE;
    mutex = signal(mutex);
}

int main() {
    int ch;
    printf("\n1. Producer\n2. Consumer\n3. Exit");
    while (1) {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full!!");
                break;
            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty!!");
                break;
            case 3:
                printf("Exiting\n");
                return 0;
            default:
                printf("Wrong Choice\n");
                break;
        }
    }

    return 0;
}
