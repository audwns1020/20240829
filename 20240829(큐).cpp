// ť ����2
#include <stdio.h> // 1/3 ������

#define MAXSIZE 10		// ť�� ũ��

int queue[MAXSIZE];
int front, rear;

void init_queue()
{
	front = rear = 0;
	printf("QUEUE SIZE is %d\n\n", MAXSIZE);
}

void clear_queue()
{
	front = rear;
}

int enqueue(int val)
{
	if ((rear + 1) % MAXSIZE == front) {	// ť�� �� á���� Ȯ��
		printf("	QUEUE Overflow.\n");
		return -1;
	}

	queue[rear] = val;				// rear�� ť�� �� ������ ������̹Ƿ� �ٷ� ����
	rear = ++rear % MAXSIZE;		// rear�� ���� ��������� ����
	return val;
}

int dequeue()
{
	int i;

	if (front == rear) {		// ť�� ��� �ִ��� Ȯ��
		printf("	QUEUE Underflow.\n");
		return (-1);
	}

	i = queue[front];	// front�� ���� ������
	front = ++front % MAXSIZE;		// front�� ���� ������ ��ҷ�
	return i;
}

void print_queue()		// 2/3 ������
{
	int i;
	printf("\n QUEUE From Front------> To Rear \n");
	for (i = front; i != rear; i = ++i % MAXSIZE)
		printf("%-6d", queue[i]);
	printf("\n\n");
}

int main()
{
	int i, value, choice;
	bool while_flag = true;

	init_queue();

	while (while_flag) {
		printf("1. enqueue\n2. dequeue\n: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nenqueue �� ���� �Է����ּ���: ");
			scanf("%d", &value);
			enqueue(value);
			print_queue();
			break;
		case 2:
			i = dequeue();
			printf("\ndequeue �� �� : %d\n", i);
			print_queue();
			break;
		default:
			while_flag = false;
			break;
		}
	}

	return 0;
}