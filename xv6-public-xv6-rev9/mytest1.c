#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

void
getpid_test(void)
{
  int ppid;

  ppid = getpid();                          // mytest1.c executes getpid() in the userspace
  printf(1, "getpid_test = %d\n", ppid);
}

void
getpri_test(void)
{
  int ppri;

  ppri = getpri();                          // mytest1.c executes getpid() in the userspace
  if(ppri==50){
    printf(1, "    -PASSED. Priority = %d\n", ppri);
  } else {
      printf(1,"**FAIL**");
  }
}

void
setpri_test(void)
{
  int ppri;

  setpriority(200);                          
  ppri = getpri();
  if(ppri==200){
    printf(1, "    -PASSED. Priority was set to = %d\n", ppri);
  } else {
    printf(1,"    -**FAIL**\n");
    printf(1, "      Priority was not set to 200. Priority = %d\n", ppri);
  }

  setpriority(166);                          
  ppri = getpri();
  if(ppri==166){
    printf(1, "    -PASSED. Priority was set to = %d\n", ppri);
  } else {
    printf(1,"    -**FAIL**\n");
    printf(1, "      Priority was not set to 166. Priority = %d\n", ppri);
  }

  setpriority(1);                          
  ppri = getpri();
  if(ppri==1){
    printf(1, "    -PASSED. Priority was set to = %d\n", ppri);
  } else {
    printf(1,"    -**FAIL**\n");
    printf(1, "      Priority was not set to 1. Priority = %d\n", ppri);
  }
}

void
setpri_low_test(void)
{
  int ppri;

  // set priority back to default value
  setpriority(50);

  setpriority(-1);                          
  ppri = getpri();
  if(ppri==50){
    printf(1, "    -PASSED. Priority = %d\n", ppri);
  } else {
    printf(1,"    -**FAIL**\n");
    printf(1, "      Priority was set to invalid low int. Priority = %d\n", ppri);
  }
}

void
setpri_high_test(void)
{
  int ppri;

  setpriority(201);                          
  ppri = getpri();
  if(ppri==50){
    printf(1, "    -PASSED. Priority = %d\n", ppri);
  } else {
    printf(1,"    -**FAIL**\n");
    printf(1, "      Priority was set to invalid high int. Priority = %d\n", ppri);
  }
}

int
main(int argc, char *argv[])
{
  printf(1, "getpid test starting\n");
  getpid_test();
  printf(1, "\nChecking that Priority is by default 50\n");
  getpri_test();
  printf(1, "\nPriority can be set within range [0-200]\n");
  setpri_test();
  printf(1, "\nCannot set priority less than 0\n");
  setpri_low_test();
  printf(1, "\nCannot set priority higher than than 200\n");
  setpri_high_test();
  exit();
}