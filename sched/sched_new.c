#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static task_ctrl * create_task(void(*fptr)(void), uint8_t priority, uint32_t period)/*_attribute_((section(".kernel")))*/;

static int register_task( task_ctrl *task_ptr, int periodic)/*__attribute__((section(".kernel")))*/;

//struct list runnable_task_list = INIT_LIST(runnable_task_list);
//struct list periodic_task_list = INIT_LIST(periodic_task_list);

//DEFINE_INSERT_TASK_FUNC(runnable_task_list);
//DEFINE_INSERT_TASK_FUNC(periodic_task_list);
//
volatile uint32_t total_tasks = 0；

task* new_task(void (*fptr)(void), uint8_t priority, uint32_t period){
    task_ctrl *task = create_task(fptr, priority, period);
    if(task == NULL){
        printf("Failed");
    }

    int ret = register_task(task, period);
    if(ret != 0){
        //free(task-> stack_limit);
        //kfree(task);
    }

    totale_task += 1;

    return get_task_t(task);
}


static task_ctrl * create_task(void (*fptr)(void), uint8_t priority, uint32_t period){
    task_ctrl *task;
    uint32_t *memory;
    static uint32_t pid_source = 1;
    task = (task_ctrl*)kamlloc(sizeof(task_ctrl));
    if(task == NULL){
        return NULL;
    }

    task -> stack_limit         = memory;
    task -> stack_base          = memory + STKSIZE;
    task -> fptr                = fptr;
    task -> priority            = priority;
/*    task -> running             = 0;
    task -> abort               = 0;
    
    task -> period              = period;
    task -> ticks_until_wake    = period;
    task -> pid                 = pid_source++;

    list_init(&task -> unnable_task_list);
    list_init(task -> periodic_task_list);
    list_init(&task -> free_task_list);

    generic_task_setup(get_task_t(task));
  */  return task;
}

void int register_task(task_ctrl *task, int periodic){
    if(task_switching){
        //SVC_ARG2();
    }esle{
        svc_register_task(task, periodic);
    }

    return 0;

}

void svc_register_task( task_ctrl *task, int periodic){
    inster_task(runnable_task_list, task);
    if(periodic){
        intert_task(periodic_task_list, task);
    }
}





