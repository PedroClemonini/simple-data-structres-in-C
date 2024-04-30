#ifndef QUEUE_H
#define QUEUE_H
#include "info.h"

typedef struct QUEUE QUEUE;

QUEUE *makeQueue(void);

void deleteQueue(QUEUE *fi);

int queueSize(QUEUE *fi);

int emptyQueue(QUEUE *fi);

int pushQueue(QUEUE *fi, STU_STRUCT al);

int pullQueue(QUEUE *fi);

int queryQueue(QUEUE *fi, STU_STRUCT *al);

#endif
