
#include "als.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
struct SensorReading gSensorLatest = {0};
pthread_mutex_t gMutex;
pthread_t gThread;
void thread_handler(void) {
  SensorReading tmp;
  
  while (1)
  {
    pthread_mutex_lock(&gMutex);    
    tmp = read_next_sample();
    if (tmp.status == ERROR)
    {
      pthread_mutex_unlock(&gMutex);    
      continue;
    }
    
    if (tmp.status == VALID)
    {
      gSensorLatest = tmp;
      printf("updated\n");      
    }
      
    pthread_mutex_unlock(&gMutex);    
  }
}
void init_recent_lux(void) {
    // your init code here if any
  pthread_attr_t attr;
  int res = 0;
  // Initialize thread attributes
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_mutex_init(&gMutex,NULL);
    
  res = pthread_create(&gThread, &attr, (void*)thread_handler, NULL);
  if (res < 0)
  {
    perror("Fail to Create Thread\n");
    exit(-1);
  }
  pthread_attr_destroy(&attr);
}
// Part 1
// Return most recent measured lux value, without blocking, and in a thread-safe manner.
float get_most_recent_lux(void) {
  return (gSensorLatest.lux);
}
// Part 2
// return -2 if the input timestamp is in the future
// return -1 if the input timestamp is not represented in the history
float get_lux_at(uint64_t timestamp) {
    return -1.0;
}



typedef struct _Node {
    int val;
    Node *next;
} Node;
pthread_mutex_t gMutex;

Node* add(int val, Node *head)
{
    Node *new = malloc(sizeof(Node));
    new->val = val;

    pthread_mutex_lock(&gMutex);    
    new->next = head;
    pthread_mutex_unlock(&gMutex);    
    return new;
}

void Remove(int val, Node *head)
{
    Node *prev = NULL, *cur = head;

    while (cur)
    {
        if (cur->val == val)
        {
            pthread_mutex_lock(&gMutex);    
            prev->next = cur->next;
            pthread_mutex_unlock(&gMutex);    
            free(cur);
            return ;
        }
        prev = cur;
        cur = cur->next;
    }
    return ;
}


#include <stdio.h>

// Function prototypes for basic arithmetic operations
int add(int a, int b) {
    return a + b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

// Define a type for function pointers that take two int arguments and return an int
typedef int (*operation_func)(int, int);

int main() {
    // Initialize the function table with the arithmetic operations
    operation_func operations[4];
    operations[0] = add;
    operations[3] = divide;

    int a = 10, b = 5;
    int choice;

    scanf("%d", &choice);

    // Validate the choice and call the corresponding function
    if (choice >= 0 && choice < 4) {
        int result = operations[choice](a, b);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
