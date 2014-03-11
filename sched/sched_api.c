#include <sched.h>

int task_compare(task_t *task1, task_t task *task2){
    if(!task1){
        return -1;
    }

    if(!task2){
        return 1;
    }

    struct task_ctrl *t1 = get_task_ctrl(task1);
    struct task_ctrl *t2 = get_task_ctrl(task2);

    if( t1 -> priority > t2 -> priority){
        return 1;
    }
    else if( t2->priority > t1-> priority){
        return -1;
    }

    return 0;
}

uint8_t task_runnable(task_t *task){
    task_ctrl *match = get_task_ctrl(task);
    task_ctrl *node;

    list_for_each_entry(node, &runnable_task_list, runnable_task_list)
    {
        if(node == match){
            return 1;
        }
    }
    return 0;
}


int task_swtich(task_t *task){
    int ret;
    task_ctrl *t = task ? get_task_ctrl(task) : NULL;

    if(arch_svc_leagl()){
        ret = SVC_ARG(SVC_TASK_SWTICH, t);
    }
    else {
        ret = svc_task_swtich(t);
    }
    return ret;
}


