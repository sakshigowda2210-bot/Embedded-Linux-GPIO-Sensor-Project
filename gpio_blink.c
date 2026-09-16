#include <stdio.h>
#include <unistd.h>

#define GPIO_VALUE "sim/gpio17/value"
int main(void)
{
    FILE *gpio;
    for (int i = 0; i < 10; i++)
    {
	gpio = fopen(GPIO_VALUE, "w");
	if (gpio == NULL)
	{
	    perror("Failed to open GPIO");
	    return 1;
	}
	fprintf(gpio, "1\n");
	fclose(gpio);
	printf("GPIO17 = HIGH\n");
	sleep(1);
	gpio = fopen(GPIO_VALUE, "w");
	if (gpio == NULL)
	{
	    perror("Failed to open GPIO");
	    return 1;
	}
	fprintf(gpio, "0\n");
	fclose(gpio);
	printf("GPIO17 = LOW\n");
	sleep(1);
    }
    printf("GPIO test completed.\n");
    return 0;
}

