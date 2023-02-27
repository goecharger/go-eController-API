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
<!-- MODBUS TABLE BEGIN -->
| Register                                                                 | Registertype | Datatype | Name                         | Unit             | Description |
| ------------------------------------------------------------------------ | ------------ | -------- | ---------------------------- | ---------------- | ----------- |
| <!-- MODBUS-SET-ADDR: 41001 -->                                          |              |          |                              |                  |             |
| 41001 (1000) <br /> 41002 (1001)                                         | Input        | Float32  | Voltage L1                   | V (Volt)         |             |
| 41003 (1002) <br /> 41004 (1003)                                         | Input        | Float32  | Voltage L2                   | V (Volt)         |             |
| 41005 (1004) <br /> 41006 (1005)                                         | Input        | Float32  | Voltage L3                   | V (Volt)         |             |
| 41007 (1006) <br /> 41008 (1007)                                         | Input        | Float32  | Voltage N                    | V (Volt)         |             |
| 41009 (1008) <br /> 41010 (1009)                                         | Input        | Float32  | Frequency                    | Hz (Herz)        |             |
| 41011 (1010) <br /> 41012 (1011)                                         | Input        | Float32  | Current Sensor 1 Current     | A (Ampere)       |             |
| 41013 (1012) <br /> 41014 (1013)                                         | Input        | Float32  | Current Sensor 2 Current     | A (Ampere)       |             |
| 41015 (1014) <br /> 41016 (1015)                                         | Input        | Float32  | Current Sensor 3 Current     | A (Ampere)       |             |
| 41017 (1016) <br /> 41018 (1017)                                         | Input        | Float32  | Current Sensor 4 Current     | A (Ampere)       |             |
| 41019 (1018) <br /> 41020 (1019)                                         | Input        | Float32  | Current Sensor 5 Current     | A (Ampere)       |             |
| 41021 (1020) <br /> 41022 (1021)                                         | Input        | Float32  | Current Sensor 6 Current     | A (Ampere)       |             |
| 41023 (1022) <br /> 41024 (1023)                                         | Input        | Float32  | Current Sensor 1 Power       | W (Watt)         |             |
| 41025 (1024) <br /> 41026 (1025)                                         | Input        | Float32  | Current Sensor 2 Power       | W (Watt)         |             |
| 41027 (1026) <br /> 41028 (1027)                                         | Input        | Float32  | Current Sensor 3 Power       | W (Watt)         |             |
| 41029 (1028) <br /> 41030 (1029)                                         | Input        | Float32  | Current Sensor 4 Power       | W (Watt)         |             |
| 41031 (1030) <br /> 41032 (1031)                                         | Input        | Float32  | Current Sensor 5 Power       | W (Watt)         |             |
| 41033 (1032) <br /> 41034 (1033)                                         | Input        | Float32  | Current Sensor 6 Power       | W (Watt)         |             |
| 41035 (1034) <br /> 41036 (1035)                                         | Input        | Float32  | Current Sensor 1 Powerfactor | Factor 0.0 - 1.0 |             |
| 41037 (1036) <br /> 41038 (1037)                                         | Input        | Float32  | Current Sensor 2 Powerfactor | Factor 0.0 - 1.0 |             |
| 41039 (1038) <br /> 41040 (1039)                                         | Input        | Float32  | Current Sensor 3 Powerfactor | Factor 0.0 - 1.0 |             |
| 41041 (1040) <br /> 41042 (1041)                                         | Input        | Float32  | Current Sensor 4 Powerfactor | Factor 0.0 - 1.0 |             |
| 41043 (1042) <br /> 41044 (1043)                                         | Input        | Float32  | Current Sensor 5 Powerfactor | Factor 0.0 - 1.0 |             |
| 41045 (1044) <br /> 41046 (1045)                                         | Input        | Float32  | Current Sensor 6 Powerfactor | Factor 0.0 - 1.0 |             |
| 41047 (1046) <br /> 41048 (1047)                                         | Input        | Float32  | Category Home Current L1     | A (Ampere)       |             |
| 41049 (1048) <br /> 41050 (1049)                                         | Input        | Float32  | Category Home Current L2     | A (Ampere)       |             |
| 41051 (1050) <br /> 41052 (1051)                                         | Input        | Float32  | Category Home Current L3     | A (Ampere)       |             |
| 41053 (1052) <br /> 41054 (1053)                                         | Input        | Float32  | Category Home Power          | W (Watt)         |             |
| 41055 (1054) <br /> 41056 (1055) <br /> 41057 (1056) <br /> 41058 (1057) | Input        | Float64  | Category Home Energy In      | Wh (Watt-Hours)  |             |
| 41059 (1058) <br /> 41060 (1059) <br /> 41061 (1060) <br /> 41062 (1061) | Input        | Float64  | Category Home Energy Out     | Wh (Watt-Hours)  |             |
| 41063 (1062) <br /> 41064 (1063) <br /> 41065 (1064) <br /> 41066 (1065) | Input        | Float64  | Category Home Money In       | Money            |             |
| 41067 (1066) <br /> 41068 (1067) <br /> 41069 (1068) <br /> 41070 (1069) | Input        | Float64  | Category Home Money Out      | Money            |             |
| 41071 (1070) <br /> 41072 (1071)                                         | Input        | Float32  | Category Grid Current L1     | A (Ampere)       |             |
| 41073 (1072) <br /> 41074 (1073)                                         | Input        | Float32  | Category Grid Current L2     | A (Ampere)       |             |
| 41075 (1074) <br /> 41076 (1075)                                         | Input        | Float32  | Category Grid Current L3     | A (Ampere)       |             |
| 41077 (1076) <br /> 41078 (1077)                                         | Input        | Float32  | Category Grid Power          | W (Watt)         |             |
| 41079 (1078) <br /> 41080 (1079) <br /> 41081 (1080) <br /> 41082 (1081) | Input        | Float64  | Category Grid Energy In      | Wh (Watt-Hours)  |             |
| 41083 (1082) <br /> 41084 (1083) <br /> 41085 (1084) <br /> 41086 (1085) | Input        | Float64  | Category Grid Energy Out     | Wh (Watt-Hours)  |             |
| 41087 (1086) <br /> 41088 (1087) <br /> 41089 (1088) <br /> 41090 (1089) | Input        | Float64  | Category Grid Money In       | Money            |             |
| 41091 (1090) <br /> 41092 (1091) <br /> 41093 (1092) <br /> 41094 (1093) | Input        | Float64  | Category Grid Money Out      | Money            |             |
| 41095 (1094) <br /> 41096 (1095)                                         | Input        | Float32  | Category Car Current L1      | A (Ampere)       |             |
| 41097 (1096) <br /> 41098 (1097)                                         | Input        | Float32  | Category Car Current L2      | A (Ampere)       |             |
| 41099 (1098) <br /> 41100 (1099)                                         | Input        | Float32  | Category Car Current L3      | A (Ampere)       |             |
| 41101 (1100) <br /> 41102 (1101)                                         | Input        | Float32  | Category Car Power           | W (Watt)         |             |
| 41103 (1102) <br /> 41104 (1103) <br /> 41105 (1104) <br /> 41106 (1105) | Input        | Float64  | Category Car Energy In       | Wh (Watt-Hours)  |             |
| 41107 (1106) <br /> 41108 (1107) <br /> 41109 (1108) <br /> 41110 (1109) | Input        | Float64  | Category Car Energy Out      | Wh (Watt-Hours)  |             |
| 41111 (1110) <br /> 41112 (1111) <br /> 41113 (1112) <br /> 41114 (1113) | Input        | Float64  | Category Car Money In        | Money            |             |
| 41115 (1114) <br /> 41116 (1115) <br /> 41117 (1116) <br /> 41118 (1117) | Input        | Float64  | Category Car Money Out       | Money            |             |
| 41119 (1118) <br /> 41120 (1119)                                         | Input        | Float32  | Category Relais Current L1   | A (Ampere)       |             |
| 41121 (1120) <br /> 41122 (1121)                                         | Input        | Float32  | Category Relais Current L2   | A (Ampere)       |             |
| 41123 (1122) <br /> 41124 (1123)                                         | Input        | Float32  | Category Relais Current L3   | A (Ampere)       |             |
| 41125 (1124) <br /> 41126 (1125)                                         | Input        | Float32  | Category Relais Power        | W (Watt)         |             |
| 41127 (1126) <br /> 41128 (1127) <br /> 41129 (1128) <br /> 41130 (1129) | Input        | Float64  | Category Relais Energy In    | Wh (Watt-Hours)  |             |
| 41131 (1130) <br /> 41132 (1131) <br /> 41133 (1132) <br /> 41134 (1133) | Input        | Float64  | Category Relais Energy Out   | Wh (Watt-Hours)  |             |
| 41135 (1134) <br /> 41136 (1135) <br /> 41137 (1136) <br /> 41138 (1137) | Input        | Float64  | Category Relais Money In     | Money            |             |
| 41139 (1138) <br /> 41140 (1139) <br /> 41141 (1140) <br /> 41142 (1141) | Input        | Float64  | Category Relais Money Out    | Money            |             |
| 41143 (1142) <br /> 41144 (1143)                                         | Input        | Float32  | Category Solar Current L1    | A (Ampere)       |             |
| 41145 (1144) <br /> 41146 (1145)                                         | Input        | Float32  | Category Solar Current L2    | A (Ampere)       |             |
| 41147 (1146) <br /> 41148 (1147)                                         | Input        | Float32  | Category Solar Current L3    | A (Ampere)       |             |
| 41149 (1148) <br /> 41150 (1149)                                         | Input        | Float32  | Category Solar Power         | W (Watt)         |             |
| 41151 (1150) <br /> 41152 (1151) <br /> 41153 (1152) <br /> 41154 (1153) | Input        | Float64  | Category Solar Energy In     | Wh (Watt-Hours)  |             |
| 41155 (1154) <br /> 41156 (1155) <br /> 41157 (1156) <br /> 41158 (1157) | Input        | Float64  | Category Solar Energy Out    | Wh (Watt-Hours)  |             |
| 41159 (1158) <br /> 41160 (1159) <br /> 41161 (1160) <br /> 41162 (1161) | Input        | Float64  | Category Solar Money In      | Money            |             |
| 41163 (1162) <br /> 41164 (1163) <br /> 41165 (1164) <br /> 41166 (1165) | Input        | Float64  | Category Solar Money Out     | Money            |             |
| 41167 (1166) <br /> 41168 (1167)                                         | Input        | Float32  | Category Akku Current L1     | A (Ampere)       |             |
| 41169 (1168) <br /> 41170 (1169)                                         | Input        | Float32  | Category Akku Current L2     | A (Ampere)       |             |
| 41171 (1170) <br /> 41172 (1171)                                         | Input        | Float32  | Category Akku Current L3     | A (Ampere)       |             |
| 41173 (1172) <br /> 41174 (1173)                                         | Input        | Float32  | Category Akku Power          | W (Watt)         |             |
| 41175 (1174) <br /> 41176 (1175) <br /> 41177 (1176) <br /> 41178 (1177) | Input        | Float64  | Category Akku Energy In      | Wh (Watt-Hours)  |             |
| 41179 (1178) <br /> 41180 (1179) <br /> 41181 (1180) <br /> 41182 (1181) | Input        | Float64  | Category Akku Energy Out     | Wh (Watt-Hours)  |             |
| 41183 (1182) <br /> 41184 (1183) <br /> 41185 (1184) <br /> 41186 (1185) | Input        | Float64  | Category Akku Money In       | Money            |             |
| 41187 (1186) <br /> 41188 (1187) <br /> 41189 (1188) <br /> 41190 (1189) | Input        | Float64  | Category Akku Money Out      | Money            |             |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |              |          |                              |                  |             |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |              |          |                              |                  |             |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |              |          |                              |                  |             |
| <!-- MODBUS-SKIP-ADDR: 24 -->                                            |              |          |                              |                  |             |
| 41287 (1286) <br /> 41288 (1287)                                         | Input        | Float32  | Custom Category 0 Current L1 | A (Ampere)       |             |
| 41289 (1288) <br /> 41290 (1289)                                         | Input        | Float32  | Custom Category 0 Current L2 | A (Ampere)       |             |
| 41291 (1290) <br /> 41292 (1291)                                         | Input        | Float32  | Custom Category 0 Current L3 | A (Ampere)       |             |
| 41293 (1292) <br /> 41294 (1293)                                         | Input        | Float32  | Custom Category 0 Power      | W (Watt)         |             |
| 41295 (1294) <br /> 41296 (1295) <br /> 41297 (1296) <br /> 41298 (1297) | Input        | Float64  | Custom Category 0 Energy In  | Wh (Watt-Hours)  |             |
| 41299 (1298) <br /> 41300 (1299) <br /> 41301 (1300) <br /> 41302 (1301) | Input        | Float64  | Custom Category 0 Energy Out | Wh (Watt-Hours)  |             |
| 41303 (1302) <br /> 41304 (1303) <br /> 41305 (1304) <br /> 41306 (1305) | Input        | Float64  | Custom Category 0 Money In   | Money            |             |
| 41307 (1306) <br /> 41308 (1307) <br /> 41309 (1308) <br /> 41310 (1309) | Input        | Float64  | Custom Category 0 Money Out  | Money            |             |
| 41311 (1310) <br /> 41312 (1311)                                         | Input        | Float32  | Custom Category 1 Current L1 | A (Ampere)       |             |
| 41313 (1312) <br /> 41314 (1313)                                         | Input        | Float32  | Custom Category 1 Current L2 | A (Ampere)       |             |
| 41315 (1314) <br /> 41316 (1315)                                         | Input        | Float32  | Custom Category 1 Current L3 | A (Ampere)       |             |
| 41317 (1316) <br /> 41318 (1317)                                         | Input        | Float32  | Custom Category 1 Power      | W (Watt)         |             |
| 41319 (1318) <br /> 41320 (1319) <br /> 41321 (1320) <br /> 41322 (1321) | Input        | Float64  | Custom Category 1 Energy In  | Wh (Watt-Hours)  |             |
| 41323 (1322) <br /> 41324 (1323) <br /> 41325 (1324) <br /> 41326 (1325) | Input        | Float64  | Custom Category 1 Energy Out | Wh (Watt-Hours)  |             |
| 41327 (1326) <br /> 41328 (1327) <br /> 41329 (1328) <br /> 41330 (1329) | Input        | Float64  | Custom Category 1 Money In   | Money            |             |
| 41331 (1330) <br /> 41332 (1331) <br /> 41333 (1332) <br /> 41334 (1333) | Input        | Float64  | Custom Category 1 Money Out  | Money            |             |
| 41335 (1334) <br /> 41336 (1335)                                         | Input        | Float32  | Custom Category 2 Current L1 | A (Ampere)       |             |
| 41337 (1336) <br /> 41338 (1337)                                         | Input        | Float32  | Custom Category 2 Current L2 | A (Ampere)       |             |
| 41339 (1338) <br /> 41340 (1339)                                         | Input        | Float32  | Custom Category 2 Current L3 | A (Ampere)       |             |
| 41341 (1340) <br /> 41342 (1341)                                         | Input        | Float32  | Custom Category 2 Power      | W (Watt)         |             |
| 41343 (1342) <br /> 41344 (1343) <br /> 41345 (1344) <br /> 41346 (1345) | Input        | Float64  | Custom Category 2 Energy In  | Wh (Watt-Hours)  |             |
| 41347 (1346) <br /> 41348 (1347) <br /> 41349 (1348) <br /> 41350 (1349) | Input        | Float64  | Custom Category 2 Energy Out | Wh (Watt-Hours)  |             |
| 41351 (1350) <br /> 41352 (1351) <br /> 41353 (1352) <br /> 41354 (1353) | Input        | Float64  | Custom Category 2 Money In   | Money            |             |
| 41355 (1354) <br /> 41356 (1355) <br /> 41357 (1356) <br /> 41358 (1357) | Input        | Float64  | Custom Category 2 Money Out  | Money            |             |
| 41359 (1358) <br /> 41360 (1359)                                         | Input        | Float32  | Custom Category 3 Current L1 | A (Ampere)       |             |
| 41361 (1360) <br /> 41362 (1361)                                         | Input        | Float32  | Custom Category 3 Current L2 | A (Ampere)       |             |
| 41363 (1362) <br /> 41364 (1363)                                         | Input        | Float32  | Custom Category 3 Current L3 | A (Ampere)       |             |
| 41365 (1364) <br /> 41366 (1365)                                         | Input        | Float32  | Custom Category 3 Power      | W (Watt)         |             |
| 41367 (1366) <br /> 41368 (1367) <br /> 41369 (1368) <br /> 41370 (1369) | Input        | Float64  | Custom Category 3 Energy In  | Wh (Watt-Hours)  |             |
| 41371 (1370) <br /> 41372 (1371) <br /> 41373 (1372) <br /> 41374 (1373) | Input        | Float64  | Custom Category 3 Energy Out | Wh (Watt-Hours)  |             |
| 41375 (1374) <br /> 41376 (1375) <br /> 41377 (1376) <br /> 41378 (1377) | Input        | Float64  | Custom Category 3 Money In   | Money            |             |
| 41379 (1378) <br /> 41380 (1379) <br /> 41381 (1380) <br /> 41382 (1381) | Input        | Float64  | Custom Category 3 Money Out  | Money            |             |
| 41383 (1382) <br /> 41384 (1383)                                         | Input        | Float32  | Custom Category 4 Current L1 | A (Ampere)       |             |
| 41385 (1384) <br /> 41386 (1385)                                         | Input        | Float32  | Custom Category 4 Current L2 | A (Ampere)       |             |
| 41387 (1386) <br /> 41388 (1387)                                         | Input        | Float32  | Custom Category 4 Current L3 | A (Ampere)       |             |
| 41389 (1388) <br /> 41390 (1389)                                         | Input        | Float32  | Custom Category 4 Power      | W (Watt)         |             |
| 41391 (1390) <br /> 41392 (1391) <br /> 41393 (1392) <br /> 41394 (1393) | Input        | Float64  | Custom Category 4 Energy In  | Wh (Watt-Hours)  |             |
| 41395 (1394) <br /> 41396 (1395) <br /> 41397 (1396) <br /> 41398 (1397) | Input        | Float64  | Custom Category 4 Energy Out | Wh (Watt-Hours)  |             |
| 41399 (1398) <br /> 41400 (1399) <br /> 41401 (1400) <br /> 41402 (1401) | Input        | Float64  | Custom Category 4 Money In   | Money            |             |
| 41403 (1402) <br /> 41404 (1403) <br /> 41405 (1404) <br /> 41406 (1405) | Input        | Float64  | Custom Category 4 Money Out  | Money            |             |
| 41407 (1406) <br /> 41408 (1407)                                         | Input        | Float32  | Custom Category 5 Current L1 | A (Ampere)       |             |
| 41409 (1408) <br /> 41410 (1409)                                         | Input        | Float32  | Custom Category 5 Current L2 | A (Ampere)       |             |
| 41411 (1410) <br /> 41412 (1411)                                         | Input        | Float32  | Custom Category 5 Current L3 | A (Ampere)       |             |
| 41413 (1412) <br /> 41414 (1413)                                         | Input        | Float32  | Custom Category 5 Power      | W (Watt)         |             |
| 41415 (1414) <br /> 41416 (1415) <br /> 41417 (1416) <br /> 41418 (1417) | Input        | Float64  | Custom Category 5 Energy In  | Wh (Watt-Hours)  |             |
| 41419 (1418) <br /> 41420 (1419) <br /> 41421 (1420) <br /> 41422 (1421) | Input        | Float64  | Custom Category 5 Energy Out | Wh (Watt-Hours)  |             |
| 41423 (1422) <br /> 41424 (1423) <br /> 41425 (1424) <br /> 41426 (1425) | Input        | Float64  | Custom Category 5 Money In   | Money            |             |
| 41427 (1426) <br /> 41428 (1427) <br /> 41429 (1428) <br /> 41430 (1429) | Input        | Float64  | Custom Category 5 Money Out  | Money            |             |
| 41431 (1430) <br /> 41432 (1431)                                         | Input        | Float32  | Custom Category 6 Current L1 | A (Ampere)       |             |
| 41433 (1432) <br /> 41434 (1433)                                         | Input        | Float32  | Custom Category 6 Current L2 | A (Ampere)       |             |
| 41435 (1434) <br /> 41436 (1435)                                         | Input        | Float32  | Custom Category 6 Current L3 | A (Ampere)       |             |
| 41437 (1436) <br /> 41438 (1437)                                         | Input        | Float32  | Custom Category 6 Power      | W (Watt)         |             |
| 41439 (1438) <br /> 41440 (1439) <br /> 41441 (1440) <br /> 41442 (1441) | Input        | Float64  | Custom Category 6 Energy In  | Wh (Watt-Hours)  |             |
| 41443 (1442) <br /> 41444 (1443) <br /> 41445 (1444) <br /> 41446 (1445) | Input        | Float64  | Custom Category 6 Energy Out | Wh (Watt-Hours)  |             |
| 41447 (1446) <br /> 41448 (1447) <br /> 41449 (1448) <br /> 41450 (1449) | Input        | Float64  | Custom Category 6 Money In   | Money            |             |
| 41451 (1450) <br /> 41452 (1451) <br /> 41453 (1452) <br /> 41454 (1453) | Input        | Float64  | Custom Category 6 Money Out  | Money            |             |
| 41455 (1454) <br /> 41456 (1455)                                         | Input        | Float32  | Custom Category 7 Current L1 | A (Ampere)       |             |
| 41457 (1456) <br /> 41458 (1457)                                         | Input        | Float32  | Custom Category 7 Current L2 | A (Ampere)       |             |
| 41459 (1458) <br /> 41460 (1459)                                         | Input        | Float32  | Custom Category 7 Current L3 | A (Ampere)       |             |
| 41461 (1460) <br /> 41462 (1461)                                         | Input        | Float32  | Custom Category 7 Power      | W (Watt)         |             |
| 41463 (1462) <br /> 41464 (1463) <br /> 41465 (1464) <br /> 41466 (1465) | Input        | Float64  | Custom Category 7 Energy In  | Wh (Watt-Hours)  |             |
| 41467 (1466) <br /> 41468 (1467) <br /> 41469 (1468) <br /> 41470 (1469) | Input        | Float64  | Custom Category 7 Energy Out | Wh (Watt-Hours)  |             |
| 41471 (1470) <br /> 41472 (1471) <br /> 41473 (1472) <br /> 41474 (1473) | Input        | Float64  | Custom Category 7 Money In   | Money            |             |
| 41475 (1474) <br /> 41476 (1475) <br /> 41477 (1476) <br /> 41478 (1477) | Input        | Float64  | Custom Category 7 Money Out  | Money            |             |
| 41479 (1478) <br /> 41480 (1479)                                         | Input        | Float32  | Custom Category 8 Current L1 | A (Ampere)       |             |
| 41481 (1480) <br /> 41482 (1481)                                         | Input        | Float32  | Custom Category 8 Current L2 | A (Ampere)       |             |
| 41483 (1482) <br /> 41484 (1483)                                         | Input        | Float32  | Custom Category 8 Current L3 | A (Ampere)       |             |
| 41485 (1484) <br /> 41486 (1485)                                         | Input        | Float32  | Custom Category 8 Power      | W (Watt)         |             |
| 41487 (1486) <br /> 41488 (1487) <br /> 41489 (1488) <br /> 41490 (1489) | Input        | Float64  | Custom Category 8 Energy In  | Wh (Watt-Hours)  |             |
| 41491 (1490) <br /> 41492 (1491) <br /> 41493 (1492) <br /> 41494 (1493) | Input        | Float64  | Custom Category 8 Energy Out | Wh (Watt-Hours)  |             |
| 41495 (1494) <br /> 41496 (1495) <br /> 41497 (1496) <br /> 41498 (1497) | Input        | Float64  | Custom Category 8 Money In   | Money            |             |
| 41499 (1498) <br /> 41500 (1499) <br /> 41501 (1500) <br /> 41502 (1501) | Input        | Float64  | Custom Category 8 Money Out  | Money            |             |
| 41503 (1502) <br /> 41504 (1503)                                         | Input        | Float32  | Custom Category 9 Current L1 | A (Ampere)       |             |
| 41505 (1504) <br /> 41506 (1505)                                         | Input        | Float32  | Custom Category 9 Current L2 | A (Ampere)       |             |
| 41507 (1506) <br /> 41508 (1507)                                         | Input        | Float32  | Custom Category 9 Current L3 | A (Ampere)       |             |
| 41509 (1508) <br /> 41510 (1509)                                         | Input        | Float32  | Custom Category 9 Power      | W (Watt)         |             |
| 41511 (1510) <br /> 41512 (1511) <br /> 41513 (1512) <br /> 41514 (1513) | Input        | Float64  | Custom Category 9 Energy In  | Wh (Watt-Hours)  |             |
| 41515 (1514) <br /> 41516 (1515) <br /> 41517 (1516) <br /> 41518 (1517) | Input        | Float64  | Custom Category 9 Energy Out | Wh (Watt-Hours)  |             |
| 41519 (1518) <br /> 41520 (1519) <br /> 41521 (1520) <br /> 41522 (1521) | Input        | Float64  | Custom Category 9 Money In   | Money            |             |
| 41523 (1522) <br /> 41524 (1523) <br /> 41525 (1524) <br /> 41526 (1525) | Input        | Float64  | Custom Category 9 Money Out  | Money            |             |
<!-- MODBUS TABLE END -->
