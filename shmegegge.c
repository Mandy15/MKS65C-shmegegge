#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  int shmid = shmget(0, 200, 0644 | IPC_CREAT);
  printf("Connected a shared memory segment: %d.\n", shmid);

  char * data;
  data = shmat(shmid, (void *)0, 0);
  if(data){
    printf("Segment just created.\n");
  }else{
    printf("Shared memory contents: %s\n", data);
  }

  char *input = malloc(100*sizeof(char));
  printf("Do you want to change the data in the segment?(y/n): ");
  fgets(input, 200, stdin);
  if(strcmp(input, "y\n") == 0){
    printf("Enter the string you would like to add.\n");
    fgets(input, 200, stdin);
    strcpy(data, input);
    printf("Current segment: %s\n", data);
  }

  printf("Do you want to delete the segment?(y/n): ");
  fgets(input, 200, stdin);
  if(strcmp(input, "y\n") == 0){
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Deleted segment.\n");
  }
  printf("Goodbye.\n");

  return 0;
}
