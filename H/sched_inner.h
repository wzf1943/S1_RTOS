//#ifdef ...
//#define ...


typedef struct task_ctr1{
    uint32_t    *stack_limit;
    uint32_t    *stack_top;
    uint32_t    *stack_base;
    void        (*fptr)(void);
    uint32_t    period;
   // uint32_t      ticks_until_wake;
   // uint8_t       running;
   // uint8_t       abort;
   // uint32_t      pid;
   // struct list   runnable_task_list;
   // struct list   periodic_task_list;
   // struct list   free_task_list;
   // task_t        exported;
} task_ctrl;

static task_t * get_task_t(task_ctr1 *task){
    return &task -> exported;
}

// int sched_service_call(uint32_t svc_number,...);


void switch_task(task_ctr1 *task);

void rtos_tick(void);

void save_context(void);

vid restore_context(void);

uint32_t *get_user_stack_pointer(void);

void create_context(task_ctr1 *task, void(*lptr)(void));

//#endif
