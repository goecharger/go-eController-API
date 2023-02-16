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

| Register                   | Registertyp | Datentyp  | Name       | Einheit   | Beschreibung         |
| -------------------------- | ----------- | --------- | ---------- | --------- | -------------------- |
| 30001 (0) <br /> 30002 (1) | Input       | Float32   | Voltage L1 | V (Volt)  |                      |
| 30003 (2) <br /> 30004 (3) | Input       | Float32   | Voltage L2 | V (Volt)  |                      |
| 30005 (4) <br /> 30006 (5) | Input       | Float32   | Voltage L3 | V (Volt)  |                      |
| 30007 (6) <br /> 30008 (7) | Input       | Float32   | Voltage N  | V (Volt)  |                      |
| 30009 (8) <br /> 30010 (9) | Input       | Float32   | Frequency  | Hz (Herz) |                      |
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