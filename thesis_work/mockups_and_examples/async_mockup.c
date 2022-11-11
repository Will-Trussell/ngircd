//This file is a mockup of what a potential async I/O extension would look like
//Potential ideas are sketched out below
//We want to simulate the epoll API without the messiness of C code

//Would like something like this:

spawn task1 = {
    stack_size = <some size (optional?)> //If optional, default to some default value, i.e. 4096?
    context = <optional context, defaults to current context>
    fd = <some file descriptor associated with the task>
}

spawn task2 = {
    fd = <some other file descriptor to watch>
}

//Want some way to indicate to begin tracking tasks
//Something to translate to epoll_ctl()


//One option: await a specific task to finish
await task1 //Waits until task 1 finishes running

//Another option: await until a task finishes, put it in some variable
await first_task[8]

//... Do something with either task1 or first_task


//All of the above code translates into something akin to Nathan's example file
//spawn task {...} translates roughly into task_new or task_spawn
//Await translates into an epoll_wait() syscall
//
//May just want to do the second option with await and some variable name
//Not sure if waiting for a specific task is possible with epoll



//New Syntax
closure <() -> void> f = lambda () -> void { /*Code here*/}
spawn f // Translate down to task_spawn(f)

// Translation of functions from io.c to nathan's functions
// io_event_change_epoll -> task_yield_for_io 
// io_dispatch_epoll     -> idle_task ?
// io_library_init_epoll -> executor_new (approximately)
//
// Not perfect translations for some IO functions, but the above are close-ish
// translations
