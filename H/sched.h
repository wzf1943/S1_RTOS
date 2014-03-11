//#ifdef 
//#define 
#include <stdio.h>

extern volatile uint8_t task_switching;

typedef struct task_t{
    

} task_t;

extern task_t * volatile curr_task;

extern volatile uint32_t total_task;

void start_sched(void);

task_t *new_task(void (*fptr)(void), uint8_t priority, uint32_t period);

void main(void);

// static _always_inline void
//
// void generic_task_setup(task_t *task)


void generic_task_setup(tesk_t *task);

int task_copare(task_t *task1, task_t *task2);

uint8_t task_runnable(task_t *task);

int task_switch(task_t *task);

//#endif
