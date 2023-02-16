Deutsch &bull; [English](modbus-en.md)

# Modbus

Die go-eController bieten ein Modbus TCP Interface an, mit dem einige Leistungs- und Energiewerte abgefragt werden können. Dieses Interface muss erst über die App oder [http API](http-de.md) aktiviert werden.

Live-Messwerte können über die [Modbus Funktion 4](https://www.simplymodbus.ca/FC04.htm) abgeholt werden.

Einstellungen können über die [Modbus Funktion 3](https://www.simplymodbus.ca/FC03.htm) gelesen und über die [Modbus Funktion 16](https://www.simplymodbus.ca/FC16.htm) gesetzt werden.

Nach Aktivierung kann der TCP Port 502 verwendet werden.

| Funktion Nr | Name                      | Unterstützt?                                 |
| ----------- | ------------------------- | -------------------------------------------- |
| 01          | Read Coil Status          | Nein                                         |
| 02          | Read Input Status         | Nein                                         |
| 03          | Read Holding Registers    | Ja, für alle Live-Werte unten aufgelistet    |
| 04          | Read Input Registers      | Ja, für alle Einstellungen unten aufgelistet |
| 05          | Force Single Coil         | Nein                                         |
| 06          | Preset Single Register    | Nein                                         |
| 15          | Force Multiple Coils      | Nein                                         |
| 16          | Read Input Registers      | Ja, für alle Einstellungen unten aufgelistet |

## Über die App das Modbus Interface aktivieren und prüfen

Unten im Tab "Internet", dann "Erweiterte Einstelluingen" im Menü anwählen, dann relativ weit unten bei Modbus

<img src="screenshots/modbus-app-enable.png?raw=true" width="200" />

## Über die http API das Modbus interface aktivieren und prüfen

Die Chargers verfügen über API Keys zum Konfigurieren und Prüfen des Modbus interface. Diese API Keys können mit der http api verwendet werden.

Beispiel: http://192.168.0.77/api/set?men=true

| api key | Beschreibung                 | Datentyp | R?W? | Kategorie |
| ------- | ---------------------------- | -------- | ---- | --------- |
| men     | modbus slave aktiviert       | bool     | R/W  | Config    |
| msp     | modbus slave port (erfordert Neustart) | uint16 | R/W | Config |
| msb     | modbus slave Bytes vertauschen | bool     | R/W  | Config    |
| msr     | modbus slave Register vertauschen | bool     | R/W  | Config    |
| mro     | modbus slave Lese-Operationen | size_t   | R    | Status    |
| mwo     | modbus slave Schreib-Operationen | size_t  | R    | Status    |

## Modbus Profil

| Register                                                         | Registertyp  | Datentyp  | Name                                   | Einheit                   | Beschreibung         |
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