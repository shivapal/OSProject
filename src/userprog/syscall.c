#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

struct processInfo 
{
struct list_elem elem;
struct file *file;
int fd
};

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  thread_exit ();
}	
void checkaddress(const void *ptr)
{
if((is_user_vaddr(ptr)==false)||(ptr==NULL))
{
exit(-1);
}

}
void halt()
{
shutdown_power_off();
}
void exit(int status)
{
thread_current()->exit_status= status;
printf("terminated: %s = %d\n",thread_current()->name, status);
thread_exit();
}
pid_t exec(const char*cmd_line)
{
pid_t child = process_execute(cmd_line);
return child;
}
int wait(pid_t pid)
{
return process_wait(pid);
}
bool create (const char*file, unsigned initial_size)
{
return  filesys_create(file, initial_size);
}
bool remove (const char*file)
{
return filesys_remove(file);
}
int open(const char*file)
{
struct file *f = filesys_open(file);

}
int filesize(int size)
{

}
int read (int fd, void *buffer, unsigned size)
{

}
int write (int fd, const void *buffer, unsigned size)
{

}
void seek(int fd, unsigned position)
{

}
unsigned tell (int fd)
{

}
void close(int fd)
{

}
