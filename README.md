# [Scheduling Algorithms](https://github.com/PrakharPipersania/Scheduling-Algorithms)

![Language](https://img.shields.io/badge/Language-C-255fcc.svg)&nbsp;
[![License](https://img.shields.io/badge/License-MIT-orange.svg)](./LICENSE)&nbsp;
![Total Tests](https://img.shields.io/badge/Total%20Tests-58%20(All%20Passed)-purple.svg)&nbsp;
![Progress](https://img.shields.io/badge/Progress-100%25-brightgreen.svg)&nbsp;

## Some Popular Process Scheduling Algorithms are:-
* First Come First Served (FCFS) Scheduling
* Shortest Job First (SJN) Scheduling
* Priority Scheduling
* Round Robin(RR) Scheduling
* Highest Response Ratio Next(HRRN) Scheduling

### First Come First Served Scheduling:
In this Algorithm, Process that request CPU first, CPU is allocated first to that process .i.e. the algorithm is known as first come, first served. It based on FIFO (First in First Out) queue data structure. When a process entered in the ready queue, its Process Control Block (PCB) is added to end of the Queue. When CPU gets free after a process execution, a new process from the head of the queue is removed and enters in running state.
* Criteria: Arrival Time
* Mode: Non-Preemptive
* Convoy Effect OR Starvation (When the process with the highest burst time is first entertained by the CPU)

### Shortest Job First Scheduling:
SJF is a preemptive and Non-Preemptive algorithm. It based on length of latter’s next CPU burst. If a process acquired CPU and execution is going on, a new process with small CPU burst entered. Then CPU is preempted from current process and will give to further process. If two processes have the same length next CPU burst, FCFS scheduling is used to break the tie. Shortest Next CPUburst is also an appropriate term for SJF algorithm because scheduler examines the length of next CPU burst continuously.
* Criteria: Burst Time
* Mode(Shortest Job First): Non-Preemptive
* Mode(Shortest Remaining Time First ): Preemptive

### Priority Scheduling:
SJF is a simple priority algorithm, where we are not considering the smallest next CPU burst, scheduler consider the priority of processes. The priority assigned to each process and CPU allocated to highest priority process. Equal priority processes scheduled in FCFS order. Priority can be discussed regarding Lower and higher priority.Numbers denote it.We can use 0 for lower priority as well as more top priority.There is not a hard and fast rule to assign numbers to preferences.
* Criteria: Priority
* Mode: Non-Preemptive OR Preemptive

### Round Robin Scheduling
Round Robin Scheduling algorithm designed for time-sharing systems. It is similar to FCFS scheduling but adding preemption to switch the processes after a small unit of time. A small unit of time is called a time quantum. A time quantum might be from 10 to 100 millisecond.
* How RR algorithm works:  Ready queue as a FIFO queue. The new process will add to the tail of the ready queue and process is removed from the head of queue.CPU select a process from ready queue, set a timer. After completion of time quantum, the process will be preempted doesn’t matter it is completed or not. IF the process not finished it will add in the tail of the queue and CPU select new process. In this way, the process is going on.
* Criteria: Time Quantum
* Mode: Preemptive
* No Starvation

### Highest Response Ratio Next Scheduling
Highest Response Ratio Next (HRNN) is one of the most optimal scheduling algorithms. This is a non-preemptive algorithm in which, the scheduling is done on the basis of an extra parameter called Response Ratio. A Response Ratio is calculated for each of the available jobs and the Job with the highest response ratio is given priority over the others.
* Criteria: Response Ratio
* Mode: Non-Preemptive
