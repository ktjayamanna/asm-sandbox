#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Enum for sensor types
typedef enum
{
    UNK = -1,
    TEMPERATURE,
    HUMIDITY,
    PRESSURE,
} SensorType;

// Enum for sensor status
typedef enum
{
    ACTIVE,
    INACTIVE,
    ERROR
} SensorStatus;

// Union for sensor-specific configuration and data
typedef union
{
    struct
    {
        short int min_range; // Temperature range min (Celsius)
        short int max_range; // Temperature range max (Celsius)
        float reading;       // Latest reading
    } temperature;
    struct
    {
        float calibration; // Calibration factor
        float reading;     // Latest reading
    } humidity;
    struct
    {
        short int altitude; // Altitude compensation (meters)
        float reading;      // Latest reading
    } pressure;
} SensorData;

// Struct for Sensor
typedef struct
{
    unsigned char id;
    char name[20];
    SensorType type;
    SensorData data;
    SensorStatus status;
} Sensor;

// Function prototypes
void init_sensor(Sensor *sensors, unsigned char *count, unsigned char max_sensors);
void read_sensor_data(Sensor *sensor);
void process_sensor_data(Sensor *sensor);
void display_sensors(Sensor *sensors, unsigned char count);

// Main function with sample usage
int main()
{
    Sensor sensors[10] = {0}; // Static array for max 10 sensors
    unsigned char count = 0;
    char choice;
    srand(time(NULL)); // Seed for simulated readings

    do
    {
        printf("\n1. Initialize Sensor\n2. Read Sensor Data\n3. Display Sensors\n4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            init_sensor(sensors, &count, 10);
            break;
        case '2':
            for (unsigned char i = 0; i < count; i++)
            {
                read_sensor_data(&sensors[i]);
                process_sensor_data(&sensors[i]);
            }
            break;
        case '3':
            display_sensors(sensors, count);
            break;
        case '4':
            printf("Thank you for using us\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

// Function implementations (to be completed)
void init_sensor(Sensor *sensors, unsigned char *count, unsigned char max_sensors)
{
    // TODO: Validate inputs and ensure count < max_sensors
    if (*count >= max_sensors)
    {
        printf("Maximum number of sensors reached!\n");
        return;
    }
    // TODO: Initialize sensor with type-specific configuration
    unsigned char is_valid_input = 1;
    Sensor current_sensor = sensors[*count];
    printf("Enter Sensor ID 0 - 255 \n");
    scanf("%hhu", &current_sensor.id);
    printf("Enter sensor name in 20 characters \n");
    scanf("%19s", &current_sensor.name);

    do
    {
        printf("Enter sensor type (0=TEMP, 1=HUMID, 2=PRES): ");
        scanf("%d", &current_sensor.type);
        switch (current_sensor.type)
        {
        case TEMPERATURE:
            current_sensor.type = TEMPERATURE;
            break;
        case HUMIDITY:
            current_sensor.type = HUMIDITY;
            break;
        case PRESSURE:
            current_sensor.type = PRESSURE;
            break;

        default:
            current_sensor.type = UNK;
            is_valid_input = 0;
            break;
        }
    } while (!is_valid_input);
    current_sensor.status = ACTIVE;
}

void read_sensor_data(Sensor *sensor)
{
    // TODO: Simulate sensor reading with random values
}

void process_sensor_data(Sensor *sensor)
{
    // TODO: Apply type-specific processing logic
    // TODO: Update sensor status based on processing
}

void display_sensors(Sensor *sensors, unsigned char count)
{
    // TODO: Display sensor details, readings, and status
}