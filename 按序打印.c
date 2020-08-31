#include <semaphore.h>
typedef struct {
    // User defined data may be declared here.
    sem_t lock2;
    sem_t lock3;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    sem_init(&obj->lock2, 0, 0);
    sem_init(&obj->lock3, 0, 0);
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->lock2);
}

void second(Foo* obj) {
    sem_wait(&obj->lock2);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->lock3);
}

void third(Foo* obj) {
    sem_wait(&obj->lock3);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();

}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    sem_destroy(&obj->lock3);
    sem_destroy(&obj->lock2);
}


typedef struct {
    int n;
    sem_t lock1;
    sem_t lock2;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->lock2, 0, 0);
    sem_init(&obj->lock1, 0, 1);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->lock1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        sem_post(&obj->lock2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->lock2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        sem_post(&obj->lock1);
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&obj->lock1);
    sem_destroy(&obj->lock2);
    free(obj);
}