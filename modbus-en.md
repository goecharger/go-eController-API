[Deutsch](modbus-de.md) &bull; English

# Modbus

The go-eController has a Modbus TCP Interface an which can be used to read some power and energy values. This interface has to be enabled from the app or the [http API](http-en.md).

Live Values can be received with [Modbus function 4](https://www.simplymodbus.ca/FC04.htm).

Settings can be read with the [Modbus function 3](https://www.simplymodbus.ca/FC03.htm) and can be written with the [Modbus function 16](https://www.simplymodbus.ca/FC16.htm).

After enabling the tcp port 502 is used.

| Function No | Name                      | Supported?                          |
| ----------- | ------------------------- | ----------------------------------- |
| 01          | Read Coil Status          | No                                  |
| 02          | Read Input Status         | No                                  |
| 03          | Read Holding Registers    | Yes, for all registers listed below |
| 04          | Read Input Registers      | Yes, for all registers listed below |
| 05          | Force Single Coil         | No                                  |
| 06          | Preset Single Register    | No                                  |
| 15          | Force Multiple Coils      | No                                  |
| 16          | Read Input Registers      | Yes, for all registers listed below |

## Using the App to enable and verify the Modbus interface

Tap the tab "Internet" at the bottom, then click on "Advanced Settings" in the menu, then at the very bottom "Modbus"

<img src="screenshots/modbus-app-enable.png?raw=true" width="200" />

## Using the http API to enable and verify the Modbus interface

The chargers provide api keys to configure and verify the modbus interface. These api keys can be used with the http api.

Example: http://192.168.0.77/api/set?men=true

| api key | description                  | datatype | R?W? | Category |
| ------- | ---------------------------- | -------- | ---- | -------- |
| men     | modbus slave enabled         | bool     | R/W  | Config   |
| msp     | modbus slave port (requires reboot) | uint16 | R/W | Config |
| msb     | modbus slave swap bytes      | bool     | R/W  | Config   |
| msr     | modbus slave swap registers  | bool     | R/W  | Config   |
| mro     | modbus slave read operations | size_t   | R    | Status   |
| mwo     | modbus slave write operations | size_t  | R    | Status   |

## Modbus Profile

| Register                                                         | Registertype | Datatype  | Name                                   | Unit                      | Description          |
| ---------------------------------------------------------------- | ------------ | --------- | -------------------------------------- | ------------------------- | -------------------- |
| 30001 (0) <br /> 30002 (1)                                       | Input        | Float32   | Voltage L1                             | V (Volt)                  |                      |
| 30003 (2) <br /> 30004 (3)                                       | Input        | Float32   | Voltage L2                             | V (Volt)                  |                      |
| 30005 (4) <br /> 30006 (5)                                       | Input        | Float32   | Voltage L3                             | V (Volt)                  |                      |
| 30007 (6) <br /> 30008 (7)                                       | Input        | Float32   | Voltage N                              | V (Volt)                  |                      |
| 30009 (8) <br /> 30010 (9)                                       | Input        | Float32   | Frequency                              | Hz (Herz)                 |                      |
| 30009 (10) <br /> 30012 (11)                                     | Input        | Float32   | Current Sensor 1 Current               | A (Ampere)                |                      |
| 30009 (12) <br /> 30014 (13)                                     | Input        | Float32   | Current Sensor 2 Current               | A (Ampere)                |                      |
| 30009 (14) <br /> 30016 (15)                                     | Input        | Float32   | Current Sensor 3 Current               | A (Ampere)                |                      |
| 30009 (16) <br /> 30018 (17)                                     | Input        | Float32   | Current Sensor 4 Current               | A (Ampere)                |                      |
| 30009 (18) <br /> 30020 (19)                                     | Input        | Float32   | Current Sensor 5 Current               | A (Ampere)                |                      |
| 30009 (20) <br /> 30022 (21)                                     | Input        | Float32   | Current Sensor 6 Current               | A (Ampere)                |                      |
| 30009 (22) <br /> 30024 (23)                                     | Input        | Float32   | Current Sensor 1 Power                 | W (Watt)                  |                      |
| 30009 (24) <br /> 30026 (25)                                     | Input        | Float32   | Current Sensor 2 Power                 | W (Watt)                  |                      |
| 30009 (26) <br /> 30028 (27)                                     | Input        | Float32   | Current Sensor 3 Power                 | W (Watt)                  |                      |
| 30009 (28) <br /> 30030 (29)                                     | Input        | Float32   | Current Sensor 4 Power                 | W (Watt)                  |                      |
| 30009 (30) <br /> 30032 (31)                                     | Input        | Float32   | Current Sensor 5 Power                 | W (Watt)                  |                      |
| 30009 (32) <br /> 30034 (33)                                     | Input        | Float32   | Current Sensor 6 Power                 | W (Watt)                  |                      |
| 30009 (34) <br /> 30036 (35)                                     | Input        | Float32   | Current Sensor 1 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (36) <br /> 30038 (37)                                     | Input        | Float32   | Current Sensor 2 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (38) <br /> 30040 (39)                                     | Input        | Float32   | Current Sensor 3 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (40) <br /> 30042 (41)                                     | Input        | Float32   | Current Sensor 4 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (42) <br /> 30044 (43)                                     | Input        | Float32   | Current Sensor 5 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (44) <br /> 30046 (45)                                     | Input        | Float32   | Current Sensor 6 Powerfactor           | Factor 0.0 - 1.0          |                      |
| 30009 (46) <br /> 30048 (47)                                     | Input        | Float32   | Category Home Current L1               | A (Ampere)                |                      |
| 30009 (48) <br /> 30050 (49)                                     | Input        | Float32   | Category Home Current L2               | A (Ampere)                |                      |
| 30009 (50) <br /> 30052 (51)                                     | Input        | Float32   | Category Home Current L3               | A (Ampere)                |                      |
| 30009 (52) <br /> 30054 (53)                                     | Input        | Float32   | Category Home Power                    | W (Watt)                  |                      |
| 30055 (54) <br /> 30056 (55) <br /> 30057 (56) <br /> 30058 (57) | Input        | Float64   | Category Home Energy In                | Wh (Watt-Hours)           |                      |
| 30059 (58) <br /> 30060 (59) <br /> 30061 (60) <br /> 30062 (61) | Input        | Float64   | Category Home Energy Out               | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Grid Current L1               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Grid Current L2               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Grid Current L3               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Grid Power                    | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Grid Energy In                | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Grid Energy Out               | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Car Current L1                | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Car Current L2                | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Car Current L3                | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Car Power                     | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Car Energy In                 | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Car Energy Out                | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Relais Current L1             | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Relais Current L2             | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Relais Current L3             | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Relais Power                  | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Relais Energy In              | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Relais Energy Out             | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Solar Current L1              | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Solar Current L2              | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Solar Current L3              | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Solar Power                   | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Solar Energy In               | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Solar Energy Out              | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Akku Current L1               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Akku Current L2               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Akku Current L3               | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Akku Power                    | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Akku Energy In                | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Akku Energy Out               | Wh (Watt-Hours)           |                      |
| // space lassen für 4 zukünftige fixe Kategorien |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 0 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 0 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 0 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 0 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 0 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 0 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 1 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 1 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 1 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 1 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 1 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 1 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 2 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 2 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 2 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 2 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 2 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 2 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 3 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 3 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 3 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 3 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 3 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 3 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 4 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 4 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 4 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 4 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 4 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 4 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 5 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 5 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 5 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 5 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 5 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 5 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 6 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 6 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 6 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 6 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 6 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 6 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 7 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 7 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 7 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 7 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 7 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 7 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 8 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 8 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 8 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 8 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 8 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 8 Energy Out  | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 9 Current L1  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 9 Current L2  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 9 Current L3  | A (Ampere)                |                      |
| XXXXX (XX) <br /> XXXXX (XX)                                     | Input        | Float32   | Category Custom Category 9 Power       | W (Watt)                  |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 9 Energy In   | Wh (Watt-Hours)           |                      |
| XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) <br /> XXXXX (XX) | Input        | Float64   | Category Custom Category 9 Energy Out  | Wh (Watt-Hours)           |                      |