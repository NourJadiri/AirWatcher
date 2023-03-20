# AirWatcher 
A government agency for environmental protection needs to monitor the air quality of a large
territory. The agency has installed a number of sensors for this purpose, which are spread evenly over
the territory. The sensors generate data at regular intervals. The data are gathered by the agency and
stored on a central server in a set of files in CSV format.


The sensors are listed in the file sensors.csv. A sensor is described in the following format:
SensorID;Latitude;Longitude;
`(Example: Sensor0;44;-1;)`


The measurements from all the sensors are given in the file measurements.csv. Each sensor
measurement is represented by a single line in the following format:
`Timestamp;SensorID;AttributeID;Value;`
`(Example: 2019-01-01 12:00:00;Sensor0;O3;50.25;)`
A sensor generates measurements of four different types, which are described in the file
attributes.csv as follows:
```csv
AttributeID,Unit;Description;
(Example: O3;µg/m3;concentration d'ozone;)
```

The AirWatcher application will allow analysis of the data generated by a sensor to make sure that it
is functioning correctly. This will help the government agency to identify and maintain
malfunctioning sensors.


Moreover, the application will aggregate the collected information to produce statistics that may help
the agency in making decisions about improving the quality of air. For example, the application will
allow the calculation of the mean of the quality of air in a circular area specified by the user. The
mean of the quality of air may be calculated for a given moment, as well as for a specified period of
time.
The application will also enable selecting one sensor and then scoring and ranking all other sensors
in terms of similarity to the selected sensor. The similarity will be based on the data generated by the
sensors during a specified period of time. The purpose of this functionality is to identify areas with
similar air quality.


Another functionality required for the AirWatcher application is to produce the value of air quality at
a precise geographical position in the territory at a given moment. Please note that there may or may
not be a sensor present at the specified position.