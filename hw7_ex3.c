/* Create a union called SensorData that can store different types of sensor readings: – int temperature
(for temperature sensors)– float pressure (for pressure sensors)– float humidity (for humidity sensors
Write a C program to:
 Input the type of sensor and its reading.
 Store the reading in the union.
 Display the sensor type and the corresponding reading*/

#include <stdio.h>

typedef union {
	int temp;
	float pres;
	float hum;
} SensorData;

int main() {
	SensorData s;
	int type;

	printf("Select sensor type:\n1. Temperature\n2. Pressure\n3. Humidity\n");
	printf("Enter choice: ");
	scanf("%d", &type);

	switch(type) {
		case 1:
			printf("Enter temperature (int): ");
			scanf("%d", &s.temp);
			printf("Sensor Type: Temperature\nReading: %d\n", s.temp);
			break;
		case 2:
			printf("Enter pressure (float): ");
			scanf("%f", &s.pres);
			printf("Sensor Type: Pressure\nReading: %.2f\n", s.pres);
			break;
		case 3:
			printf("Enter humidity (float): ");
			scanf("%f", &s.hum);
			printf("Sensor Type: Humidity\nReading: %.2f\n", s.hum);
			break;
		default:
			printf("Invalid choice!\n");
	}

	return 0;
}
