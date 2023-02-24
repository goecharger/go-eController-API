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
<!-- MODBUS TABLE BEGIN -->
| Register                                                             | Registertyp | Datentyp | Name                         | Einheit          | Beschreibung |
| -------------------------------------------------------------------- | ----------- | -------- | ---------------------------- | ---------------- | ------------ |
| <!-- MODBUS-SET-ADDR: 40001 -->                                      |             |          |                              |                  |              |
| 40001 (0) <br /> 40002 (1)                                           | Input       | Float32  | Voltage L1                   | V (Volt)         |              |
| 40003 (2) <br /> 40004 (3)                                           | Input       | Float32  | Voltage L2                   | V (Volt)         |              |
| 40005 (4) <br /> 40006 (5)                                           | Input       | Float32  | Voltage L3                   | V (Volt)         |              |
| 40007 (6) <br /> 40008 (7)                                           | Input       | Float32  | Voltage N                    | V (Volt)         |              |
| 40009 (8) <br /> 40010 (9)                                           | Input       | Float32  | Frequency                    | Hz (Herz)        |              |
| 40011 (10) <br /> 40012 (11)                                         | Input       | Float32  | Current Sensor 1 Current     | A (Ampere)       |              |
| 40013 (12) <br /> 40014 (13)                                         | Input       | Float32  | Current Sensor 2 Current     | A (Ampere)       |              |
| 40015 (14) <br /> 40016 (15)                                         | Input       | Float32  | Current Sensor 3 Current     | A (Ampere)       |              |
| 40017 (16) <br /> 40018 (17)                                         | Input       | Float32  | Current Sensor 4 Current     | A (Ampere)       |              |
| 40019 (18) <br /> 40020 (19)                                         | Input       | Float32  | Current Sensor 5 Current     | A (Ampere)       |              |
| 40021 (20) <br /> 40022 (21)                                         | Input       | Float32  | Current Sensor 6 Current     | A (Ampere)       |              |
| 40023 (22) <br /> 40024 (23)                                         | Input       | Float32  | Current Sensor 1 Power       | W (Watt)         |              |
| 40025 (24) <br /> 40026 (25)                                         | Input       | Float32  | Current Sensor 2 Power       | W (Watt)         |              |
| 40027 (26) <br /> 40028 (27)                                         | Input       | Float32  | Current Sensor 3 Power       | W (Watt)         |              |
| 40029 (28) <br /> 40030 (29)                                         | Input       | Float32  | Current Sensor 4 Power       | W (Watt)         |              |
| 40031 (30) <br /> 40032 (31)                                         | Input       | Float32  | Current Sensor 5 Power       | W (Watt)         |              |
| 40033 (32) <br /> 40034 (33)                                         | Input       | Float32  | Current Sensor 6 Power       | W (Watt)         |              |
| 40035 (34) <br /> 40036 (35)                                         | Input       | Float32  | Current Sensor 1 Powerfactor | Factor 0.0 - 1.0 |              |
| 40037 (36) <br /> 40038 (37)                                         | Input       | Float32  | Current Sensor 2 Powerfactor | Factor 0.0 - 1.0 |              |
| 40039 (38) <br /> 40040 (39)                                         | Input       | Float32  | Current Sensor 3 Powerfactor | Factor 0.0 - 1.0 |              |
| 40041 (40) <br /> 40042 (41)                                         | Input       | Float32  | Current Sensor 4 Powerfactor | Factor 0.0 - 1.0 |              |
| 40043 (42) <br /> 40044 (43)                                         | Input       | Float32  | Current Sensor 5 Powerfactor | Factor 0.0 - 1.0 |              |
| 40045 (44) <br /> 40046 (45)                                         | Input       | Float32  | Current Sensor 6 Powerfactor | Factor 0.0 - 1.0 |              |
| 40047 (46) <br /> 40048 (47)                                         | Input       | Float32  | Category Home Current L1     | A (Ampere)       |              |
| 40049 (48) <br /> 40050 (49)                                         | Input       | Float32  | Category Home Current L2     | A (Ampere)       |              |
| 40051 (50) <br /> 40052 (51)                                         | Input       | Float32  | Category Home Current L3     | A (Ampere)       |              |
| 40053 (52) <br /> 40054 (53)                                         | Input       | Float32  | Category Home Power          | W (Watt)         |              |
| 40055 (54) <br /> 40056 (55) <br /> 40057 (56) <br /> 40058 (57)     | Input       | Float64  | Category Home Energy In      | Wh (Watt-Hours)  |              |
| 40059 (58) <br /> 40060 (59) <br /> 40061 (60) <br /> 40062 (61)     | Input       | Float64  | Category Home Energy Out     | Wh (Watt-Hours)  |              |
| 40063 (62) <br /> 40064 (63) <br /> 40065 (64) <br /> 40066 (65)     | Input       | Float64  | Category Home Money In       | Money            |              |
| 40067 (66) <br /> 40068 (67) <br /> 40069 (68) <br /> 40070 (69)     | Input       | Float64  | Category Home Money Out      | Money            |              |
| 40071 (70) <br /> 40072 (71)                                         | Input       | Float32  | Category Grid Current L1     | A (Ampere)       |              |
| 40073 (72) <br /> 40074 (73)                                         | Input       | Float32  | Category Grid Current L2     | A (Ampere)       |              |
| 40075 (74) <br /> 40076 (75)                                         | Input       | Float32  | Category Grid Current L3     | A (Ampere)       |              |
| 40077 (76) <br /> 40078 (77)                                         | Input       | Float32  | Category Grid Power          | W (Watt)         |              |
| 40079 (78) <br /> 40080 (79) <br /> 40081 (80) <br /> 40082 (81)     | Input       | Float64  | Category Grid Energy In      | Wh (Watt-Hours)  |              |
| 40083 (82) <br /> 40084 (83) <br /> 40085 (84) <br /> 40086 (85)     | Input       | Float64  | Category Grid Energy Out     | Wh (Watt-Hours)  |              |
| 40087 (86) <br /> 40088 (87) <br /> 40089 (88) <br /> 40090 (89)     | Input       | Float64  | Category Grid Money In       | Money            |              |
| 40091 (90) <br /> 40092 (91) <br /> 40093 (92) <br /> 40094 (93)     | Input       | Float64  | Category Grid Money Out      | Money            |              |
| 40095 (94) <br /> 40096 (95)                                         | Input       | Float32  | Category Car Current L1      | A (Ampere)       |              |
| 40097 (96) <br /> 40098 (97)                                         | Input       | Float32  | Category Car Current L2      | A (Ampere)       |              |
| 40099 (98) <br /> 40100 (99)                                         | Input       | Float32  | Category Car Current L3      | A (Ampere)       |              |
| 40101 (100) <br /> 40102 (101)                                       | Input       | Float32  | Category Car Power           | W (Watt)         |              |
| 40103 (102) <br /> 40104 (103) <br /> 40105 (104) <br /> 40106 (105) | Input       | Float64  | Category Car Energy In       | Wh (Watt-Hours)  |              |
| 40107 (106) <br /> 40108 (107) <br /> 40109 (108) <br /> 40110 (109) | Input       | Float64  | Category Car Energy Out      | Wh (Watt-Hours)  |              |
| 40111 (110) <br /> 40112 (111) <br /> 40113 (112) <br /> 40114 (113) | Input       | Float64  | Category Car Money In        | Money            |              |
| 40115 (114) <br /> 40116 (115) <br /> 40117 (116) <br /> 40118 (117) | Input       | Float64  | Category Car Money Out       | Money            |              |
| 40119 (118) <br /> 40120 (119)                                       | Input       | Float32  | Category Relais Current L1   | A (Ampere)       |              |
| 40121 (120) <br /> 40122 (121)                                       | Input       | Float32  | Category Relais Current L2   | A (Ampere)       |              |
| 40123 (122) <br /> 40124 (123)                                       | Input       | Float32  | Category Relais Current L3   | A (Ampere)       |              |
| 40125 (124) <br /> 40126 (125)                                       | Input       | Float32  | Category Relais Power        | W (Watt)         |              |
| 40127 (126) <br /> 40128 (127) <br /> 40129 (128) <br /> 40130 (129) | Input       | Float64  | Category Relais Energy In    | Wh (Watt-Hours)  |              |
| 40131 (130) <br /> 40132 (131) <br /> 40133 (132) <br /> 40134 (133) | Input       | Float64  | Category Relais Energy Out   | Wh (Watt-Hours)  |              |
| 40135 (134) <br /> 40136 (135) <br /> 40137 (136) <br /> 40138 (137) | Input       | Float64  | Category Relais Money In     | Money            |              |
| 40139 (138) <br /> 40140 (139) <br /> 40141 (140) <br /> 40142 (141) | Input       | Float64  | Category Relais Money Out    | Money            |              |
| 40143 (142) <br /> 40144 (143)                                       | Input       | Float32  | Category Solar Current L1    | A (Ampere)       |              |
| 40145 (144) <br /> 40146 (145)                                       | Input       | Float32  | Category Solar Current L2    | A (Ampere)       |              |
| 40147 (146) <br /> 40148 (147)                                       | Input       | Float32  | Category Solar Current L3    | A (Ampere)       |              |
| 40149 (148) <br /> 40150 (149)                                       | Input       | Float32  | Category Solar Power         | W (Watt)         |              |
| 40151 (150) <br /> 40152 (151) <br /> 40153 (152) <br /> 40154 (153) | Input       | Float64  | Category Solar Energy In     | Wh (Watt-Hours)  |              |
| 40155 (154) <br /> 40156 (155) <br /> 40157 (156) <br /> 40158 (157) | Input       | Float64  | Category Solar Energy Out    | Wh (Watt-Hours)  |              |
| 40159 (158) <br /> 40160 (159) <br /> 40161 (160) <br /> 40162 (161) | Input       | Float64  | Category Solar Money In      | Money            |              |
| 40163 (162) <br /> 40164 (163) <br /> 40165 (164) <br /> 40166 (165) | Input       | Float64  | Category Solar Money Out     | Money            |              |
| 40167 (166) <br /> 40168 (167)                                       | Input       | Float32  | Category Akku Current L1     | A (Ampere)       |              |
| 40169 (168) <br /> 40170 (169)                                       | Input       | Float32  | Category Akku Current L2     | A (Ampere)       |              |
| 40171 (170) <br /> 40172 (171)                                       | Input       | Float32  | Category Akku Current L3     | A (Ampere)       |              |
| 40173 (172) <br /> 40174 (173)                                       | Input       | Float32  | Category Akku Power          | W (Watt)         |              |
| 40175 (174) <br /> 40176 (175) <br /> 40177 (176) <br /> 40178 (177) | Input       | Float64  | Category Akku Energy In      | Wh (Watt-Hours)  |              |
| 40179 (178) <br /> 40180 (179) <br /> 40181 (180) <br /> 40182 (181) | Input       | Float64  | Category Akku Energy Out     | Wh (Watt-Hours)  |              |
| 40183 (182) <br /> 40184 (183) <br /> 40185 (184) <br /> 40186 (185) | Input       | Float64  | Category Akku Money In       | Money            |              |
| 40187 (186) <br /> 40188 (187) <br /> 40189 (188) <br /> 40190 (189) | Input       | Float64  | Category Akku Money Out      | Money            |              |
| <!-- MODBUS-SKIP-ADDR: 100 -->                                       |             |          |                              |                  |              |
| 40291 (290) <br /> 40292 (291)                                       | Input       | Float32  | Custom Category 0 Current L1 | A (Ampere)       |              |
| 40293 (292) <br /> 40294 (293)                                       | Input       | Float32  | Custom Category 0 Current L2 | A (Ampere)       |              |
| 40295 (294) <br /> 40296 (295)                                       | Input       | Float32  | Custom Category 0 Current L3 | A (Ampere)       |              |
| 40297 (296) <br /> 40298 (297)                                       | Input       | Float32  | Custom Category 0 Power      | W (Watt)         |              |
| 40299 (298) <br /> 40300 (299) <br /> 40301 (300) <br /> 40302 (301) | Input       | Float64  | Custom Category 0 Energy In  | Wh (Watt-Hours)  |              |
| 40303 (302) <br /> 40304 (303) <br /> 40305 (304) <br /> 40306 (305) | Input       | Float64  | Custom Category 0 Energy Out | Wh (Watt-Hours)  |              |
| 40307 (306) <br /> 40308 (307) <br /> 40309 (308) <br /> 40310 (309) | Input       | Float64  | Custom Category 0 Money In   | Money            |              |
| 40311 (310) <br /> 40312 (311) <br /> 40313 (312) <br /> 40314 (313) | Input       | Float64  | Custom Category 0 Money Out  | Money            |              |
| 40315 (314) <br /> 40316 (315)                                       | Input       | Float32  | Custom Category 1 Current L1 | A (Ampere)       |              |
| 40317 (316) <br /> 40318 (317)                                       | Input       | Float32  | Custom Category 1 Current L2 | A (Ampere)       |              |
| 40319 (318) <br /> 40320 (319)                                       | Input       | Float32  | Custom Category 1 Current L3 | A (Ampere)       |              |
| 40321 (320) <br /> 40322 (321)                                       | Input       | Float32  | Custom Category 1 Power      | W (Watt)         |              |
| 40323 (322) <br /> 40324 (323) <br /> 40325 (324) <br /> 40326 (325) | Input       | Float64  | Custom Category 1 Energy In  | Wh (Watt-Hours)  |              |
| 40327 (326) <br /> 40328 (327) <br /> 40329 (328) <br /> 40330 (329) | Input       | Float64  | Custom Category 1 Energy Out | Wh (Watt-Hours)  |              |
| 40331 (330) <br /> 40332 (331) <br /> 40333 (332) <br /> 40334 (333) | Input       | Float64  | Custom Category 1 Money In   | Money            |              |
| 40335 (334) <br /> 40336 (335) <br /> 40337 (336) <br /> 40338 (337) | Input       | Float64  | Custom Category 1 Money Out  | Money            |              |
| 40339 (338) <br /> 40340 (339)                                       | Input       | Float32  | Custom Category 2 Current L1 | A (Ampere)       |              |
| 40341 (340) <br /> 40342 (341)                                       | Input       | Float32  | Custom Category 2 Current L2 | A (Ampere)       |              |
| 40343 (342) <br /> 40344 (343)                                       | Input       | Float32  | Custom Category 2 Current L3 | A (Ampere)       |              |
| 40345 (344) <br /> 40346 (345)                                       | Input       | Float32  | Custom Category 2 Power      | W (Watt)         |              |
| 40347 (346) <br /> 40348 (347) <br /> 40349 (348) <br /> 40350 (349) | Input       | Float64  | Custom Category 2 Energy In  | Wh (Watt-Hours)  |              |
| 40351 (350) <br /> 40352 (351) <br /> 40353 (352) <br /> 40354 (353) | Input       | Float64  | Custom Category 2 Energy Out | Wh (Watt-Hours)  |              |
| 40355 (354) <br /> 40356 (355) <br /> 40357 (356) <br /> 40358 (357) | Input       | Float64  | Custom Category 2 Money In   | Money            |              |
| 40359 (358) <br /> 40360 (359) <br /> 40361 (360) <br /> 40362 (361) | Input       | Float64  | Custom Category 2 Money Out  | Money            |              |
| 40363 (362) <br /> 40364 (363)                                       | Input       | Float32  | Custom Category 3 Current L1 | A (Ampere)       |              |
| 40365 (364) <br /> 40366 (365)                                       | Input       | Float32  | Custom Category 3 Current L2 | A (Ampere)       |              |
| 40367 (366) <br /> 40368 (367)                                       | Input       | Float32  | Custom Category 3 Current L3 | A (Ampere)       |              |
| 40369 (368) <br /> 40370 (369)                                       | Input       | Float32  | Custom Category 3 Power      | W (Watt)         |              |
| 40371 (370) <br /> 40372 (371) <br /> 40373 (372) <br /> 40374 (373) | Input       | Float64  | Custom Category 3 Energy In  | Wh (Watt-Hours)  |              |
| 40375 (374) <br /> 40376 (375) <br /> 40377 (376) <br /> 40378 (377) | Input       | Float64  | Custom Category 3 Energy Out | Wh (Watt-Hours)  |              |
| 40379 (378) <br /> 40380 (379) <br /> 40381 (380) <br /> 40382 (381) | Input       | Float64  | Custom Category 3 Money In   | Money            |              |
| 40383 (382) <br /> 40384 (383) <br /> 40385 (384) <br /> 40386 (385) | Input       | Float64  | Custom Category 3 Money Out  | Money            |              |
| 40387 (386) <br /> 40388 (387)                                       | Input       | Float32  | Custom Category 4 Current L1 | A (Ampere)       |              |
| 40389 (388) <br /> 40390 (389)                                       | Input       | Float32  | Custom Category 4 Current L2 | A (Ampere)       |              |
| 40391 (390) <br /> 40392 (391)                                       | Input       | Float32  | Custom Category 4 Current L3 | A (Ampere)       |              |
| 40393 (392) <br /> 40394 (393)                                       | Input       | Float32  | Custom Category 4 Power      | W (Watt)         |              |
| 40395 (394) <br /> 40396 (395) <br /> 40397 (396) <br /> 40398 (397) | Input       | Float64  | Custom Category 4 Energy In  | Wh (Watt-Hours)  |              |
| 40399 (398) <br /> 40400 (399) <br /> 40401 (400) <br /> 40402 (401) | Input       | Float64  | Custom Category 4 Energy Out | Wh (Watt-Hours)  |              |
| 40403 (402) <br /> 40404 (403) <br /> 40405 (404) <br /> 40406 (405) | Input       | Float64  | Custom Category 4 Money In   | Money            |              |
| 40407 (406) <br /> 40408 (407) <br /> 40409 (408) <br /> 40410 (409) | Input       | Float64  | Custom Category 4 Money Out  | Money            |              |
| 40411 (410) <br /> 40412 (411)                                       | Input       | Float32  | Custom Category 5 Current L1 | A (Ampere)       |              |
| 40413 (412) <br /> 40414 (413)                                       | Input       | Float32  | Custom Category 5 Current L2 | A (Ampere)       |              |
| 40415 (414) <br /> 40416 (415)                                       | Input       | Float32  | Custom Category 5 Current L3 | A (Ampere)       |              |
| 40417 (416) <br /> 40418 (417)                                       | Input       | Float32  | Custom Category 5 Power      | W (Watt)         |              |
| 40419 (418) <br /> 40420 (419) <br /> 40421 (420) <br /> 40422 (421) | Input       | Float64  | Custom Category 5 Energy In  | Wh (Watt-Hours)  |              |
| 40423 (422) <br /> 40424 (423) <br /> 40425 (424) <br /> 40426 (425) | Input       | Float64  | Custom Category 5 Energy Out | Wh (Watt-Hours)  |              |
| 40427 (426) <br /> 40428 (427) <br /> 40429 (428) <br /> 40430 (429) | Input       | Float64  | Custom Category 5 Money In   | Money            |              |
| 40431 (430) <br /> 40432 (431) <br /> 40433 (432) <br /> 40434 (433) | Input       | Float64  | Custom Category 5 Money Out  | Money            |              |
| 40435 (434) <br /> 40436 (435)                                       | Input       | Float32  | Custom Category 6 Current L1 | A (Ampere)       |              |
| 40437 (436) <br /> 40438 (437)                                       | Input       | Float32  | Custom Category 6 Current L2 | A (Ampere)       |              |
| 40439 (438) <br /> 40440 (439)                                       | Input       | Float32  | Custom Category 6 Current L3 | A (Ampere)       |              |
| 40441 (440) <br /> 40442 (441)                                       | Input       | Float32  | Custom Category 6 Power      | W (Watt)         |              |
| 40443 (442) <br /> 40444 (443) <br /> 40445 (444) <br /> 40446 (445) | Input       | Float64  | Custom Category 6 Energy In  | Wh (Watt-Hours)  |              |
| 40447 (446) <br /> 40448 (447) <br /> 40449 (448) <br /> 40450 (449) | Input       | Float64  | Custom Category 6 Energy Out | Wh (Watt-Hours)  |              |
| 40451 (450) <br /> 40452 (451) <br /> 40453 (452) <br /> 40454 (453) | Input       | Float64  | Custom Category 6 Money In   | Money            |              |
| 40455 (454) <br /> 40456 (455) <br /> 40457 (456) <br /> 40458 (457) | Input       | Float64  | Custom Category 6 Money Out  | Money            |              |
| 40459 (458) <br /> 40460 (459)                                       | Input       | Float32  | Custom Category 7 Current L1 | A (Ampere)       |              |
| 40461 (460) <br /> 40462 (461)                                       | Input       | Float32  | Custom Category 7 Current L2 | A (Ampere)       |              |
| 40463 (462) <br /> 40464 (463)                                       | Input       | Float32  | Custom Category 7 Current L3 | A (Ampere)       |              |
| 40465 (464) <br /> 40466 (465)                                       | Input       | Float32  | Custom Category 7 Power      | W (Watt)         |              |
| 40467 (466) <br /> 40468 (467) <br /> 40469 (468) <br /> 40470 (469) | Input       | Float64  | Custom Category 7 Energy In  | Wh (Watt-Hours)  |              |
| 40471 (470) <br /> 40472 (471) <br /> 40473 (472) <br /> 40474 (473) | Input       | Float64  | Custom Category 7 Energy Out | Wh (Watt-Hours)  |              |
| 40475 (474) <br /> 40476 (475) <br /> 40477 (476) <br /> 40478 (477) | Input       | Float64  | Custom Category 7 Money In   | Money            |              |
| 40479 (478) <br /> 40480 (479) <br /> 40481 (480) <br /> 40482 (481) | Input       | Float64  | Custom Category 7 Money Out  | Money            |              |
| 40483 (482) <br /> 40484 (483)                                       | Input       | Float32  | Custom Category 8 Current L1 | A (Ampere)       |              |
| 40485 (484) <br /> 40486 (485)                                       | Input       | Float32  | Custom Category 8 Current L2 | A (Ampere)       |              |
| 40487 (486) <br /> 40488 (487)                                       | Input       | Float32  | Custom Category 8 Current L3 | A (Ampere)       |              |
| 40489 (488) <br /> 40490 (489)                                       | Input       | Float32  | Custom Category 8 Power      | W (Watt)         |              |
| 40491 (490) <br /> 40492 (491) <br /> 40493 (492) <br /> 40494 (493) | Input       | Float64  | Custom Category 8 Energy In  | Wh (Watt-Hours)  |              |
| 40495 (494) <br /> 40496 (495) <br /> 40497 (496) <br /> 40498 (497) | Input       | Float64  | Custom Category 8 Energy Out | Wh (Watt-Hours)  |              |
| 40499 (498) <br /> 40500 (499) <br /> 40501 (500) <br /> 40502 (501) | Input       | Float64  | Custom Category 8 Money In   | Money            |              |
| 40503 (502) <br /> 40504 (503) <br /> 40505 (504) <br /> 40506 (505) | Input       | Float64  | Custom Category 8 Money Out  | Money            |              |
| 40507 (506) <br /> 40508 (507)                                       | Input       | Float32  | Custom Category 9 Current L1 | A (Ampere)       |              |
| 40509 (508) <br /> 40510 (509)                                       | Input       | Float32  | Custom Category 9 Current L2 | A (Ampere)       |              |
| 40511 (510) <br /> 40512 (511)                                       | Input       | Float32  | Custom Category 9 Current L3 | A (Ampere)       |              |
| 40513 (512) <br /> 40514 (513)                                       | Input       | Float32  | Custom Category 9 Power      | W (Watt)         |              |
| 40515 (514) <br /> 40516 (515) <br /> 40517 (516) <br /> 40518 (517) | Input       | Float64  | Custom Category 9 Energy In  | Wh (Watt-Hours)  |              |
| 40519 (518) <br /> 40520 (519) <br /> 40521 (520) <br /> 40522 (521) | Input       | Float64  | Custom Category 9 Energy Out | Wh (Watt-Hours)  |              |
| 40523 (522) <br /> 40524 (523) <br /> 40525 (524) <br /> 40526 (525) | Input       | Float64  | Custom Category 9 Money In   | Money            |              |
| 40527 (526) <br /> 40528 (527) <br /> 40529 (528) <br /> 40530 (529) | Input       | Float64  | Custom Category 9 Money Out  | Money            |              |
<!-- MODBUS TABLE END -->
