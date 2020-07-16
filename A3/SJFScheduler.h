#include "Scheduler.h"

#ifndef SJFSCHEDULER_H
#define SJFSCHEDULER_H

class SJFScheduler: public Scheduler {
public:
    SJFScheduler();
    SJFScheduler(const SJFScheduler& orig);
    virtual ~SJFScheduler();
    
    /* Comparison for burst time */
    struct LowerBurstTime {
        bool operator()(Process* left, Process* right) const {
            return left->initCpuTime < right->initCpuTime;
        }
    };
    
    priority_queue<Process*, vector<Process*>, LowerBurstTime> processQueue;
private:

};

#endif /* SJFSCHEDULER_H */
