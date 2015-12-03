
?
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
	
/***********************************************************
 * * You can use all the programs on  www.c-program-example.com
 * * for personal and learning purposes. For permissions to use the
 * * programs for commercial purposes,
 * * contact info@c-program-example.com
 * * To find more C programs, do visit www.c-program-example.com
 * * and browse!
 * * 
 * *                      Happy Coding
 * ***********************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
 
 
#define NUM_LOOPS 20
int main(int argc, char* argv[])
{
    int sem_set_id;
    union semun sem_val;
    int child_pid;
    int i;
    struct sembuf sem_op;
    int rc;
    struct timespec delay;
     
     
    sem_set_id = semget(IPC_PRIVATE, 1, 0600);
    if (sem_set_id == -1) {
        perror("main: semget");
        exit(1);
    }
    printf("Semaphore set created,
    semaphore set id '%d'.\n", sem_set_id);
     
     
    sem_val.val = 0;
    rc = semctl(sem_set_id, 0, SETVAL, sem_val);
    child_pid = fork();
    switch (child_pid) {
        case -1:
        perror("fork");
        exit(1);
        case 0:
        for (i=0; i<NUM_LOOPS; i++) {
            sem_op.sem_num = 0;
            sem_op.sem_op = -1;
            sem_op.sem_flg = 0;
            semop(sem_set_id, &sem_op, 1);
            printf("consumer: '%d'\n", i);
            fflush(stdout);
            sleep(3);
        }
        break;
        default:
        for (i=0; i<NUM_LOOPS; i++)
        {
            printf("producer: '%d'\n", i);
            fflush(stdout);
            sem_op.sem_num = 0;
            sem_op.sem_op = 1;
            sem_op.sem_flg = 0;
            semop(sem_set_id, &sem_op, 1);
            sleep(2);
            if (rand() > 3*(RAND_MAX/4))
            {
                delay.tv_sec = 0;
                delay.tv_nsec = 10;
                nanosleep(&delay, NULL);
            }
        }
        break;
    }
     
     
    return 0;
}
