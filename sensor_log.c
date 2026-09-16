#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SENSOR_FILE "sim/w1_device/w1_slave"
#define LOG_FILE "temp_log.csv"
int main(void)
{
    FILE *sensor;
    FILE *log;
    char line[256];
    char *temp_position;
    double temperature = 0.0;
    time_t now;
    sensor = fopen(SENSOR_FILE, "r");
    if (sensor == NULL)
    {
    	perror("Failed to open sensor file");
	return 1;
    }
    while (fgets(line, sizeof(line), sensor))
    {
    	   temp_position = strstr(line, "t=");
	   if (temp_position != NULL)
	   {
	       temperature = atof(temp_position +2) / 1000.0;
	       break;
	   }
    }
    fclose(sensor);
    time(&now);
    log = fopen(LOG_FILE, "a");
    if (log == NULL)
    {
    	perror("Failed to open log file");
	return 1;
    }
    fprintf(log,"%ld,%.3f\n", (long)now, temperature);
    fclose(log);
    printf("Temperature: %.3f C\n", temperature);
    printf("Temperature logged successfully.\n");
    return 0;
}
