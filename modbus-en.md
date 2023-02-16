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

| Register                   | Registertype | Datatype  | Name       | Unit      | Description          |
| -------------------------- | ------------ | --------- | ---------- | --------- | -------------------- |
| 30001 (0) <br /> 30002 (1) | Input        | Float32   | Voltage L1 | V (Volt)  |                      |
| 30003 (2) <br /> 30004 (3) | Input        | Float32   | Voltage L2 | V (Volt)  |                      |
| 30005 (4) <br /> 30006 (5) | Input        | Float32   | Voltage L3 | V (Volt)  |                      |
| 30007 (6) <br /> 30008 (7) | Input        | Float32   | Voltage N  | V (Volt)  |                      |
| 30009 (8) <br /> 30010 (9) | Input        | Float32   | Frequency  | Hz (Herz) |                      |
Current Sensor 1 Current
Current Sensor 2 Current
Current Sensor 3 Current
Current Sensor 4 Current
Current Sensor 5 Current
Current Sensor 6 Current
Current Sensor 1 Power
Current Sensor 2 Power
Current Sensor 3 Power
Current Sensor 4 Power
Current Sensor 5 Power
Current Sensor 6 Power
Current Sensor 1 Powerfactor
Current Sensor 2 Powerfactor
Current Sensor 3 Powerfactor
Current Sensor 4 Powerfactor
Current Sensor 5 Powerfactor
Current Sensor 6 Powerfactor
Category Home Current L1
Category Home Current L2
Category Home Current L3
Category Home Power
Category Home Energy In
Category Home Energy Out
Category Grid Current L1
Category Grid Current L2
Category Grid Current L3
Category Grid Power
Category Grid Energy In
Category Grid Energy Out
Category Car Current L1
Category Car Current L2
Category Car Current L3
Category Car Power
Category Car Energy In
Category Car Energy Out
Category Relais Current L1
Category Relais Current L2
Category Relais Current L3
Category Relais Power
Category Relais Energy In
Category Relais Energy Out
Category Solar Current L1
Category Solar Current L2
Category Solar Current L3
Category Solar Power
Category Solar Energy In
Category Solar Energy Out
Category Akku Current L1
Category Akku Current L2
Category Akku Current L3
Category Akku Power
Category Akku Energy In
Category Akku Energy Out
// space lassen für 4 zukünftige fixe Kategorien
Category Custom Category 0 Current L1
Category Custom Category 0 Current L2
Category Custom Category 0 Current L3
Category Custom Category 0 Power
Category Custom Category 0 Energy In
Category Custom Category 0 Energy Out
Category Custom Category 1 Current L1
Category Custom Category 1 Current L2
Category Custom Category 1 Current L3
Category Custom Category 1 Power
Category Custom Category 1 Energy In
Category Custom Category 1 Energy Out
Category Custom Category 2 Current L1
Category Custom Category 2 Current L2
Category Custom Category 2 Current L3
Category Custom Category 2 Power
Category Custom Category 2 Energy In
Category Custom Category 2 Energy Out
Category Custom Category 3 Current L1
Category Custom Category 3 Current L2
Category Custom Category 3 Current L3
Category Custom Category 3 Power
Category Custom Category 3 Energy In
Category Custom Category 3 Energy Out
Category Custom Category 4 Current L1
Category Custom Category 4 Current L2
Category Custom Category 4 Current L3
Category Custom Category 4 Power
Category Custom Category 4 Energy In
Category Custom Category 4 Energy Out
Category Custom Category 5 Current L1
Category Custom Category 5 Current L2
Category Custom Category 5 Current L3
Category Custom Category 5 Power
Category Custom Category 5 Energy In
Category Custom Category 5 Energy Out
Category Custom Category 6 Current L1
Category Custom Category 6 Current L2
Category Custom Category 6 Current L3
Category Custom Category 6 Power
Category Custom Category 6 Energy In
Category Custom Category 6 Energy Out
Category Custom Category 7 Current L1
Category Custom Category 7 Current L2
Category Custom Category 7 Current L3
Category Custom Category 7 Power
Category Custom Category 7 Energy In
Category Custom Category 7 Energy Out
Category Custom Category 8 Current L1
Category Custom Category 8 Current L2
Category Custom Category 8 Current L3
Category Custom Category 8 Power
Category Custom Category 8 Energy In
Category Custom Category 8 Energy Out
Category Custom Category 9 Current L1
Category Custom Category 9 Current L2
Category Custom Category 9 Current L3
Category Custom Category 9 Power
Category Custom Category 9 Energy In
Category Custom Category 9 Energy Out