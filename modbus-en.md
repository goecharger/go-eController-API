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

| Register (wire-format)                                               | Registertype | Datatype  | Name                          | Unit             | Description          |
| -------------------------------------------------------------------- | ------------ | --------- | ----------------------------- | ---------------- | -------------------- |
| 30001 (0 <br /> 30002 (1                                             | Input        | Float32   | Voltage L1                    | V (Volt)         |                      |
| 30003 (2 <br /> 30004 (3                                             | Input        | Float32   | Voltage L2                    | V (Volt)         |                      |
| 30005 (4 <br /> 30006 (5                                             | Input        | Float32   | Voltage L3                    | V (Volt)         |                      |
| 30007 (6 <br /> 30008 (7                                             | Input        | Float32   | Voltage N                     | V (Volt)         |                      |
| 30009 (8 <br /> 30010 (9                                             | Input        | Float32   | Frequency                     | Hz (Herz)        |                      |
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
| 30063 (62) <br /> 30064 (63)                                         | Input        | Float32   | Category Grid Current L1      | A (Ampere)       |                      |
| 30065 (64) <br /> 30066 (65)                                         | Input        | Float32   | Category Grid Current L2      | A (Ampere)       |                      |
| 30067 (66) <br /> 30068 (67)                                         | Input        | Float32   | Category Grid Current L3      | A (Ampere)       |                      |
| 30069 (68) <br /> 30070 (69)                                         | Input        | Float32   | Category Grid Power           | W (Watt)         |                      |
| 30071 (70) <br /> 30072 (71) <br /> 30073 (72) <br /> 30074 (73)     | Input        | Float64   | Category Grid Energy In       | Wh (Watt-Hours)  |                      |
| 30075 (74) <br /> 30076 (75) <br /> 30077 (76) <br /> 30078 (77)     | Input        | Float64   | Category Grid Energy Out      | Wh (Watt-Hours)  |                      |
| 30079 (78) <br /> 30080 (79)                                         | Input        | Float32   | Category Car Current L1       | A (Ampere)       |                      |
| 30081 (80) <br /> 30082 (81)                                         | Input        | Float32   | Category Car Current L2       | A (Ampere)       |                      |
| 30083 (82) <br /> 30084 (83)                                         | Input        | Float32   | Category Car Current L3       | A (Ampere)       |                      |
| 30085 (84) <br /> 30086 (85)                                         | Input        | Float32   | Category Car Power            | W (Watt)         |                      |
| 30087 (86) <br /> 30088 (87) <br /> 30089 (88) <br /> 30090 (89)     | Input        | Float64   | Category Car Energy In        | Wh (Watt-Hours)  |                      |
| 30091 (90) <br /> 30092 (91) <br /> 30093 (92) <br /> 30094 (93)     | Input        | Float64   | Category Car Energy Out       | Wh (Watt-Hours)  |                      |
| 30095 (94) <br /> 30096 (95)                                         | Input        | Float32   | Category Relais Current L1    | A (Ampere)       |                      |
| 30097 (96) <br /> 30098 (97)                                         | Input        | Float32   | Category Relais Current L2    | A (Ampere)       |                      |
| 30099 (98) <br /> 30100 (99)                                         | Input        | Float32   | Category Relais Current L3    | A (Ampere)       |                      |
| 30101 (100) <br /> 30102 (101)                                       | Input        | Float32   | Category Relais Power         | W (Watt)         |                      |
| 30103 (102) <br /> 30104 (103) <br /> 30105 (104) <br /> 30106 (105) | Input        | Float64   | Category Relais Energy In     | Wh (Watt-Hours)  |                      |
| 30107 (106) <br /> 30108 (107) <br /> 30109 (108) <br /> 30110 (109) | Input        | Float64   | Category Relais Energy Out    | Wh (Watt-Hours)  |                      |
| 30111 (110) <br /> 30112 (111)                                       | Input        | Float32   | Category Solar Current L1     | A (Ampere)       |                      |
| 30113 (112) <br /> 30114 (113)                                       | Input        | Float32   | Category Solar Current L2     | A (Ampere)       |                      |
| 30115 (114) <br /> 30116 (115)                                       | Input        | Float32   | Category Solar Current L3     | A (Ampere)       |                      |
| 30117 (116) <br /> 30118 (117)                                       | Input        | Float32   | Category Solar Power          | W (Watt)         |                      |
| 30119 (118) <br /> 30120 (119) <br /> 30121 (120) <br /> 30122 (121) | Input        | Float64   | Category Solar Energy In      | Wh (Watt-Hours)  |                      |
| 30123 (122) <br /> 30124 (123) <br /> 30125 (124) <br /> 30126 (125) | Input        | Float64   | Category Solar Energy Out     | Wh (Watt-Hours)  |                      |
| 30127 (126) <br /> 30128 (127)                                       | Input        | Float32   | Category Akku Current L1      | A (Ampere)       |                      |
| 30129 (128) <br /> 30130 (129)                                       | Input        | Float32   | Category Akku Current L2      | A (Ampere)       |                      |
| 30131 (130) <br /> 30132 (131)                                       | Input        | Float32   | Category Akku Current L3      | A (Ampere)       |                      |
| 30133 (132) <br /> 30134 (133)                                       | Input        | Float32   | Category Akku Power           | W (Watt)         |                      |
| 30135 (134) <br /> 30136 (135) <br /> 30137 (136) <br /> 30138 (137) | Input        | Float64   | Category Akku Energy In       | Wh (Watt-Hours)  |                      |
| 30139 (138) <br /> 30140 (139) <br /> 30141 (140) <br /> 30142 (141) | Input        | Float64   | Category Akku Energy Out      | Wh (Watt-Hours)  |                      |
| 30207 (206) <br /> 30208 (207)                                       | Input        | Float32   | Custom Category 0 Current L1  | A (Ampere)       |                      |
| 30209 (208) <br /> 30210 (209)                                       | Input        | Float32   | Custom Category 0 Current L2  | A (Ampere)       |                      |
| 30211 (210) <br /> 30212 (211)                                       | Input        | Float32   | Custom Category 0 Current L3  | A (Ampere)       |                      |
| 30213 (212) <br /> 30214 (213)                                       | Input        | Float32   | Custom Category 0 Power       | W (Watt)         |                      |
| 30215 (214) <br /> 30216 (215) <br /> 30217 (216) <br /> 30218 (217) | Input        | Float64   | Custom Category 0 Energy In   | Wh (Watt-Hours)  |                      |
| 30219 (218) <br /> 30220 (219) <br /> 30221 (220) <br /> 30222 (221) | Input        | Float64   | Custom Category 0 Energy Out  | Wh (Watt-Hours)  |                      |
| 30223 (222) <br /> 30224 (223)                                       | Input        | Float32   | Custom Category 1 Current L1  | A (Ampere)       |                      |
| 30225 (224) <br /> 30226 (225)                                       | Input        | Float32   | Custom Category 1 Current L2  | A (Ampere)       |                      |
| 30227 (226) <br /> 30228 (227)                                       | Input        | Float32   | Custom Category 1 Current L3  | A (Ampere)       |                      |
| 30229 (228) <br /> 30230 (229)                                       | Input        | Float32   | Custom Category 1 Power       | W (Watt)         |                      |
| 30231 (230) <br /> 30232 (231) <br /> 30233 (232) <br /> 30234 (233) | Input        | Float64   | Custom Category 1 Energy In   | Wh (Watt-Hours)  |                      |
| 30235 (234) <br /> 30236 (235) <br /> 30237 (236) <br /> 30238 (237) | Input        | Float64   | Custom Category 1 Energy Out  | Wh (Watt-Hours)  |                      |
| 30239 (238) <br /> 30240 (239)                                       | Input        | Float32   | Custom Category 2 Current L1  | A (Ampere)       |                      |
| 30241 (240) <br /> 30242 (241)                                       | Input        | Float32   | Custom Category 2 Current L2  | A (Ampere)       |                      |
| 30243 (242) <br /> 30244 (243)                                       | Input        | Float32   | Custom Category 2 Current L3  | A (Ampere)       |                      |
| 30245 (244) <br /> 30246 (245)                                       | Input        | Float32   | Custom Category 2 Power       | W (Watt)         |                      |
| 30247 (246) <br /> 30248 (247) <br /> 30249 (248) <br /> 30250 (249) | Input        | Float64   | Custom Category 2 Energy In   | Wh (Watt-Hours)  |                      |
| 30251 (250) <br /> 30252 (251) <br /> 30253 (252) <br /> 30254 (253) | Input        | Float64   | Custom Category 2 Energy Out  | Wh (Watt-Hours)  |                      |
| 30255 (254) <br /> 30256 (255)                                       | Input        | Float32   | Custom Category 3 Current L1  | A (Ampere)       |                      |
| 30257 (256) <br /> 30258 (257)                                       | Input        | Float32   | Custom Category 3 Current L2  | A (Ampere)       |                      |
| 30259 (258) <br /> 30260 (259)                                       | Input        | Float32   | Custom Category 3 Current L3  | A (Ampere)       |                      |
| 30261 (260) <br /> 30262 (261)                                       | Input        | Float32   | Custom Category 3 Power       | W (Watt)         |                      |
| 30263 (262) <br /> 30264 (263) <br /> 30265 (264) <br /> 30266 (265) | Input        | Float64   | Custom Category 3 Energy In   | Wh (Watt-Hours)  |                      |
| 30267 (266) <br /> 30268 (267) <br /> 30269 (268) <br /> 30270 (269) | Input        | Float64   | Custom Category 3 Energy Out  | Wh (Watt-Hours)  |                      |
| 30271 (270) <br /> 30272 (271)                                       | Input        | Float32   | Custom Category 4 Current L1  | A (Ampere)       |                      |
| 30273 (272) <br /> 30274 (273)                                       | Input        | Float32   | Custom Category 4 Current L2  | A (Ampere)       |                      |
| 30275 (274) <br /> 30276 (275)                                       | Input        | Float32   | Custom Category 4 Current L3  | A (Ampere)       |                      |
| 30277 (276) <br /> 30278 (277)                                       | Input        | Float32   | Custom Category 4 Power       | W (Watt)         |                      |
| 30279 (278) <br /> 30280 (279) <br /> 30281 (280) <br /> 30282 (281) | Input        | Float64   | Custom Category 4 Energy In   | Wh (Watt-Hours)  |                      |
| 30283 (282) <br /> 30284 (283) <br /> 30285 (284) <br /> 30286 (285) | Input        | Float64   | Custom Category 4 Energy Out  | Wh (Watt-Hours)  |                      |
| 30287 (286) <br /> 30288 (287)                                       | Input        | Float32   | Custom Category 5 Current L1  | A (Ampere)       |                      |
| 30289 (288) <br /> 30290 (289)                                       | Input        | Float32   | Custom Category 5 Current L2  | A (Ampere)       |                      |
| 30291 (290) <br /> 30292 (291)                                       | Input        | Float32   | Custom Category 5 Current L3  | A (Ampere)       |                      |
| 30293 (292) <br /> 30294 (293)                                       | Input        | Float32   | Custom Category 5 Power       | W (Watt)         |                      |
| 30295 (294) <br /> 30296 (295) <br /> 30297 (296) <br /> 30298 (297) | Input        | Float64   | Custom Category 5 Energy In   | Wh (Watt-Hours)  |                      |
| 30299 (298) <br /> 30300 (299) <br /> 30301 (300) <br /> 30302 (301) | Input        | Float64   | Custom Category 5 Energy Out  | Wh (Watt-Hours)  |                      |
| 30303 (302) <br /> 30304 (303)                                       | Input        | Float32   | Custom Category 6 Current L1  | A (Ampere)       |                      |
| 30305 (304) <br /> 30306 (305)                                       | Input        | Float32   | Custom Category 6 Current L2  | A (Ampere)       |                      |
| 30307 (306) <br /> 30308 (307)                                       | Input        | Float32   | Custom Category 6 Current L3  | A (Ampere)       |                      |
| 30309 (308) <br /> 30310 (309)                                       | Input        | Float32   | Custom Category 6 Power       | W (Watt)         |                      |
| 30311 (310) <br /> 30312 (311) <br /> 30313 (312) <br /> 30314 (313) | Input        | Float64   | Custom Category 6 Energy In   | Wh (Watt-Hours)  |                      |
| 30315 (314) <br /> 30316 (315) <br /> 30317 (316) <br /> 30318 (317) | Input        | Float64   | Custom Category 6 Energy Out  | Wh (Watt-Hours)  |                      |
| 30319 (318) <br /> 30320 (319)                                       | Input        | Float32   | Custom Category 7 Current L1  | A (Ampere)       |                      |
| 30321 (320) <br /> 30322 (321)                                       | Input        | Float32   | Custom Category 7 Current L2  | A (Ampere)       |                      |
| 30323 (322) <br /> 30324 (323)                                       | Input        | Float32   | Custom Category 7 Current L3  | A (Ampere)       |                      |
| 30325 (324) <br /> 30326 (325)                                       | Input        | Float32   | Custom Category 7 Power       | W (Watt)         |                      |
| 30327 (326) <br /> 30328 (327) <br /> 30329 (328) <br /> 30330 (329) | Input        | Float64   | Custom Category 7 Energy In   | Wh (Watt-Hours)  |                      |
| 30331 (330) <br /> 30332 (331) <br /> 30333 (332) <br /> 30334 (333) | Input        | Float64   | Custom Category 7 Energy Out  | Wh (Watt-Hours)  |                      |
| 30335 (334) <br /> 30336 (335)                                       | Input        | Float32   | Custom Category 8 Current L1  | A (Ampere)       |                      |
| 30337 (336) <br /> 30338 (337)                                       | Input        | Float32   | Custom Category 8 Current L2  | A (Ampere)       |                      |
| 30339 (338) <br /> 30340 (339)                                       | Input        | Float32   | Custom Category 8 Current L3  | A (Ampere)       |                      |
| 30341 (340) <br /> 30342 (341)                                       | Input        | Float32   | Custom Category 8 Power       | W (Watt)         |                      |
| 30343 (342) <br /> 30344 (343) <br /> 30345 (344) <br /> 30346 (345) | Input        | Float64   | Custom Category 8 Energy In   | Wh (Watt-Hours)  |                      |
| 30347 (346) <br /> 30348 (347) <br /> 30349 (348) <br /> 30350 (349) | Input        | Float64   | Custom Category 8 Energy Out  | Wh (Watt-Hours)  |                      |
| 30351 (350) <br /> 30352 (351)                                       | Input        | Float32   | Custom Category 9 Current L1  | A (Ampere)       |                      |
| 30353 (352) <br /> 30354 (353)                                       | Input        | Float32   | Custom Category 9 Current L2  | A (Ampere)       |                      |
| 30355 (354) <br /> 30356 (355)                                       | Input        | Float32   | Custom Category 9 Current L3  | A (Ampere)       |                      |
| 30357 (356) <br /> 30358 (357)                                       | Input        | Float32   | Custom Category 9 Power       | W (Watt)         |                      |
| 30359 (358) <br /> 30360 (359) <br /> 30361 (360) <br /> 30362 (361) | Input        | Float64   | Custom Category 9 Energy In   | Wh (Watt-Hours)  |                      |
| 30363 (362) <br /> 30364 (363) <br /> 30365 (364) <br /> 30366 (365) | Input        | Float64   | Custom Category 9 Energy Out  | Wh (Watt-Hours)  |                      |