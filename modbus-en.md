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

| Register                                                             | Registertype | Datatype  | Name                          | Unit             | Description          |
| -------------------------------------------------------------------- | ------------ | --------- | ----------------------------- | ---------------- | -------------------- |
| 30001 (0) <br /> 30002 (1)                                           | Input        | Float32   | Voltage L1                    | V (Volt)         |                      |
| 30003 (2) <br /> 30004 (3)                                           | Input        | Float32   | Voltage L2                    | V (Volt)         |                      |
| 30005 (4) <br /> 30006 (5)                                           | Input        | Float32   | Voltage L3                    | V (Volt)         |                      |
| 30007 (6) <br /> 30008 (7)                                           | Input        | Float32   | Voltage N                     | V (Volt)         |                      |
| 30009 (8) <br /> 30010 (9)                                           | Input        | Float32   | Frequency                     | Hz (Herz)        |                      |
| 30011 (10) <br /> 30012 (11)                                         | Input        | Float32   | Current Sensor 1 Current      | A (Ampere)       |                      |
| 30013 (12) <br /> 30014 (13)                                         | Input        | Float32   | Current Sensor 2 Current      | A (Ampere)       |                      |
| 30015 (14) <br /> 30016 (15)                                         | Input        | Float32   | Current Sensor 3 Current      | A (Ampere)       |                      |
| 30017 (16) <br /> 30018 (17)                                         | Input        | Float32   | Current Sensor 4 Current      | A (Ampere)       |                      |
| 30019 (18) <br /> 30020 (19)                                         | Input        | Float32   | Current Sensor 5 Current      | A (Ampere)       |                      |
| 30021 (20) <br /> 30022 (21)                                         | Input        | Float32   | Current Sensor 6 Current      | A (Ampere)       |                      |
| 30023 (22) <br /> 30024 (23)                                         | Input        | Float32   | Current Sensor 1 Power        | W (Watt)         |                      |
| 30025 (24) <br /> 30026 (25)                                         | Input        | Float32   | Current Sensor 2 Power        | W (Watt)         |                      |
| 30027 (26) <br /> 30028 (27)                                         | Input        | Float32   | Current Sensor 3 Power        | W (Watt)         |                      |
| 30029 (28) <br /> 30030 (29)                                         | Input        | Float32   | Current Sensor 4 Power        | W (Watt)         |                      |
| 30031 (30) <br /> 30032 (31)                                         | Input        | Float32   | Current Sensor 5 Power        | W (Watt)         |                      |
| 30033 (32) <br /> 30034 (33)                                         | Input        | Float32   | Current Sensor 6 Power        | W (Watt)         |                      |
| 30035 (34) <br /> 30036 (35)                                         | Input        | Float32   | Current Sensor 1 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30037 (36) <br /> 30038 (37)                                         | Input        | Float32   | Current Sensor 2 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30039 (38) <br /> 30040 (39)                                         | Input        | Float32   | Current Sensor 3 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30041 (40) <br /> 30042 (41)                                         | Input        | Float32   | Current Sensor 4 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30043 (42) <br /> 30044 (43)                                         | Input        | Float32   | Current Sensor 5 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30045 (44) <br /> 30046 (45)                                         | Input        | Float32   | Current Sensor 6 Powerfactor  | Factor 0.0 - 1.0 |                      |
| 30047 (46) <br /> 30048 (47)                                         | Input        | Float32   | Category Home Current L1      | A (Ampere)       |                      |
| 30049 (48) <br /> 30050 (49)                                         | Input        | Float32   | Category Home Current L2      | A (Ampere)       |                      |
| 30051 (50) <br /> 30052 (51)                                         | Input        | Float32   | Category Home Current L3      | A (Ampere)       |                      |
| 30053 (52) <br /> 30054 (53)                                         | Input        | Float32   | Category Home Power           | W (Watt)         |                      |
| 30055 (54) <br /> 30056 (55) <br /> 30057 (56) <br /> 30058 (57)     | Input        | Float64   | Category Home Energy In       | Wh (Watt-Hours)  |                      |
| 30059 (58) <br /> 30060 (59) <br /> 30061 (60) <br /> 30062 (61)     | Input        | Float64   | Category Home Energy Out      | Wh (Watt-Hours)  |                      |
| 30063 (54) <br /> 30064 (55) <br /> 30065 (56) <br /> 30066 (57)     | Input        | Float64   | Category Home Money In        | Money            |                      |
| 30067 (58) <br /> 30068 (59) <br /> 30069 (60) <br /> 30070 (61)     | Input        | Float64   | Category Home Money Out       | Money            |                      |
| 30071 (62) <br /> 30072 (63)                                         | Input        | Float32   | Category Grid Current L1      | A (Ampere)       |                      |
| 30073 (64) <br /> 30074 (65)                                         | Input        | Float32   | Category Grid Current L2      | A (Ampere)       |                      |
| 30075 (66) <br /> 30076 (67)                                         | Input        | Float32   | Category Grid Current L3      | A (Ampere)       |                      |
| 30077 (68) <br /> 30078 (69)                                         | Input        | Float32   | Category Grid Power           | W (Watt)         |                      |
| 30079 (70) <br /> 30080 (71) <br /> 30081 (72) <br /> 30082 (73)     | Input        | Float64   | Category Grid Energy In       | Wh (Watt-Hours)  |                      |
| 30083 (74) <br /> 30084 (75) <br /> 30085 (76) <br /> 30086 (77)     | Input        | Float64   | Category Grid Energy Out      | Wh (Watt-Hours)  |                      |
| 30087 (70) <br /> 30088 (71) <br /> 30089 (72) <br /> 30090 (73)     | Input        | Float64   | Category Grid Money In        | Money            |                      |
| 30091 (74) <br /> 30092 (75) <br /> 30093 (76) <br /> 30094 (77)     | Input        | Float64   | Category Grid Money Out       | Money            |                      |
| 30095 (78) <br /> 30096 (79)                                         | Input        | Float32   | Category Car Current L1       | A (Ampere)       |                      |
| 30097 (80) <br /> 30098 (81)                                         | Input        | Float32   | Category Car Current L2       | A (Ampere)       |                      |
| 30099 (82) <br /> 30100 (83)                                         | Input        | Float32   | Category Car Current L3       | A (Ampere)       |                      |
| 30101 (84) <br /> 30102 (85)                                         | Input        | Float32   | Category Car Power            | W (Watt)         |                      |
| 30103 (86) <br /> 30104 (87) <br /> 30105 (88) <br /> 30106 (89)     | Input        | Float64   | Category Car Energy In        | Wh (Watt-Hours)  |                      |
| 30107 (90) <br /> 30108 (91) <br /> 30109 (92) <br /> 30110 (93)     | Input        | Float64   | Category Car Energy Out       | Wh (Watt-Hours)  |                      |
| 30111 (86) <br /> 30112 (87) <br /> 30113 (88) <br /> 30114 (89)     | Input        | Float64   | Category Car Money In         | Money            |                      |
| 30115 (90) <br /> 30116 (91) <br /> 30117 (92) <br /> 30118 (93)     | Input        | Float64   | Category Car Money Out        | Money            |                      |
| 30119 (94) <br /> 30120 (95)                                         | Input        | Float32   | Category Relais Current L1    | A (Ampere)       |                      |
| 30121 (96) <br /> 30122 (97)                                         | Input        | Float32   | Category Relais Current L2    | A (Ampere)       |                      |
| 30123 (98) <br /> 30124 (99)                                         | Input        | Float32   | Category Relais Current L3    | A (Ampere)       |                      |
| 30125 (100) <br /> 30126 (101)                                       | Input        | Float32   | Category Relais Power         | W (Watt)         |                      |
| 30127 (102) <br /> 30128 (103) <br /> 30129 (104) <br /> 30130 (105) | Input        | Float64   | Category Relais Energy In     | Wh (Watt-Hours)  |                      |
| 30131 (106) <br /> 30132 (107) <br /> 30133 (108) <br /> 30134 (109) | Input        | Float64   | Category Relais Energy Out    | Wh (Watt-Hours)  |                      |
| 30135 (102) <br /> 30136 (103) <br /> 30137 (104) <br /> 30138 (105) | Input        | Float64   | Category Relais Money In      | Money            |                      |
| 30139 (106) <br /> 30140 (107) <br /> 30141 (108) <br /> 30142 (109) | Input        | Float64   | Category Relais Money Out     | Money            |                      |
| 30143 (110) <br /> 30144 (111)                                       | Input        | Float32   | Category Solar Current L1     | A (Ampere)       |                      |
| 30145 (112) <br /> 30146 (113)                                       | Input        | Float32   | Category Solar Current L2     | A (Ampere)       |                      |
| 30147 (114) <br /> 30148 (115)                                       | Input        | Float32   | Category Solar Current L3     | A (Ampere)       |                      |
| 30149 (116) <br /> 30150 (117)                                       | Input        | Float32   | Category Solar Power          | W (Watt)         |                      |
| 30151 (118) <br /> 30152 (119) <br /> 30153 (120) <br /> 30154 (121) | Input        | Float64   | Category Solar Energy In      | Wh (Watt-Hours)  |                      |
| 30155 (122) <br /> 30156 (123) <br /> 30157 (124) <br /> 30158 (125) | Input        | Float64   | Category Solar Energy Out     | Wh (Watt-Hours)  |                      |
| 30159 (118) <br /> 30160 (119) <br /> 30161 (120) <br /> 30162 (121) | Input        | Float64   | Category Solar Money In       | Money            |                      |
| 30163 (122) <br /> 30164 (123) <br /> 30165 (124) <br /> 30166 (125) | Input        | Float64   | Category Solar Money Out      | Money            |                      |
| 30167 (126) <br /> 30168 (127)                                       | Input        | Float32   | Category Akku Current L1      | A (Ampere)       |                      |
| 30169 (128) <br /> 30170 (129)                                       | Input        | Float32   | Category Akku Current L2      | A (Ampere)       |                      |
| 30171 (130) <br /> 30172 (131)                                       | Input        | Float32   | Category Akku Current L3      | A (Ampere)       |                      |
| 30173 (132) <br /> 30174 (133)                                       | Input        | Float32   | Category Akku Power           | W (Watt)         |                      |
| 30175 (134) <br /> 30176 (135) <br /> 30177 (136) <br /> 30178 (137) | Input        | Float64   | Category Akku Energy In       | Wh (Watt-Hours)  |                      |
| 30179 (138) <br /> 30180 (139) <br /> 30181 (140) <br /> 30182 (141) | Input        | Float64   | Category Akku Energy Out      | Wh (Watt-Hours)  |                      |
| 30183 (134) <br /> 30184 (135) <br /> 30185 (136) <br /> 30186 (137) | Input        | Float64   | Category Akku Money In        | Money            |                      |
| 30187 (138) <br /> 30188 (139) <br /> 30189 (140) <br /> 30190 (141) | Input        | Float64   | Category Akku Money Out       | Money            |                      |
| 30287 (206) <br /> 30288 (207)                                       | Input        | Float32   | Custom Category 0 Current L1  | A (Ampere)       |                      |
| 30289 (208) <br /> 30290 (209)                                       | Input        | Float32   | Custom Category 0 Current L2  | A (Ampere)       |                      |
| 30291 (210) <br /> 30292 (211)                                       | Input        | Float32   | Custom Category 0 Current L3  | A (Ampere)       |                      |
| 30293 (212) <br /> 30294 (213)                                       | Input        | Float32   | Custom Category 0 Power       | W (Watt)         |                      |
| 30295 (214) <br /> 30296 (215) <br /> 30297 (216) <br /> 30298 (217) | Input        | Float64   | Custom Category 0 Energy In   | Wh (Watt-Hours)  |                      |
| 30299 (218) <br /> 30300 (219) <br /> 30301 (220) <br /> 30302 (221) | Input        | Float64   | Custom Category 0 Energy Out  | Wh (Watt-Hours)  |                      |
| 30303 (214) <br /> 30304 (215) <br /> 30305 (216) <br /> 30306 (217) | Input        | Float64   | Custom Category 0 Money In    | Money            |                      |
| 30307 (218) <br /> 30308 (219) <br /> 30309 (220) <br /> 30310 (221) | Input        | Float64   | Custom Category 0 Money Out   | Money            |                      |
| 30311 (222) <br /> 30312 (223)                                       | Input        | Float32   | Custom Category 1 Current L1  | A (Ampere)       |                      |
| 30313 (224) <br /> 30314 (225)                                       | Input        | Float32   | Custom Category 1 Current L2  | A (Ampere)       |                      |
| 30315 (226) <br /> 30316 (227)                                       | Input        | Float32   | Custom Category 1 Current L3  | A (Ampere)       |                      |
| 30317 (228) <br /> 30318 (229)                                       | Input        | Float32   | Custom Category 1 Power       | W (Watt)         |                      |
| 30319 (230) <br /> 30320 (231) <br /> 30321 (232) <br /> 30322 (233) | Input        | Float64   | Custom Category 1 Energy In   | Wh (Watt-Hours)  |                      |
| 30323 (234) <br /> 30324 (235) <br /> 30325 (236) <br /> 30326 (237) | Input        | Float64   | Custom Category 1 Energy Out  | Wh (Watt-Hours)  |                      |
| 30327 (230) <br /> 30328 (231) <br /> 30329 (232) <br /> 30330 (233) | Input        | Float64   | Custom Category 1 Money In    | Money            |                      |
| 30331 (234) <br /> 30332 (235) <br /> 30333 (236) <br /> 30334 (237) | Input        | Float64   | Custom Category 1 Money Out   | Money            |                      |
| 30335 (238) <br /> 30336 (239)                                       | Input        | Float32   | Custom Category 2 Current L1  | A (Ampere)       |                      |
| 30337 (240) <br /> 30338 (241)                                       | Input        | Float32   | Custom Category 2 Current L2  | A (Ampere)       |                      |
| 30339 (242) <br /> 30340 (243)                                       | Input        | Float32   | Custom Category 2 Current L3  | A (Ampere)       |                      |
| 30341 (244) <br /> 30342 (245)                                       | Input        | Float32   | Custom Category 2 Power       | W (Watt)         |                      |
| 30343 (246) <br /> 30344 (247) <br /> 30345 (248) <br /> 30346 (249) | Input        | Float64   | Custom Category 2 Energy In   | Wh (Watt-Hours)  |                      |
| 30347 (250) <br /> 30348 (251) <br /> 30349 (252) <br /> 30350 (253) | Input        | Float64   | Custom Category 2 Energy Out  | Wh (Watt-Hours)  |                      |
| 30351 (246) <br /> 30352 (247) <br /> 30353 (248) <br /> 30354 (249) | Input        | Float64   | Custom Category 2 Money In    | Money            |                      |
| 30355 (250) <br /> 30356 (251) <br /> 30357 (252) <br /> 30358 (253) | Input        | Float64   | Custom Category 2 Money Out   | Money            |                      |
| 30359 (254) <br /> 30360 (255)                                       | Input        | Float32   | Custom Category 3 Current L1  | A (Ampere)       |                      |
| 30361 (256) <br /> 30362 (257)                                       | Input        | Float32   | Custom Category 3 Current L2  | A (Ampere)       |                      |
| 30363 (258) <br /> 30364 (259)                                       | Input        | Float32   | Custom Category 3 Current L3  | A (Ampere)       |                      |
| 30365 (260) <br /> 30366 (261)                                       | Input        | Float32   | Custom Category 3 Power       | W (Watt)         |                      |
| 30367 (262) <br /> 30368 (263) <br /> 30369 (264) <br /> 30370 (265) | Input        | Float64   | Custom Category 3 Energy In   | Wh (Watt-Hours)  |                      |
| 30371 (266) <br /> 30372 (267) <br /> 30373 (268) <br /> 30374 (269) | Input        | Float64   | Custom Category 3 Energy Out  | Wh (Watt-Hours)  |                      |
| 30375 (262) <br /> 30376 (263) <br /> 30377 (264) <br /> 30378 (265) | Input        | Float64   | Custom Category 3 Money In    | Money            |                      |
| 30379 (266) <br /> 30380 (267) <br /> 30381 (268) <br /> 30382 (269) | Input        | Float64   | Custom Category 3 Money Out   | Money            |                      |
| 30383 (270) <br /> 30384 (271)                                       | Input        | Float32   | Custom Category 4 Current L1  | A (Ampere)       |                      |
| 30385 (272) <br /> 30386 (273)                                       | Input        | Float32   | Custom Category 4 Current L2  | A (Ampere)       |                      |
| 30387 (274) <br /> 30388 (275)                                       | Input        | Float32   | Custom Category 4 Current L3  | A (Ampere)       |                      |
| 30389 (276) <br /> 30390 (277)                                       | Input        | Float32   | Custom Category 4 Power       | W (Watt)         |                      |
| 30391 (278) <br /> 30392 (279) <br /> 30393 (280) <br /> 30394 (281) | Input        | Float64   | Custom Category 4 Energy In   | Wh (Watt-Hours)  |                      |
| 30395 (282) <br /> 30396 (283) <br /> 30397 (284) <br /> 30398 (285) | Input        | Float64   | Custom Category 4 Energy Out  | Wh (Watt-Hours)  |                      |
| 30399 (278) <br /> 30400 (279) <br /> 30401 (280) <br /> 30402 (281) | Input        | Float64   | Custom Category 4 Money In    | Money            |                      |
| 30403 (282) <br /> 30404 (283) <br /> 30405 (284) <br /> 30406 (285) | Input        | Float64   | Custom Category 4 Money Out   | Money            |                      |
| 30407 (286) <br /> 30408 (287)                                       | Input        | Float32   | Custom Category 5 Current L1  | A (Ampere)       |                      |
| 30409 (288) <br /> 30410 (289)                                       | Input        | Float32   | Custom Category 5 Current L2  | A (Ampere)       |                      |
| 30411 (290) <br /> 30412 (291)                                       | Input        | Float32   | Custom Category 5 Current L3  | A (Ampere)       |                      |
| 30413 (292) <br /> 30414 (293)                                       | Input        | Float32   | Custom Category 5 Power       | W (Watt)         |                      |
| 30415 (294) <br /> 30416 (295) <br /> 30417 (296) <br /> 30418 (297) | Input        | Float64   | Custom Category 5 Energy In   | Wh (Watt-Hours)  |                      |
| 30419 (298) <br /> 30420 (299) <br /> 30421 (300) <br /> 30422 (301) | Input        | Float64   | Custom Category 5 Energy Out  | Wh (Watt-Hours)  |                      |
| 30423 (294) <br /> 30424 (295) <br /> 30425 (296) <br /> 30426 (297) | Input        | Float64   | Custom Category 5 Money In    | Money            |                      |
| 30427 (298) <br /> 30428 (299) <br /> 30429 (300) <br /> 30430 (301) | Input        | Float64   | Custom Category 5 Money Out   | Money            |                      |
| 30431 (302) <br /> 30432 (303)                                       | Input        | Float32   | Custom Category 6 Current L1  | A (Ampere)       |                      |
| 30433 (304) <br /> 30434 (305)                                       | Input        | Float32   | Custom Category 6 Current L2  | A (Ampere)       |                      |
| 30435 (306) <br /> 30436 (307)                                       | Input        | Float32   | Custom Category 6 Current L3  | A (Ampere)       |                      |
| 30437 (308) <br /> 30438 (309)                                       | Input        | Float32   | Custom Category 6 Power       | W (Watt)         |                      |
| 30439 (310) <br /> 30440 (311) <br /> 30441 (312) <br /> 30442 (313) | Input        | Float64   | Custom Category 6 Energy In   | Wh (Watt-Hours)  |                      |
| 30443 (314) <br /> 30444 (315) <br /> 30445 (316) <br /> 30446 (317) | Input        | Float64   | Custom Category 6 Energy Out  | Wh (Watt-Hours)  |                      |
| 30447 (310) <br /> 30448 (311) <br /> 30449 (312) <br /> 30450 (313) | Input        | Float64   | Custom Category 6 Money In    | Money            |                      |
| 30451 (314) <br /> 30452 (315) <br /> 30453 (316) <br /> 30454 (317) | Input        | Float64   | Custom Category 6 Money Out   | Money            |                      |
| 30455 (318) <br /> 30456 (319)                                       | Input        | Float32   | Custom Category 7 Current L1  | A (Ampere)       |                      |
| 30457 (320) <br /> 30458 (321)                                       | Input        | Float32   | Custom Category 7 Current L2  | A (Ampere)       |                      |
| 30459 (322) <br /> 30460 (323)                                       | Input        | Float32   | Custom Category 7 Current L3  | A (Ampere)       |                      |
| 30461 (324) <br /> 30462 (325)                                       | Input        | Float32   | Custom Category 7 Power       | W (Watt)         |                      |
| 30463 (326) <br /> 30464 (327) <br /> 30465 (328) <br /> 30466 (329) | Input        | Float64   | Custom Category 7 Energy In   | Wh (Watt-Hours)  |                      |
| 30467 (330) <br /> 30468 (331) <br /> 30469 (332) <br /> 30470 (333) | Input        | Float64   | Custom Category 7 Energy Out  | Wh (Watt-Hours)  |                      |
| 30471 (326) <br /> 30472 (327) <br /> 30473 (328) <br /> 30474 (329) | Input        | Float64   | Custom Category 7 Money In    | Money            |                      |
| 30475 (330) <br /> 30476 (331) <br /> 30477 (332) <br /> 30478 (333) | Input        | Float64   | Custom Category 7 Money Out   | Money            |                      |
| 30479 (334) <br /> 30480 (335)                                       | Input        | Float32   | Custom Category 8 Current L1  | A (Ampere)       |                      |
| 30481 (336) <br /> 30482 (337)                                       | Input        | Float32   | Custom Category 8 Current L2  | A (Ampere)       |                      |
| 30483 (338) <br /> 30484 (339)                                       | Input        | Float32   | Custom Category 8 Current L3  | A (Ampere)       |                      |
| 30485 (340) <br /> 30486 (341)                                       | Input        | Float32   | Custom Category 8 Power       | W (Watt)         |                      |
| 30487 (342) <br /> 30488 (343) <br /> 30489 (344) <br /> 30490 (345) | Input        | Float64   | Custom Category 8 Energy In   | Wh (Watt-Hours)  |                      |
| 30491 (346) <br /> 30492 (347) <br /> 30493 (348) <br /> 30494 (349) | Input        | Float64   | Custom Category 8 Energy Out  | Wh (Watt-Hours)  |                      |
| 30495 (342) <br /> 30496 (343) <br /> 30497 (344) <br /> 30498 (345) | Input        | Float64   | Custom Category 8 Money In    | Money            |                      |
| 30499 (346) <br /> 30500 (347) <br /> 30501 (348) <br /> 30502 (349) | Input        | Float64   | Custom Category 8 Money Out   | Money            |                      |
| 30503 (350) <br /> 30504 (351)                                       | Input        | Float32   | Custom Category 9 Current L1  | A (Ampere)       |                      |
| 30505 (352) <br /> 30506 (353)                                       | Input        | Float32   | Custom Category 9 Current L2  | A (Ampere)       |                      |
| 30507 (354) <br /> 30508 (355)                                       | Input        | Float32   | Custom Category 9 Current L3  | A (Ampere)       |                      |
| 30509 (356) <br /> 30510 (357)                                       | Input        | Float32   | Custom Category 9 Power       | W (Watt)         |                      |
| 30511 (358) <br /> 30512 (359) <br /> 30513 (360) <br /> 30514 (361) | Input        | Float64   | Custom Category 9 Energy In   | Wh (Watt-Hours)  |                      |
| 30515 (362) <br /> 30516 (363) <br /> 30517 (364) <br /> 30518 (365) | Input        | Float64   | Custom Category 9 Energy Out  | Wh (Watt-Hours)  |                      |
| 30519 (358) <br /> 30520 (359) <br /> 30521 (360) <br /> 30522 (361) | Input        | Float64   | Custom Category 9 Money In    | Money            |                      |
| 30523 (362) <br /> 30524 (363) <br /> 30525 (364) <br /> 30526 (365) | Input        | Float64   | Custom Category 9 Money Out   | Money            |                      |