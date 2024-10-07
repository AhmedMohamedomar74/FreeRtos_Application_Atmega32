#include "SSD_interface.h"
#include "FreeRTOS.h"
#include "task.h"

/* Define Tasks Priorities */
#define TASK2_PRIORITY (3)
#define TASK_DISPLAY_WAITING_TIME (2)
#define TASK1_PRIORITY (1)

#define TASK1_STACK_SIZE (configMINIMAL_STACK_SIZE * 2)
#define TASK2_STACK_SIZE (configMINIMAL_STACK_SIZE * 2)

/*tasks codes prototypes */
void ssd_display(void *pvParamter);
void task2_code(void *pvParamter);
void Control_time(void *pvParamter);
u8 Waiting_time = 0;

int main(void)
{

	SSD_voidInit();
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
	xTaskCreate(ssd_display, NULL, TASK1_STACK_SIZE, NULL, TASK1_PRIORITY, NULL);
	xTaskCreate(task2_code, NULL, TASK2_STACK_SIZE, NULL, TASK2_PRIORITY, NULL);
	xTaskCreate(Control_time, NULL, TASK2_STACK_SIZE, NULL, TASK_DISPLAY_WAITING_TIME, NULL);
	/*start Scheduler */
	vTaskStartScheduler();

	return 0;
}

/*Task1 Code */
void ssd_display(void *pvParamter)
{
	for (;;)
	{
		SSD_voidDisplayMultiplexedNumber(Waiting_time);
	}
}
/*Task2 Code */
void task2_code(void *pvParamter)
{
	for (;;)
	{
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
		Waiting_time = 11;
		vTaskDelay(10000);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
		Waiting_time = 6;
		vTaskDelay(5000);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_LOW);
		Waiting_time = 11;
		vTaskDelay(10000);
	}
}

void Control_time(void *pvParamter)
{
	for (;;)
	{
		Waiting_time--;
		vTaskDelay(1000);
	}
}
