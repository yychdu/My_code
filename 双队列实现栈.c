#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char DataType2;

typedef struct Queue
{
	DataType2* queue_data;
	int head;
	int tail;
	int size;
	int capacity;
}Queue;

typedef struct Stack
{
	Queue queue1;
	Queue queue2;
	//栈中有效元素个数
	int size;
}Stack;

//栈的初始化
void StackInit(Stack *stack,int vector_capacity);
//栈的销毁
void StackDestory(Stack* stack);
//入栈
void StackPush(Stack* stack, DataType2 value);
//出栈
void StackPop(Stack* stack);
//取栈顶元素
DataType2 StackGetTop(Stack* stack);

void QueueInit(Queue* queue, int vector_capacity)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	queue->capacity = vector_capacity;
	queue->queue_data = (DataType2*)malloc(sizeof(DataType2)*queue->capacity);
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
}

void QueueDestory(Queue* queue)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	free(queue->queue_data);
	queue->queue_data = NULL;
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->capacity = 0;
}

void QueuePush(Queue* queue,DataType2 value)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	if (queue->size >= queue->capacity)
	{
		return ;
	}
	queue->queue_data[queue->tail++] = value;
	queue->size++;
	if (queue->tail > queue->capacity)
	{
		queue->tail = 0;
	}
}

void QueuePop(Queue* queue)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	if (queue->size == 0)
	{
		return ; 
	}
	if (queue->head >= queue->capacity)
	{
		queue->head = 0;
	}
	queue->head++;
	queue->size--;
	if (queue->size == 0)
	{
		queue->head = 0;
		queue->tail = 0;
	}
}
//取队首元素
DataType2 QueueGetTop(Queue* queue)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	if (queue->size == 0)
	{
		return ;
	}
	return queue->queue_data[queue->head];
}

//打印整个队列
void PrintQueue(Queue* queue)
{
	if (queue == NULL)
	{
		assert(0);
		return -1;
	}
	if (queue->size == 0)
	{
		return ; 
	}
	if (queue->head < queue->tail)
	{
		int i = queue->head;
		for (; i < queue->tail; i++)
		{
			printf("%c ", queue->queue_data[i]);
		}
	}
	else
	{
		int i = queue->head;
		while (queue->head < queue->capacity)
		{
			printf("%c", queue->queue_data[queue->head]);
			queue->head++;
		}
		queue->head = 0;
		for (i = queue->head; i < queue->tail; ++i)
		{
			printf("%c ", queue->queue_data[i]);
		}
	}
	printf("\n");
}

//通过两个队列实现一个栈的入栈，出栈和取栈顶元素操作
//栈的初始化函数
void StackInit(Stack* stack,int vector_capacity)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	QueueInit(&stack->queue1,vector_capacity);
	QueueInit(&stack->queue2,vector_capacity);
	stack->size = 0;
}

//销毁一个栈
void StackDestory(Stack* stack)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	QueueDestory(&stack->queue1);
	QueueDestory(&stack->queue2);
	stack->size = 0;
}

//入栈操作
void StackPush(Stack* stack,DataType2 value)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	if (stack->queue1.size != 0) {
		QueuePush(&stack->queue1, value);
	}
	else {
		QueuePush(&stack->queue2, value);
	}
	stack->size++;
}

void StackPop(Stack* stack)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	if (stack->queue1.size == 0 && stack->queue2.size == 0)
	{
		return ;
	}
	Queue* from = NULL;
	Queue* to = NULL;
	//判断数据放在了哪个队列
	if (stack->queue1.size != 0)
	{
		from = &stack->queue1;
		to = &stack->queue2;
	}
	else
	{
		from = &stack->queue2;
		to = &stack->queue1;
	}
	while (from->size > 1)
	{
		//取到from队列的队头元素
		DataType2 tmp = QueueGetTop(from);
		//from做一次出队列操作
		QueuePop(from);
		//将from的对头放到to队列
		QueuePush(to, tmp);
	}
	//把from队列剩的最后一个元素移出队列，模拟出栈
	QueuePop(from);
	//栈中的有效数据个数减一
	stack->size--;
}

DataType2 StackGetTop(Stack* stack)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	if ((stack->queue1.size == 0) && (stack->queue2.size == 0))
	{
		return ;
	}
	Queue* from = NULL;
	Queue* to = NULL;
	//判断数据放在了哪个队列
	if (stack->queue1.size != 0)
	{
		from = &stack->queue1;
		to = &stack->queue2;
	}
	else
	{
		from = &stack->queue2;
		to = &stack->queue1;
	}
	while (from->size > 1)
	{
		//取到from队列的队头元素
		DataType2 tmp = QueueGetTop(from);
		//from做一次出队列操作
		QueuePop(from);
		//将from的对头放到to队列
		QueuePush(to, tmp);
	}
	//读取from队列的最后一个元素，模拟读取栈顶
	DataType2 stacktop = QueueGetTop(from);
	QueuePop(from);
	QueuePush(to, stacktop);
	return stacktop;
}

void PrintStack(Stack* stack)
{
	if (stack == NULL)
	{
		assert(0);
		return -1;
	}
	if (stack->size == 0)
	{
		return ;
	}
	Queue* print = NULL;
	if (stack->queue1.size == 0)
	{
		print = &stack->queue2;
	}
	else
	{
		print = &stack->queue1;
	}
	PrintQueue(print);
}

int main()
{
	Stack stack;
	//初始化
	StackInit(&stack,10);
	//入栈函数测试
	StackPush(&stack, 'a');
	StackPush(&stack, 'b');
	StackPush(&stack, 'c');
	StackPush(&stack, 'd');
	StackPop(&stack);
	PrintStack(&stack);
	DataType2 top_value = StackGetTop(&stack);
	printf("%c \n", top_value);
	StackDestory(&stack);
	system("pause");
	return 0;
}
