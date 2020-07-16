#include "Scheduler.h"

#ifndef FCFSSCHEDULER_H
#define FCFSSCHEDULER_H

class FCFSScheduler: public Scheduler {
public:
    FCFSScheduler();
    FCFSScheduler(const FCFSScheduler& orig);
    virtual ~FCFSScheduler();
private:

};

#endif /* FCFSSCHEDULER_H */
